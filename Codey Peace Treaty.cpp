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

//up down left right dru drd dlu dld
    int dx[9] = {-1, +1, 0, 0, -1,1, -1,1,0};
    int dy[9] = {0, 0, -1, +1, 1, 1, -1, -1,0};	

bool chk(pair<int,int>a, pair<int,int>b){

	for(int i = 0; i<9; i++){
		int newx = a.first+dx[i];
		int newy = a.second + dy[i];
		if(newx>=0 and newx<25 and newy>=0 and newy<25 and (newx==b.first and newy==b.second)){
			return false;
		}
	}

	return true;
}


int func(){
	int n,m;
	cin>>n>>m;
	pair<int,int>t1,t2;
	queue<pair<pair<int,int>,pair<int,int>>>qu;
	vector<vector<vector<vector<int>>>>vis(25, vector<vector<vector<int>>>(25, vector<vector<int>>(25, vector<int>(25,0))));
	vector<vector<int>>vec(n,vector<int>(m,0));

	for(int i = 0;i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>vec[i][j];
			if(vec[i][j]==2){
				t1 = {i,j};
			}

			else if(vec[i][j]==3){
				t2 = {i,j};
			}
		}
	}

	if(chk(t1,t2)){
		qu.push({t1,t2});
		vis[t1.first][t1.second][t2.first][t2.second] = 1;
	}

	int ans = 0;

	while(qu.empty()==false){
		int size = qu.size();

		for(int i = 0;i<size; i++){
			pair<int,int>a = qu.front().first;
			pair<int,int>b = qu.front().second;
			qu.pop();

			if(vec[a.first][a.second]==4 and vec[b.first][b.second]==5)return ans;

			for(int j = 0; j<9; j++){
				for(int k = 0; k<9; k++){
					int newaf = a.first+dx[j];
					int newas = a.second+dy[j];
					int newbf = b.first+dx[k];
					int newbs = b.second+dy[k];
					// cout<<newaf<<" "<<newas<<" "<<newbf<<" "<<newbs<<endl;
					if(newaf<0 or newaf>=25 or newbf<0 or newbf>=25 or newas<0 or newas>=25 or newbs<0 or newbs>=25 or vis[newaf][newas][newbf][newbs]==1 or vec[newaf][newas]==1 or vec[newbf][newbs]==1 or chk({newaf, newas},{newbf, newbs})==false)continue;

					vis[newaf][newas][newbf][newbs]=1;
					qu.push({{newaf, newas}, {newbf, newbs}});
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