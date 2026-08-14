#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[2000][2000],p[MAXN];
vector<int> xl;
void sieve()
{
    fill(p+1,p+MAXN+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i*i < MAXN;i++)
        if(p[i])
            for(int j = i*2;j < MAXN;j+=i) 
                p[j] = 0;
    for(int i = 2;i < MAXN;i++)
        if(p[i]) xl.push_back(i);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int x;
            cin >> x;
            if(p[x]) a[i][j] = 0;
            else {
                int p = lower_bound(xl.begin(),xl.end(),x)-xl.begin();
                a[i][j] = xl[p]-x;
            }
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    while(q--) {
        int a1,b,c,d;
        cin >> a1 >> b >> c >> d;
        int s = a[c][d]-a[c][b-1]-a[a1-1][d]+a[a1-1][b-1];
        cout << s << '\n';
    }
    return 0;
}