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

int func2(int l, int r, vector<int>&vec){
	auto itl = lower_bound(vec.begin(), vec.end(),l);
	auto itr = upper_bound(vec.begin(), vec.end(),r);
	return itr-itl;
}

int findparent(int i, vector<int>&parent){
    if(parent[i]==i)return i;
    return parent[i] = findparent(parent[i],parent);
}

void unionthem(int i, int j, vector<int>&parent, vector<int>&rank){
    i = findparent(i,parent);
    j = findparent(j, parent);
    if(rank[i]>rank[j]){
        parent[j] = i;
        rank[i]++;
    }

    else{
        parent[i] = j;
        rank[j]++;
    }
}


void func(){
	int n,c;
	cin>>n>>c;


}	

int main(){
	// init_code();
	fast_io;
	int tc;
	cin>>tc;

	for(int i = 0; i<tc; i++){
		func();
	}
}