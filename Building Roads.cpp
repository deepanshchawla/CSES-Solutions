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

/*
The question is quite simple we just need to find out the minimum number of roads needed to make all the cities connected.
If it was not the case minimum the quuestion could have been done in one line as we would have connected each node to the every other node.

but now in this case as we have to find the minimum number of nodes to make the cities connected so, in this solution we make the components of the connected cities. 
1. the already connected cities will have a parent node
2. now total_components-1 is the number of nodes which we must build to make all the cities connected.
3. and the number of nodes we can have by connecting the parent of each successive parent node with its prev passing parent (as we have stored all the parent nodes in a vector/arr) 
4. like if there are 4 6 8 are the parent nodes of the already connected components cities then the roads required are 4-6, 6-8 i.e 2.
*/

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
