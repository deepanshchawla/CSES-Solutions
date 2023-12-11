#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int chk(int node, unordered_map<int,vector<int>>&mp, vector<int>&vis){
	int currans = 0;

	currans++;
	vis[node] = 1;

	for(int x: mp[node]){
		if(vis[x]==0){
			currans+=chk(x,mp, vis);
		}
	}

	return currans;
}

void func(int n, unordered_map<int,vector<int>>&mp, vector<int>&indegree){
	for(int i = 1; i<=n; i++){
		vector<int>vis(n+1,0);
		indegree[i]+=chk(i,mp,vis);
	}
}

int main() {
	init_code();
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
    	// cout<<i<<endl;
        int N, M;
        cin >> N >> M;

        unordered_map<int,vector<int>>mp;
        unordered_map<int,vector<int>>rev_map;
        vector<int>outdegree(N+1,0);
        vector<int>indegree(N+1,0);

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            rev_map[b].push_back(a);
        }
        // cout<<i<<endl;
        int rank_known_count = 0;
        // cout<<i<<endl;
        func(N,mp,outdegree);
        func(N,rev_map,indegree);
        // cout<<i<<endl;
        for (int i = 1; i <= N; i++) {
        	// cout<<outdegree[i]<<" "<<indegree[i]<<endl;
            if(outdegree[i]+indegree[i]==N+1){
            	rank_known_count++;
            }
        }

        cout << "#" << i << " " << rank_known_count << endl;
    }

    return 0;
}
