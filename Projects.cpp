#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
long long mod = 1000000007;

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}


long long helper(int it, vector<pair<pair<int,int>,int>>&vec, vector<vector<long long>>&dp, int prev){
	if(it == vec.size())return 0;

	bool decide = (prev<vec[it].first.first);

	if(dp[it][decide]!=-1)return dp[it][decide];

	long long take = 0;
	long long nottake = 0;
	
	if(decide){
		take = vec[it].second+helper(it+1,vec,dp,vec[it].first.second);
	}

	nottake = helper(it+1,vec, dp, prev);

	return dp[it][decide] = max(take,nottake);
}

void func(){
	long long n;
	cin>>n;

	vector<pair<pair<int,int>,int>>vec;

	for(long long i = 0; i<n; i++){
		int s,e,p;
		cin>>s>>e>>p;

		vec.push_back({{s,e},p});
	}

	sort(vec.begin(), vec.end(), [&](pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
		return a.first.first<b.first.first;
	});

	vector<vector<long long>>dp(vec.size(), vector<long long>(2,-1));

	long long ans = helper(0,vec,dp, 0);

	cout<<ans<<endl;
}	

int main(){
	fast_io;
	init_code();

	func();
}