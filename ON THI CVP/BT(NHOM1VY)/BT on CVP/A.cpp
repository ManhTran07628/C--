#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.empty()) {
        cout << 0;
        return 0;
    }
    if(s[0] != s[s.size()-1]) {
        cout << 1;
        return 0;
    }
    for(int i = 1;i < s.size()-1;i++) {
        if(s[0] != s[i] && s[i+1] != s[s.size()-1]) {
            cout << 2;
            return 0;
        }
    }
    cout << -1;
    return 0;
}