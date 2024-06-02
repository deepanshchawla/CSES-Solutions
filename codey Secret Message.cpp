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


//down right dld drd 
int dx[4] = {+1, 0, 1,1};
int dy[4] = {0, +1, -1, 1};

// int dx[4] = {};
// int dy[4] = {}
void helper(vector<bool>&arr){
	arr[0] = false;
	arr[1] = false;
	for(int i = 2; i*i<arr.size(); i++){
		if(arr[i]==false)continue;
		for(int j = i*i; j<arr.size(); j+=i){
			arr[j] = false;
		}
	}
}

void func(){
	int n;
	cin>>n;
	// cout<<"here"<<endl;
	vector<vector<char>>vec(n,vector<char>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>vec[i][j];
		}
	}

	vector<bool>arr(1000001,true);
	helper(arr);
	unordered_map<char,int>mp;
	mp['0'] = 0;
	mp['1'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	mp['A'] = 10;
	mp['B'] = 11;
	mp['C'] = 12;
	mp['D'] = 13;
	mp['E'] = 14;
	mp['F'] = 15;
	int ans = 0;
	// cout<<"here ";
	// for(int i = 0; i<n; i++){
	// 	int j = 0;
	// 	if(vec[i][j]=='0')continue;

	// 	if(arr[mp[vec[i][j]]]){
	// 		ans++;
	// 	}

	// 	for(int d = 0; d<4; d++){
	// 		long long currno = mp[vec[i][j]];
	// 		int tempi = i, tempj = j;
	// 		tempi+=dx[d];
	// 		tempj+=dy[d];
	// 		int power = 0;
	// 		while(tempi>=0 and tempi<n and tempj>=0 and tempj<n and currno<=1000000){
	// 			currno*=16;
	// 			power++;
	// 			currno+=mp[vec[tempi][tempj]];

	// 			if(currno<=1000000 and arr[currno]){
	// 				cout<<currno<<endl;
	// 				ans++;
	// 			}

	// 			tempi+=dx[d];
	// 			tempj+=dy[d];
	// 		}

	// 		tempi = i, tempj = j;
	// 		while(tempi>=0 and tempi<n and tempj>=0 and tempj<n){
	// 			currno-=(mp[vec[tempi][tempj]]*power);
	// 			tempi+=dx[d];
	// 			tempj+=dy[d];

	// 			if(tempi>=0 and tempi<n and tempj>=0 and tempj<n and vec[tempi][tempj] != '0' and currno<=1000000 and arr[currno]){
	// 				cout<<currno<<endl;
	// 				ans++;
	// 			}
	// 			power--;
	// 		}
	// 	}
	// }

	// for(int j = 0; j<n; j++){
	// 	int i = 0;
	// 	if(vec[i][j]=='0')continue;
		
	// 	if(i!=j and arr[mp[vec[i][j]]]){
	// 		ans++;
	// 	}

	// 	for(int d = 0; d<4; d++){
	// 		long long currno = mp[vec[i][j]];
	// 		int tempi = i, tempj = j;
	// 		tempi+=dx[d];
	// 		tempj+=dy[d];
	// 		int power = 0;
	// 		while(tempi>=0 and tempi<n and tempj>=0 and tempj<n and currno<=1000000){
	// 			currno*=16;
	// 			power++;
	// 			currno+=mp[vec[tempi][tempj]];

	// 			if(currno<=1000000 and arr[currno]){
	// 				cout<<currno<<endl;
	// 				ans++;
	// 			}

	// 			tempi+=dx[d];
	// 			tempj+=dy[d];
	// 		}

	// 		tempi = i, tempj = j;
	// 		while(tempi>=0 and tempi<n and tempj>=0 and tempj<n){
	// 			currno-=(mp[vec[tempi][tempj]]*power);
	// 			tempi+=dx[d];
	// 			tempj+=dy[d];

	// 			if(tempi>=0 and tempi<n and tempj>=0 and tempj<n and vec[tempi][tempj] != '0' and currno<=1000000 and arr[currno]){
	// 				ans++;
	// 			}
	// 			power--;
	// 		}
	// 	}
	// }

	int ans = 0;

	for(int i = 0; i<n; i++){
		int power = 0;
		long long currno = mp[vec[i][0]];
		if(arr[currno]){
			ans++;
		}

		for(int j = 1; j<n; j++){
			power++;
			currno*=16;
			currno+=mp[vec[i[j]]];
			
		}
	}

	for(int j = 0; j<n; j++){
		for(int i = 0; i<n; i++){
			
		}
	}


	for(int j = 0, i = 0; j<n and i<n; i++,j++){

	}

	for(int i = 0, j = n-1; i<n and j>=0; j--, i++){

	}

	cout<<ans<<endl;
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