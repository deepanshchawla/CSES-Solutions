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


void func(string & line){
	stack<int>stk;
	stringstream ss(line);
	string str;
	while(getline(ss, str, ' ')){
		int currno = stoi(str);
		stk.push(currno);
	}
	int flag = 1;
	while(stk.empty()==false){
		if(flag){
			cout<<stk.top()<<" ";
		}
		stk.pop();
		flag = 1-flag;
	}
}

int main(){
	string line;
	while(getline(cin,line)){
		func(line);
	}
	return 0;
}