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

string longestCommonPrefix(vector<string>p){
	unordered_map<string,int>mp;
	for(int i = 0; i<p.size(); i++){
		string curr;
		for(int j = 0; j<p[i].size(); j++){
			char currchar = tolower(p[i][j]);
			curr.push_back(currchar);
			mp[curr]++;
		}
	}

	string ans = "";
	for(auto x: mp){
		if(x.second == p.size()){
			if(x.first.size()>ans.size()){
				ans = x.first;
			}
		}
	}

	return ans;
}

int minimumColorsNeeded(vector<int>boxes, int s){
	int ans = 1;
	int mini = INT_MAX, maxi = INT_MIN;
	for(int i = 0; i<boxes.size(); i++){
		mini = min(mini, boxes[i]);
		maxi = max(maxi, boxes[i]);
		cout<<i<<" "<<mini<<maxi<<endl;
		if(maxi-mini<=s){
			continue;
		}

		else{
			ans++;
			mini = boxes[i];
			maxi = boxes[i];
		}
	}

	return ans;
}

int main(){
	init_code();
	vector<string>vec = {"flower", "FLOW", "Floor", "flow"};
	cout<<minimumColorsNeeded({1,3,1,2,4,2,1}, 2);
	return 0;
}