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

void func(){
	ll n,k;
	cin>>n>>k;
	vector<priority_queue<ll>>cost_sw_pq(101);
	vector<ll>cost_vals,sweetness_vals;
	for(ll i = 0; i<n; i++){
		ll curr_cost;
		cin>>curr_cost;
		cost_vals.push_back(curr_cost);
	}

	for(ll i = 0; i<n; i++){
		ll curr_sweetness;
		cin>>curr_sweetness;
		sweetness_vals.push_back(curr_sweetness);
	}

	for(int i = 0 ;i<n; i++){
		cost_sw_pq[cost_vals[i]].push(sweetness_vals[i]);
	}

	for(int i = 0; i<k; i++){
		int s,e;
		cin>>s>>e;
		int currans = -1;
		int currmaxs = 0;
		for(int j = s; j<=e; j++){
			if(!cost_sw_pq[j].empty() and cost_sw_pq[j].top()>=currmaxs){
				if(currmaxs!=-1){
					cost_sw_pq[currans].push(currmaxs);
				}
				currmaxs = cost_sw_pq[j].top();
				cost_sw_pq[j].pop();
				currans = j;
			}
		}

		if(i == k-1){
			cout<<currmaxs<<endl;
		}
	}
}

int main(){
	init_code();
	int tc;
	cin>>tc;	
	while(tc--){
		func();
	}

	return 0;
}