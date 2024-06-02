#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
long long mod = 1000000007;

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

struct cmp1{
	bool operator()(const pair<pair<int,int>,int>&a, const pair<pair<int,int>,int>&b)const{
		if(a.first==b.first){
			return a.first.second<b.first.second;
		}
		return a.first.first>b.first.first;
	}
};

struct cmp2{
	bool operator()(const pair<pair<int,int>,int>&a, const pair<pair<int,int>,int>&b)const{
		if(a.first==b.first){
			return a.first.second>b.first.second;
		}
		return a.first.first<b.first.first;
	}
};

bool chk(pair<pair<int,int>,int>a, pair<pair<int,int>,int>b){
	if(a.first.first==b.first.first){
		return a.first.second<b.first.second;
	}

	return a.first.first>b.first.first;
}

void func(){
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, cmp1>maxHeap;
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp2>minHeap;

	
	while(true){
		int currele;
		cin>>currele;
		if(currele == 0){
			break;
		}

		else if(currele == -1){

			if(maxHeap.size()==0 and minHeap.size()==0){
				continue;
			}

			// pair<pair<int,int>,int>p = maxHeap.top();
			// maxHeap.pop();
			// cout<<p.second<<endl;
			// if(maxHeap.size()!=minHeap.size()){
			// 	maxHeap.push(minHeap.top());
			// 	minHeap.pop();
			// }

			if(minHeap.size()==maxHeap.size()){
				pair<pair<int,int>,int>p = minHeap.top();
				minHeap.pop();
				cout<<p.second<<"\n";
			}

			else{
				pair<pair<int,int>,int>p = maxHeap.top();
				maxHeap.pop();
				cout<<p.second<<"\n";
			}
		}

		else{
			int score = currele;
			int ts,rl;
			cin>>ts>>rl;
			pair<pair<int,int>,int>p = {{score,ts},rl};

			if(maxHeap.size()==0){
				maxHeap.push(p);
			}

			else{
				if(chk(maxHeap.top(),p)){
					//if true
					minHeap.push(p);
				}

				else{
					maxHeap.push(p);
				}
			}

			while(maxHeap.size()-minHeap.size()>1){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}

			while(minHeap.size()>maxHeap.size()){
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
		}
	}
}	

int main(){
	fast_io;
	init_code();

	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		func();
		// cout<<endl;
	}
}