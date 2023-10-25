#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int mod = 1000000007;

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

ll func(ll k, vector<pair<ll,ll>>&vec){
	map<ll,ll>mp;
	
}

void func(){
	ll n, k;
	cin>>n>>k;
	vector<pair<ll,ll>>vec;
	for(ll i = 0; i<n; i++){
		ll start,end;
		cin>>start>>end;
		vec.push_back({start,end});
	}

	sort(vec.begin(), vec.end());
	ll ans;
	ll low = k, high = n;
	while(low<=high){
		ll mid = low + (high-low)/2;
		if(func(k,vec)>=mid){
			ans = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	cout<<ans<<endl;
}

int main(){
	init_code();
	func();
	return 0;
}