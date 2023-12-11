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

int func2(int l, int r, vector<int>&vec){
	auto itl = lower_bound(vec.begin(), vec.end(),l);
	auto itr = upper_bound(vec.begin(), vec.end(),r);
	return itr-itl;
}

void func(){
	int n;
	cin>>n;
	
	vector<int>one,two;
	for(int i = 0; i<n; i++){
		int ele;
		cin>>ele;
		if(i%2 == 0){
			one.push_back(ele);
		}

		else{
			two.push_back(ele);
		}
	}

	int qu;
	cin>>qu;

	for(int i = 0; i<qu; i++){
		int l,r;
		cin>>l>>r;
		int ans = func2(l,r,one) + func2(l,r,two);
		cout<<ans<<endl;
	}
}	

int main(){
	fast_io;
	// init_code();
	int tc;
	cin>>tc;

	for(int i = 0; i<tc; i++){
		func();
	}
}