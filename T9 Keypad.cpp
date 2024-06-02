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

void helper(int it, string str, vector<string>&vec, string curr){
	if(it == str.size()){
		cout<<curr<<" ";
		return;
	}

	for(auto x: vec[str[it]-'0']){
		curr.push_back(x);
		helper(it+1,str,vec,curr);
		curr.pop_back();
	}
}

void func(){
	// unordered_map<int,string>mp;
	vector<string>vec = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int n;
	cin>>n;

	helper(0,to_string(n),vec, "");
}	

int main(){
	fast_io;
	// init_code();

	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		func();
		cout<<endl;
	}
}