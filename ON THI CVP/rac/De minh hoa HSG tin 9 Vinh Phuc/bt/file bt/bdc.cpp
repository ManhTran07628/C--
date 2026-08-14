#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+1;
ll hoa[N],f[N];

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
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < s.size();i++) {
        hoa[i+1] = hoa[i];
        if(s[i] >= 'A' && s[i] <= 'Z')
            hoa[i+1]++;
    }
    ll m1 = n;
    fill(f,f+n+3,1e9);
    for(int i = 1;i <= s.size();i++) {
        f[i] = min(f[i-1],i-hoa[i]+hoa[n]-hoa[i]);
    }
    cout << f[n];
    return 0;
}
// GTmpijYHAaKA
// Auutcg - 1
//
