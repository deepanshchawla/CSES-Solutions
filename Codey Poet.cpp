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

struct trie{
	int eow;
	struct trie * arr[26];

	trie(){
		for(int i = 0; i<26; i++){
			arr[i] = NULL;
		}

		eow = 0;
	}
};

struct trie * s_root = new trie();
struct trie * r_root = new trie();

void insertInto(struct trie * root, string word, int tbi){
	trie * temp = root;
	for(int i = 0; i<word.size(); i++){
		if(temp->arr[word[i]-'a']==NULL){
			temp->arr[word[i]-'a'] = new trie();
		}
		temp = temp->arr[word[i]-'a'];

		temp->eow+=tbi;
	}
}

void rev_insertInto(struct trie * root, string word, int tbi){
	trie * temp = root;
	for(int i = word.size()-1; i>=0; i--){
		if(temp->arr[word[i]-'a']==NULL){
			temp->arr[word[i]-'a'] = new trie();
		}
		temp = temp->arr[word[i]-'a'];

		temp->eow+=tbi;
	}
}


void removeDuplicateOfWord(struct trie * root, string word, int tbr){
	if(tbr == 0)return;
	trie * temp = root;
	for(int i = 0; i<word.size(); i++){
		temp = temp->arr[word[i]-'a'];
		temp->eow-=tbr;
	}
}

void rev_removeDuplicateOfWord(struct trie * root, string word, int tbr){
	if(tbr == 0)return;
	trie * temp = root;
	for(int i = word.size()-1; i>=0; i--){
		temp = temp->arr[word[i]-'a'];
		temp->eow-=tbr;
	}
}

int startingWith(struct trie * root, string & word){
	trie * temp = root;

	for(int i = word.size()-1; i>=0; i--){
		if(temp->arr[word[i]-'a']!=NULL){
			temp = temp->arr[word[i]-'a'];
		}

		else{
			return 0;
		}
	}

	return temp->eow;
}


void func(){
	int n,q;
	cin>>n>>q;
	// cout<<n<<q<<"\n";
	unordered_map<string,int>mp;

	for(int i = 0;i<n; i++){
		string word;
		cin>>word;
		
		mp[word]++;
	}

	for(auto & x: mp){
		insertInto(s_root, x.first, x.second);
		rev_insertInto(r_root, x.first, x.second);
	}

	for(int i = 0; i<q; i++){
		int n;
		cin>>n;

		if(n == 1){
			string str;
			cin>>str;

			if(mp.count(str) and mp[str]>1){
				// string rev = str;
				// reverse(rev.begin(), rev.end());
				removeDuplicateOfWord(s_root,str,mp[str]-1);
				rev_removeDuplicateOfWord(r_root,str, mp[str]-1);
				int ans = mp[str]-1;
				mp[str] = 1;
				cout<<ans<<"\n";
			}

			else{
				cout<<0<<"\n";
			}
		}

		else if(n == 2){
			string str;
			cin>>str;

			cout<<startingWith(r_root,str)<<"\n";
		}

		else if(n == 3){
			string wtr,wwr;
			cin>>wtr>>wwr;
			// string r_wtr = wtr;
			// reverse(r_wtr.begin(), r_wtr.end());

			// string r_wwr = wwr;
			// reverse(r_wwr.begin(), r_wwr.end());
			if(mp.count(wtr)==0){
				cout<<0<<"\n";
			}

			else{
				int occ = mp[wtr];

				mp.erase(wtr);
				mp[wwr]+=occ;

				removeDuplicateOfWord(s_root,wtr,occ);
				rev_removeDuplicateOfWord(r_root,wtr, occ);

				insertInto(s_root,wwr,occ);
				rev_insertInto(r_root,wwr,occ);
				cout<<occ<<"\n";
			}
		}

		else if(n == 4){
			string word;
			cin>>word;

			// string rev = word;
			// reverse(rev.begin(), rev.end());
			mp[word]+=1;
			insertInto(s_root,word,1);
			rev_insertInto(r_root,word, 1);
		}

		else{
			for(auto & x: mp){
				// cout<<x.first<<" "<<x.second<<"\n";
				int currocc = x.second;
				x.second = 1;
				// string rev = x.first;
				// reverse(rev.begin(), rev.end());

				removeDuplicateOfWord(s_root,x.first,currocc-1);
				rev_removeDuplicateOfWord(r_root,x.first,currocc-1);
			}

			cout<<mp.size()<<"\n";
		}
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