#include <bits/stdc++.h>
#define OPTIMIZE_IO                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define NEW_LINE "\n"
using namespace std;


// void init_code(){
// 	fast_io;

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// }


struct CustomComparator
{
    bool operator()(const pair<int, pair<int, int>> &current, const pair<int, pair<int, int>> &other)
    {
        if (current.first == other.first)
        {
            return current.second.first > other.second.first;
        }
        else
        {
            return current.first < other.first;
        }
    }
};

void func(){
    set<pair<int, pair<int, int>>, CustomComparator> lowSet, highSet;
	
    while (true)
    {
        int number;
        cin >> number;
        if (number == 0)
        {
            break;
        }
        else if (number == -1)
        {
            if (!lowSet.empty())
            {
                cout << lowSet.rbegin()->second.second << NEW_LINE;
                lowSet.erase(*lowSet.rbegin());
                int totalElements = lowSet.size() + highSet.size();
                if (highSet.size() > totalElements / 2)
                {
                    lowSet.insert({highSet.begin()->first, {highSet.begin()->second.first, highSet.begin()->second.second}});
                    highSet.erase(*highSet.begin());
                }
            }
        }
        else
        {
            int time, rollNumber;
            cin >> time >> rollNumber;
            if (lowSet.empty())
            {
                lowSet.insert({number, {time, rollNumber}});
            }
            else
            {
                auto iterator = lowSet.rbegin();
                auto it = iterator->first;
                if (number <= it)
                {
                    lowSet.insert({number, {time, rollNumber}});
                    int totalElements = lowSet.size() + highSet.size();
                    if (lowSet.size() > (totalElements + 1) / 2)
                    {
                        highSet.insert({lowSet.rbegin()->first, {lowSet.rbegin()->second.first, lowSet.rbegin()->second.second}});
                        lowSet.erase(*lowSet.rbegin());
                    }
                }
                else
                {
                    highSet.insert({number, {time, rollNumber}});
                    int totalElements = lowSet.size() + highSet.size();
                    if (highSet.size() > totalElements / 2)
                    {
                        lowSet.insert({highSet.begin()->first, {highSet.begin()->second.first, highSet.begin()->second.second}});
                        highSet.erase(*highSet.begin());
                    }
                }
            }
        }
    }
}

int main()
{
    // init_code();
    OPTIMIZE_IO;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        func();
    }
    
    return 0;
}
