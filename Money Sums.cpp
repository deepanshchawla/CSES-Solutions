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


void func(){
	int n;
	cin>>n;
	vector<int>vec(n);
	for(int & x: vec){
		cin>>x;
	}

	vector<vector<int>>ans(n+1, vector<int>(100001, false));
	ans[0][0] = true;
	for(int i = 1; i<=n; i++){
		ans[i][0] = true;
		for(int j = 1; j<ans[i].size(); j++){
			ans[i][j] = ans[i-1][j];

			if(j>=vec[i-1]){
				ans[i][j] = max(ans[i][j], ans[i-1][j-vec[i-1]]);
			}
		}
	}

	int nos = 0;
	vector<int>no_nos;
	for(int i = 1; i<=100000; i++){
		if(ans[n][i]){
			nos++;
			no_nos.push_back(i);
		}
	}

	cout<<nos<<endl;
	for(auto x: no_nos){
		cout<<x<<" ";
	}
	cout<<endl;
}	

int main(){
	init_code();
	func();	
}

