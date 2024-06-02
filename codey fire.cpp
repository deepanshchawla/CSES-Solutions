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

//up down left right
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};


void func(){
	int n;
	cin>>n;
	queue<pair<int,int>>qu;
	vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

	vector<vector<char>>vec(n,vector<char>(n,0));
	for(int i = 0; i<n ;i++){
		for(int j = 0; j<n; j++){
			cin>>vec[i][j];
			if(vec[i][j] == '1'){
				qu.push({i,j});
				dis[i][j] = 0;
				// cout<<i<<" "<<j<<endl;
			}
		}
	}



	int ans = 0;
	while(qu.empty()==false){
		int size= qu.size();
		// ans++;
		for(int s = 0; s<size; s++){
			int i = qu.front().first;
			int j = qu.front().second;
			qu.pop();
			for(int d = 0; d<4; d++){
				int newi = i+dx[d];
				int newj = j+dy[d];

				if(newi>=0 and newi<n and newj>=0 and newj<n and dis[newi][newj]>ans+1){
					dis[newi][newj] = ans;
					qu.push({newi,newj});
				}
			}
		}
		if(qu.size()){
			ans++;
		}
	}

	cout<<ans<<endl;
}	

int main(){
	fast_io;
	// init_code();

	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		func();
		// cout<<endl;
	}
}