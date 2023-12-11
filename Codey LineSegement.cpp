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


void func(){
	int n;
	cin>>n;

	// vector<vector<int>>vec;
	vector<pair<int,int>>starting;
	vector<pair<int,int>>ending;
	vector<int>y;
	for(int i = 0; i<n; i++){
		int a, b, c;
		cin>>a>>b>>c;
		// vec.push_back({a,b,c});
		starting.push_back({a,i});
		ending.push_back({b,i});
		y.push_back(c);
	}

	map<int,int>yvalues;
	// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	sort(starting.begin(), starting.end());
	sort(ending.begin(), ending.end());
	int maxsize = 1;
	int minlen = 0;
	int currsize = 0;
	int j = 0;

	for(int i = 0; i<starting.size(); i++){

		while(starting[i].first>ending[j].first){
			int value = y[ending[j].second];
			yvalues[value]--;
			if(yvalues[value]==0){
				yvalues.erase(value);
			}
			j++;
		}

		// currsize+=1;
		yvalues[y[starting[i].second]]++;
		
		if(maxsize<(i-j+1)){
			maxsize = i-j+1;
			minlen = (yvalues.rbegin()->first-yvalues.begin()->first);
			// maxlen = minlen;
		}

		else if(maxsize == i-j+1){
			minlen = min(minlen, yvalues.rbegin()->first-yvalues.begin()->first);
			// maxlen = max(maxlen, yvalues.rbegin()->first-yvalues.begin()->first);
		}
	}

	cout<<maxsize<<" "<<minlen<<endl;
}


int main(){
	fast_io;
	// init_code();
	int tc;
	cin>>tc;
	// cout<<tc<<endl;
	for(int i = 0; i<tc; i++){
		func();
	}
}