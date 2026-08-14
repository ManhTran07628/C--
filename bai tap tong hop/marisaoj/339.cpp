#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int p[N],a[N];
vector<int> f;
void prime()
{
    fill(p+1,p+N+1,1);
    p[1] = p[0] = 0;
    for(ll i = 2;i*i < N;i++) {
        if(p[i]) {
            for(ll j = i*2;j < N;j+=i) {
                p[j] = 0;
            }
        }
    }
    for(int i = 2;i < N;i++) {
        if(p[i]) f.push_back(i);
    }
}

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
    prime();
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        int ans = 1;
        int n = upper_bound(f.begin(),f.end(),sqrt(x)) - f.begin();
        for(int i = 0;i <= n;i++) {
            int cur = 1;
            while(x % f[i] == 0) {
                cur++;
                x /= f[i];
            }
            ans *= cur;
            if(x < f[i] || x == 1) break;
        }
        if (x > 1) ans *= 2;
        cout << ans << '\n';
    }
    return 0;
}