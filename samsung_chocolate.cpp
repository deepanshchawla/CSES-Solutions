#include<iostream>
#include<string>
#include<chrono>
using namespace std;

static const int maxWordsCount = 100000;
static const int ValidCharsCount = 10;
static const int maxWordLength = 10;
static const int minWordLength = 6;
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// void init_code(){
//     fast_io;

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
// }

struct trienode{
    int count;
    trienode * arr[26];

    trienode(){
        for(int i = 0; i<26; i++){
            arr[i] = NULL;
        }
        count = 0;
    }
};

struct trienode * root = new trienode();

void insertinto(string  word){
    trienode * temp = root;

    for(int i = 0; i<word.size(); i++){
        if(temp->arr[word[i]-'a']==NULL){
            temp->arr[word[i]-'a'] = new trienode();
        }
        temp = temp->arr[word[i]-'a'];
    }

    temp->count++;
    // cout<<temp->count<<endl;
}

int func(int * freq, struct trienode * root){
    trienode * curr = root;
    int currans = root->count;
    for(int i = 0; i<26; i++){
        if(curr->arr[i]!=NULL and freq[i]>0){
            freq[i]--;
            currans+=func(freq,curr->arr[i]);
            freq[i]++;
        }
    }
    // cout<<currans<<endl;
    return currans;
}

int queryCount;

void init(const int N, const string words[maxWordsCount]){
    for(int i = 0; i<4; i++){
        insertinto(words[i]);   
    }
}

int query(const string& validChars){
    int arr[26] = {0};
    // cout<<"Inserted all the chars into the freq array"<<endl;
    for(int i = 0; i<validChars.size(); i++){
        arr[validChars[i]-'a']++;
    }

    int ans = func(arr, root);
    // cout<<ans<<endl;
    return ans;
}

string words[maxWordsCount];
string validChars;

void generateWords()
{
    int N = 0;
    cin >> N>>queryCount;
    // cout<<N<<endl;
    // cout<<queryCount<<endl;
    for (int wc = 1; wc <= N; wc++)
    {
        string str;
        cin >> str;
        words[wc - 1] = str;
        // cout<<str<<endl;
        // cout<<words[wc-1]<<endl;
    }
}

int main()
{

    
    // init_code();
    FILE* pf = 0;

    FILE* pfout = 0;

    //freopen_s(&pf, "input.txt", "r", stdin);

    //freopen_s(&pfout, "out.txt", "w", stdout);
    

    generateWords();

    init(maxWordsCount, words);

    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int score = 1000;
    for (int q = 1; q <= queryCount; q++)
    {
        int expectedOutput = 0;

        cin >> validChars >> expectedOutput;
        // cout<<q<<" ";
        int validWords = query(validChars);

        if (expectedOutput != validWords)
            score--;
    }

    if (score != 1000)
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}