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

int findparent(int i, vector<int>&parent){
    if(parent[i]==i)return i;
    return parent[i] = findparent(parent[i],parent);
}

void unionthem(int i, int j, vector<int>&parent, vector<int>&rankarr){
    i = findparent(i,parent);
    j = findparent(j, parent);
    if(rankarr[i]>rankarr[j]){
        parent[j] = i;
        rankarr[i]++;
    }

    else{
        parent[i] = j;
        rankarr[j]++;
    }
}

void func(){
	int n,m;
	cin>>n>>m;

	// vector<vector<int>>roads;
	unordered_map<int,vector<int>>mp;

	for(int i = 0 ;i<m; i++){
		int s,e;
		cin>>s>>e;
		// roads.push_back({s,e});
		mp[s].push_back(e);
		mp[e].push_back(s);
	}

	queue<pair<int,vector<int>>>qu;
	qu.push({1,{1}});
	vector<int>vis(n+1,0);
	vis[1] = 1;
	while(qu.empty()==false){
		int size = qu.size();
		for(int i = 0; i<size; i++){
			int currnode = qu.front().first;
			vector<int>currpath = qu.front().second;
			
		}
	}
}

int main(){
	init_code();
	func();	
}