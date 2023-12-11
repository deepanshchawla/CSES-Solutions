#include<bits/stdc++.h>
using namespace std;

void init_code(){
	fast_io;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int N = 10000;
static int gifts[N] ;
int user_gifts[N];
static int calls = 0;
static int numberOfGifts = 0;
const int KK = 7;

bool swap(int a[KK], int b[KK], int k)
{
	calls++;
	int temp[KK];

	for (int i = 0; i < k; i++)
	{
		temp[i] = gifts[a[i]];
		gifts[a[i]] = -1;
	}

	for (int i = 0; i < k; i++)
	{
		if (gifts[b[i]] != -1)
			return false;
		gifts[b[i]] = temp[i];
	}

	return true;
}

void build_arr()
{		
	for(int i = 0 ; i < numberOfGifts; i++)	
	{
		cin >> gifts[i];	
		user_gifts[i]=gifts[i];
	}
}


extern void arrange(int arr[],int N);
bool check()
{
	if(calls > numberOfGifts/6*2)
		return false;
	for (int i = 0; i < numberOfGifts; i++)
	{
		if (gifts[i] != i)
			return false;
	}
	return true;
}

int main()
{	
	init_code();

	for (int i = 0; i < 50; i++)
	{
		cin >> numberOfGifts;

		build_arr();

		arrange(user_gifts,numberOfGifts);

		bool res = check();
		if(res)
			cout<<1<<endl;
		else
			cout<<0<<endl;
#if 0//will be used for evaluation 
		if (res)
		{
			cout << "score :: " << calls << endl;
		}
		else
		{
			cout << "score :: " << 999999999999 << endl;
		}
#endif
		calls = 0;
	}
	return 0;
}


////////////////////////////////////user code///////////////////////////////////////


void arrange(int userGifts[], int N)
{
	
}
