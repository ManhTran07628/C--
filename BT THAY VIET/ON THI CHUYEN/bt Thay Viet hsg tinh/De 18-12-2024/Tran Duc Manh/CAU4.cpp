#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll nguyen[N],phu[N];

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
    ll cnt = 0;
    for(int i = 0;i < s.size();i++) {
        nguyen[i+1] = nguyen[i];
        phu[i+1] = phu[i];
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            nguyen[i+1]++;
            cnt += phu[i+1];
        }
        else {
             phu[i+1]++;
             cnt += nguyen[i+1];
        }
    }
    cout << cnt;
    return 0;
}