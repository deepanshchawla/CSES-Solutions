#include<iostream>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int chk(int * vec, int * vec_g, int n, int g, int mid){
	int j = 0;
	int cuf = vec_g[j];
	j++;
	for(int i = 0; i<n; i++){
		if(vec[i]<=mid){
			cuf--;
			if(cuf == 0){
				if(j<g){
					cuf = vec_g[j];
					j++;
				}
				else{
					return true;
				}
			}
		}

		else{
			cuf = vec_g[j-1];
		}
	}

	return false;
}

int func(){
	int n,g;
	cin>>n>>g;
	int mini = 1e9,maxi = -1e9;

	int vec[n];
	int vec_g[g];

	for(int i = 0; i<n; i++){
		cin>>vec[i];
		mini = min(mini, vec[i]);
		maxi = max(maxi, vec[i]);
	}

	for(int i = 0; i<g; i++){
		cin>>vec_g[i];
	}

	int ans = -1;
	int low = mini, high = maxi;

	while(low<=high){
		int mid = low + (high-low)/2;

		if(chk(vec,vec_g,n,g,mid)){
			ans = mid;
			high = mid-1;
		}

		else{
			low = mid+1;
		}
	}

	return ans;
}

int main(){
	init_code();
	int tc;
	cin>>tc;

	for(int i = 1; i<=tc; i++){
		cout<<"#"<<i<<" "<<func()<<endl;
	}
}