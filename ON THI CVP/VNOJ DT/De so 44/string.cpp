#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 5e5+7;
ll n,m;
string a,b;
ll v[N];
ll p[N][58];

ll check(ll i)
{
    for(int j = 'A';j <= 'z';j++) {
        if(p[i][j-'A'] - p[i-n][j-'A'] != v[j-'A']) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "string"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> a >> b;
    for(auto i:a) v[i-'A']++;

    for(int i = 1;i <= m;i++) {
        for(int j = 'A';j <= 'z';j++) {
            p[i][j-'A'] = p[i-1][j-'A'];
        }
        p[i][b[i-1]-'A']++;
    }
    ll cnt = 0;
    for(int i = n;i <= m;i++) {
        if(check(i)) cnt++;
    }
    cout << cnt;
    return 0;
}