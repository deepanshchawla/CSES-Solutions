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

int ele;
bool in = false;
vector<int>ans;

bool chk(int node, vector<int>&vis, vector<int>&dfsvis, unordered_map<int,vector<int>>&mp){
	vis[node] = 1;
	dfsvis[node] = 1;

	for(auto x: mp[node]){
		if(vis[x]==0){
			if(chk(x,vis,dfsvis,mp)){
				// if(in == false){
				dfsvis[node] = 0;
				// }

				if(in == true){
					ans.push_back(node);
				}

				if(node == ele){
					in = false;
				}

				return true;
			}
		}


		else{
			if(dfsvis[x]){
				ele = x;
				in = true;
				dfsvis[node] = 0;
				ans.push_back(node);
				return true;
			}
		}
	}

	dfsvis[node] = 0;
	return false;
}


void func(){
	unordered_map<int,vector<int>>mp;
	int edges;
	cin>>edges;
	for(int i = 0; i<edges; i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
	}

	vector<int>vis(2001,0);
	vector<int>dfsvis(2001,0);

	bool flag = true;
	for(int i = 1; i<=2000; i++){
		if(vis[i]==0){
			if(chk(i,vis,dfsvis,mp)){
				flag = false;
				break;
			}
		}
	}

	if(flag){
		cout<<0<<endl;
	}

	else{
		sort(ans.begin(), ans.end());
		for(auto x: ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

int main(){
	init_code();
	int tc;
	cin>>tc;

	while(tc--){
		func();		
		// cout<<endl;
	}
}