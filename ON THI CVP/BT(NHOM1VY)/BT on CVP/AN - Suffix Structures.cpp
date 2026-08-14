#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

string s,t;
bool automaton()
{
    int j = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == t[j]) {
            j++;
        }
        if(j == t.size()) return 1;
    }
    if(j == t.size()) return 1;
    return 0;
}

bool arrayt(string a,string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a == b) return 1;
    return 0;
}

ll both(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int j = 0;
    for(int i = 0; i < s.size(); i++)
    {
     if(s[i] == t[j]){
         j++;
     }
    }
    if(j == t.size()) return 1;
    return 0;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    int n = s.size();
    if(automaton()) {
        cout << "automaton";
        return 0;
    }
    if(arrayt(s,t)) {
        cout << "array";
        return 0;
    }
    if(both(s,t)) {
         cout << "both";
         return 0;
    }
    cout << "need tree";
    return 0;
}