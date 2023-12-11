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

long long buildtree(long long it, long long left, long long right, vector<long long>&vec, vector<long long>&segtree){
	if(left == right){
		segtree[it] = vec[left];
		return segtree[it];
	}

	long long mid = (left + right)/2;
	long long leftside = buildtree(2*it + 1, left, mid, vec, segtree);
	long long rightside = buildtree(2*it+2, mid+1, right, vec, segtree);
	segtree[it] = max(leftside,rightside);

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
	segtree[it] = max(leftside,rightside);
	return segtree[it];
}

long long query(long long roomsreq, long long left, long long right, long long it, vector<long long>&segtree){
	if(segtree[it]<roomsreq){
		// cout<<"returning from here only"<<endl;
		return LLONG_MIN;
	}

	if(left == right){
		if(segtree[it]>=roomsreq){
			return left;
		}
		return LLONG_MIN;
	}

	long long mid = (left + right)/2;
	long long leftside = query(roomsreq,left,mid,2*it+1,segtree);
	long long rightside = query(roomsreq, mid+1,right,2*it+2,segtree);

	if(leftside!=LLONG_MIN){
		return leftside;
	}

	else{
		return rightside;
	}
}

void func(){
	int n,q;
	cin>>n>>q;

	vector<long long>vec(n);
	vector<long long>segtree(4*n + 5);

	for(int i = 0; i<n; i++){
		cin>>vec[i];
	}

	buildtree(0,0,n-1,vec,segtree);

	for(int i = 0; i<q; i++){
		long long a;
		cin>>a;
		cout<<a<<endl;
		cout<<segtree[0]<<endl;
		// long long ans = query(a,0,n-1,0,segtree);
		// // cout<<ans<<endl;
		// if(ans != LLONG_MIN){
		// 	cout<<ans+1<<" ";
		// 	updatetree(ans,vec[ans]-a,0,n-1,0,segtree);
		// 	vec[ans]-=a;
		// }
		// else{
		// 	cout<<0<<" ";
		// }
	}
}

int main(){
	init_code();
	func();	
}