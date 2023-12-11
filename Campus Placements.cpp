#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
long long mod = 1000000007;

// void init_code(){
// 	fast_io;

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// }

void func(){
	int n;
	cin>>n;

	vector<pair<long long,long long>>vp;
	for(int i = 1; i<=n; i++){
		long long ele;
		cin>>ele;
		vp.push_back({ele, i});
	}

	long long ans = LLONG_MIN;

	sort(vp.begin(), vp.end());
	long long minirank = vp.back().second, maxirank = vp.back().second;

	for(int i = n-2; i>=0; i--){
		ans = max(ans, vp[i].first * max(abs(vp[i].second-minirank), abs(vp[i].second-maxirank)));
		minirank = min(minirank, vp[i].second);
		maxirank = max(maxirank, vp[i].second);
	}

	cout<<ans<<endl;
}	

int main(){
	fast_io;
	// init_code();
	int tc;
	cin>>tc;

	for(int i = 0; i<tc; i++){
		func();
	}
}