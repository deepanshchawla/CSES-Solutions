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

/*
Problem Explanation:

the problem is quite simple we need to find the length of the shortest route from a source to a destination. But the catch is that there is a coupon which can be used only once and which makes the cost of the path half.

Now we have to find the shortest route cost from source to destination by using atmost one coupon optimally. The test cases are quite tight so we need to think something fast and optimal

Solution: if there is no flag like coupon in this question then the question is quite simple, we will simply use dijkstra to find the length of shortest route from source to destination.

But here, to solve this question, i have used dijkstra in a different way. 
	1. I have found the minimum distance from the source node to all other nodes and 
 	2. from the all other nodes to the destination node. Here we have inverted the graph and found the shortest distance from the destination node to all other nodes, this indirectly gives us the shortest distance from the destination to all other nodes.
  	3. now i have traversed on each edge and tried weather can it be the part of my path with the coupon applied and will it give the shortest distance.
   	4. this solution works because applying coupon is always better because it only reduces the path cost so we need to apply this on an edge such that by applying it on that edge it gives the overall shortest path.
    	5. it has to be applied on on of the edge so why not try each and every edge and find the minimum distance to reach from source to destination.

if you still not understood, ping me or raise an issue i will be more than happy to answer you.
*/


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
