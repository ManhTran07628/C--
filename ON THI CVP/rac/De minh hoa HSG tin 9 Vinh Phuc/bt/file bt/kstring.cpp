#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "kstring"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int k;
    cin >> k;
    string s,s1;
    cin >> s;
    if(s.size() % k != 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0;i < s.size();i++) a[s[i]]++;

    for(char i = 'a';i <= 'z';i++) {
        if(a[i] > 0) 
            if(a[i] < k) {
                cout << -1;
                return 0;
            }
    }
    sort(s.begin(),s.end());
    for(int i = 0;i < s.size();i++) {
        for(int j = i;j < s.size();j += k) {
            s1 += s[j];
        }
        cout << s1 << '\n';
    }
    s1.erase(s.size());
    // cout << s1;
    return 0;
}