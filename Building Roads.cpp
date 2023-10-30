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

	vector<int>parent(n+1);
	iota(parent.begin(), parent.end(),0);
	vector<int>rank(n+1,0);

	vector<vector<int>>roads;

	for(int i = 0 ;i<m; i++){
		int s,e;
		cin>>s>>e;
		unionthem(s,e,parent,rank);
	}

	unordered_set<int>us;
	
	for(int i = 1; i<=n; i++){
		us.insert(findparent(i,parent));
	}

	vector<int>ansarr(us.begin(), us.end());

	if(us.size()>1){
		cout<<us.size()-1<<endl;
		for(int i = 1; i<ansarr.size(); i++){
			cout<<ansarr[i-1]<<" "<<ansarr[i]<<endl;
		}
	}

	else{
		cout<<0<<endl;
	}
}

int main(){
	init_code();
	// int t;
	// cin>>t;

	// for(int i = 1; i<=t; i++){
		func();
	// }
}