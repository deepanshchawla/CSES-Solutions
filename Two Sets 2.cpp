#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int mod = 1000000007;

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
	// cout<<n<<endl;
	int totsum = (n*(n+1))/2;

	if(totsum%2 == 1){
		cout<<0<<endl;
	}

	else{
		int halfsum = totsum/2;

		vector<vector<int>>dp(n+2,vector<int>(halfsum+1,0));
		dp[n+1][0] = 1;

		for(int i = n; i>=1; i--){
			for(int j = 0; j<=halfsum; j++){
				int take = 0, nottake = 0;
				if(j>=i){
					take = dp[i+1][j-i]%mod;
				}
				nottake = dp[i+1][j]%mod;

				dp[i][j] = take + nottake;
				// cout<<dp[i][j]<<endl;

			}
		}
		// int ans = (helper(1,n,halfsum,dp)%mod);
		int ans = dp[1][halfsum]%mod;
		cout<<(ans)/2<<endl;
	}
}

int main(){
	init_code();
	func();	
}