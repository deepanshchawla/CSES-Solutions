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

	vector<vector<int>>board(n, vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>board[i][j];
		}
	}

	int q;
	cin>>q;

	unordered_map<int,int>mappings;
	mappings[0] = 0;
	mappings[-1] = 1;
	mappings[1] = 2;
	mappings[2] = 3;
	mappings[-2] = 4;
	mappings[3] = 5;
	mappings[-3] = 6;

	unordered_map<int,vector<pair<int,int>>>mp;
	for(int i = 0; i<n-2; i++){
		for(int j = 0; j<n-2; j++){
			// int currno = 0;
			int currno = 0;
			for(int k = i; k<i+2; k++){
				for(int l = j; l<j+2; l++){
					currno*=10;
					currno+=(mappings[board[k][l]]);
				}
			}

			mp[currno].push_back({i,j});
		}
	}

	for(int i = 0; i<q; i++){
		vector<vector<int>>query(7, vector<int>(7));
		// int query[7][7];
		for(int j = 0; j<7; j++){
			for(int k = 0; k<7; k++){
				cin>>query[j][k];
			}
		}

		int currno = 0;
		for(int k = 0; k<2; k++){
			for(int l = 6; l>4; l--){
				currno*=10;
				currno+=(mappings[-query[k][l]]);
			}
		}
		// cout<<currno<<endl;
		for(auto x: mp[currno]){
			if(x.first+6>=n or x.second+6>=n)continue;
			// cout<<"here"<<endl;
			int qi = 0;
			bool flag = true;
			for(int str = x.first; str<x.first+7; str++){
				int qj = 6;
				for(int stc = x.second; stc<x.second+7; stc++){
					if(board[str][stc]+query[qi][qj]!=0){
						flag= false;
						break;
					}
					qj--;
				}
				if(flag == false){
					break;
				}
				qi++;
			}

			if(flag){
				cout<<x.first<<" "<<x.second<<"\n";
				break;
			}
		}

		// if(mp.count(currno)){
		// 	cout<<"no entries"<<endl;
		// }
	}
}	

int main(){
	fast_io;
	init_code();

	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		func();
	}
}