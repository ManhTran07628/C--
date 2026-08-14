#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
int n;


void solve()
{
    for(int i = 1;i <= n;i++) {
        int k = a[i];
        for(int j = 1;j <= sqrt(k);j++) {
            if(k % j == 0) {
                b[j]++;
                if(k / j != j) {
                    b[k/j]++;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cdiv"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    solve();
    ll ans = 1;
    for(int i = 1;i <= 1e6;i++) {
        if(b[i] >= 2) 
            ans = i;
    }
    cout << ans;

    return 0;
}