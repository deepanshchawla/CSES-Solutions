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

int func(){
	int x1,y1,x2,y2,b11,b12, b21, b22, m;
	cin>>x1>>y1>>x2>>y2>>b11>>b12>>b21>>b22>>m;

	vector<vector<int>>vec(10, vector<int>(10,0));

	for(int i = 0; i<m; i++){
		int a, b;
		cin>>a>>b;
		vec[a][b] = -1;
	}

	queue<pair<int,int>>qu;
	if(vec[x1][y1]==0){
		qu.push({x1,y1});
		vec[x1][y1] = 1;
	}

	int ans = 0;

	while(qu.empty()==false){
		int size = qu.size();

		for(int i = 0; i<size; i++){
			int ci = qu.front().first;
			int cj = qu.front().second;
			qu.pop();

			if(ci == x2 and cj == y2){
				return ans;
			}

			for(int d = 0; d<4; d++){
				int ni = ci+dx[d];
				int nj = cj+dy[d];
				if(ni<0 or ni>=10 or nj>=10 or nj<0)continue;

				if(vec[ni][nj]==0){
					vec[ni][nj] = 1;

					if((ni == b11 and nj == b12) or (ni == b21 and nj == b22)){
						if(ni == b11 and nj == b12){
							ni = b21;
							nj = b22;

						}

						else{
							ni = b11;
							nj = b12;
						}

						vec[ni][nj] = 1;
					}

					// else{
						qu.push({ni,nj});
					// }
				}
			}
		}

		ans++;
	}

	return -1;
}	

int main(){
	fast_io;
	// init_code();
	int tc;
	cin>>tc;

	for(int i = 0; i<tc; i++){
		cout<<func()<<endl;
	}
}