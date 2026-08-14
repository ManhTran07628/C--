#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll r[N],b[N];

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
    string s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        r[i] = r[i-1] + (s[i-1] == 'R');
        if(s[i-1] == 'G') r[i] = 0;
    }
    for(int i = n;i >= 1;i--) {
        b[i] = b[i+1] + (s[i-1] == 'B');
        if(s[i-1] == 'G') b[i] = 0;
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(s[i-1] == 'G') cnt += r[i-1]*b[i+1];
    }
    cout << cnt;
    return 0;
}