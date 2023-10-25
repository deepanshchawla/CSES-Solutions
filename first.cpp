#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll mod = 1000000007;

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

ll func2(ll it, ll low, ll high, vector<ll>&vec, vector<ll>&seg_tree){
	// if()

	if(low == high){
		return seg_tree[it] = vec[low];
	}
	// cout<<it<<endl;
	// cout<<low<<" "<<high<<endl;
	return seg_tree[it] = min(func2(2*it+1, low, (low+high)/2, vec,seg_tree),func2(2*it+2, (low+high)/2 + 1, high, vec,seg_tree));
}

ll find(ll left, ll right, ll low, ll high, int it, vector<ll>&seg_tree){
	//no overlap
	if(left>high or right<low)return INT_MAX;
	
	if(left<=low and right>=high)return seg_tree[it];
	// cout<<low<<" "<<high<<endl;
	return min(find(left,right, low,(low+high)/2,2*it+1, seg_tree), find(left, right, (low+high)/2+1, high, 2*it+2, seg_tree));
}


void func(){
	ll n, q;
	cin>>n>>q;
	vector<ll>vec;
	for(int i = 0; i<n; i++){
		ll ele;
		cin>>ele;
		vec.push_back(ele);
	}

	int height = ceil(log2(2*n-1));
	
	vector<ll>seg_tree(pow(2,height)-1);
	ll seg_it = 0;
	// cout<<seg_tree.size()<<endl;
	ll low = 0, high = vec.size()-1;
	func2(seg_it, low, high, vec, seg_tree);
	// for(auto x: seg_tree){
	// 	cout<<x<<" ";
	// }
	// cout<<endl;

	for(ll i = 0; i<q; i++){
		ll left,right;
		cin>>left>>right;
		cout<<find(left-1,right-1,0,vec.size()-1,0,seg_tree)<<endl;
	}

}

int main(){
	init_code();
	func();
	return 0;
}