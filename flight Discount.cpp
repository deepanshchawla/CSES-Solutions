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

void dij(ll node, vector<ll>&a, vector<vector<pair<ll,ll>>>&mp){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	pq.push({0,node});
	// a[node] = 0;
	vector<int>vis(a.size(),0);
	// vis[node] = 1;

	while(pq.empty()==false){
		ll currnode = pq.top().second;
		ll currcost = pq.top().first;
		pq.pop();

		if(a[currnode]!=LLONG_MAX){
			continue;
		}
		a[currnode] = currcost;
		for(auto x: mp[currnode]){
			if(a[x.first]>currcost+x.second){
				// a[x.first] = ;
				pq.push({currcost+x.second,x.first});
			}
		}
	}
}

void func(){
	ll n, m;
	cin>>n>>m;
	ll ans = LLONG_MAX;
	vector<pair<ll,pair<ll,ll>>>edges;
	vector<vector<pair<ll,ll>>>mp1(n+1), mp2(n+1);
	vector<ll>a(n+1, LLONG_MAX),b(n+1, LLONG_MAX);

	for(ll i = 0; i<m; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		mp1[a].push_back({b,c});
		mp2[b].push_back({a,c});
		edges.push_back({a,{b,c}});
	}		

	dij(1,a,mp1);
	dij(n,b,mp2);

	for(auto x: edges){
		if(b[x.second.first]!=LLONG_MAX and a[x.first]!=LLONG_MAX){
			ans = min(ans, a[x.first]+b[x.second.first]+(x.second.second/2));
		}
	}

	cout<<ans<<endl;
}

int main(){
	init_code();
	func();
	return 0;
}