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


void func(){
	int n,x;
	cin>>n>>x;
	vector<int>price(n),pages(n);

    for(int i = 0; i<n; i++){
    	cin>>price[i];
    }

    for(int i = 0; i<n; i++){
    	cin>>pages[i];
    }

	int dp[n+1][x+1];
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=x; j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=x; j++){
			int take = 0, nottake = 0;
			if(price[i-1]<=j){
				take = pages[i-1]+dp[i-1][j-price[i-1]];
			}

			nottake = dp[i-1][j];

			dp[i][j] = max(take,nottake);
		}
	}

	cout<<dp[n][x]<<endl;
}

int main(){
	init_code();
	func();	
}

