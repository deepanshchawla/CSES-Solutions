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

pair<long long> buildtree(long long it, long long left, long long right, vector<long long>&vec, vector<long long>&segtree){
	if(left == right){
		segtree[it] = vec[left];
		return segtree[it];
	}

	long long mid = (left + right)/2;
	long long leftside = buildtree(2*it + 1, left, mid, vec, segtree);
	long long rightside = buildtree(2*it+2, mid+1, right, vec, segtree);
	segtree[it] = max(leftside,leftside+rightside);

	return segtree[it];
}

long long updatetree(long long k, long long u, long long left, long long right,long long it, vector<long long>&segtree){
	if(left>k or right<k){
		return segtree[it];
	}

	if(left == right){
		if(left == k){
			segtree[it] = u;
		}

		return segtree[it];
	}

	long long mid = (left + right)/2;
	long long leftside = updatetree(k,u,left,mid,2*it+1,segtree);
	long long rightside = updatetree(k,u,mid+1,right,2*it+2,segtree);
	segtree[it] = max(leftside,leftside+rightside);
	return segtree[it];
}

long long query(long long i, long long j, long long left, long long right, long long it, vector<long long>&segtree){
	if(i<=left and j>=right){
		return segtree[it];
	}

	if(left>j or right<i){
		return LLONG_MIN;
	}

	long long mid = (left + right)/2;
	long long leftside = query(i,j,left,mid,2*it+1, segtree);
	long long rightside = query(i,j,mid+1,right,2*it+2, segtree);
	return max(leftside,leftside+rightside);
}

void func(){
	long long n,q;
	cin>>n>>q;

	vector<long long>vec(n);
	vector<long long>segtree(4*n + 5);
	for(long long i = 0; i<n; i++){
		cin>>vec[i];
	}

	buildtree(0,0,n-1,vec,segtree);
	for(auto x: segtree){
		cout<<x<<" ";
	}
	for(int i = 0; i<q; i++){
		long long a;
		cin>>a;
		if(a == 1){
			long long k,u;
			cin>>k>>u;
			updatetree(k-1,u,0,n-1,0,segtree);
		}

		else{
			long long a,b;
			cin>>a>>b;
			cout<<query(a-1,b-1,0,n-1,0,segtree)<<endl;
		}
	}
}

int main(){
	init_code();
	func();	
}