#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

long long helper(int i, int j, vector<long long>&nums, vector<vector<long long>>&dp){
	if(i>j){
		return 0;
	}

	if(dp[i][j]!=-1)return dp[i][j];

	return dp[i][j] = max(nums[i]+min(helper(i+2,j,nums,dp), helper(i+1,j-1,nums,dp)), nums[j]+min(helper(i+1,j-1,nums,dp), helper(i,j-2,nums,dp)));
}

void func(){
	int n;
	cin>>n;

	vector<long long>nums(n);
	for(long long & i: nums){
		cin>>i;
	}
	vector<vector<long long>>dp(n, vector<long long>(n,-1));

	long long ans = helper(0,n-1,nums,dp);

	cout<<ans<<endl;
}

int main(){
	init_code();
	func();	
}