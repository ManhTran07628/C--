#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
set<pair<int,int>> s;
int p[MAXN];

void sieve()
{
    for(int i = 2;i * i < MAXN;i++) {
        if(p[i] == 0) {
            for(int j = i*2;j < MAXN;j+=i) {
                if(p[j] == 0) p[j] = i;
            }
        }
    }
    for(int i = 2;i < MAXN;i++) {
        if(p[i] == 0) p[i] = i;
    }
}



void xuly(int a,int b)
{
    int a1 = abs(a),b1 = abs(b);
    while(a1 > 1) {
        if(a1 / p[a1] != 0) a1 /= p[a1];
        else break;
    }
    if(a < 0) a1 *= -1;
    while(b1 > 1) {
        if(b1 / p[b1] != 0) b1 /= p[b1];
        else break;
    }
    if(b < 0) b1 *= -1;
    a = a1;
    b = b1;
}



int main()
{
    sieve();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    cin >> n >> x >> y;
    for(int i = 1;i <= n;i++) {
        int u,v;
        cin >> u >> v;
        u -= x;
        v -= y;
        xuly(u,v);
        s.insert({u,v});
    }
    cout << s.size() << '\n';
    // for(int i = 1;i <= n;i++) {
    //     cout << a[i].fi << ' ' << a[i].se << '\n';
    // }
    return 0;
}