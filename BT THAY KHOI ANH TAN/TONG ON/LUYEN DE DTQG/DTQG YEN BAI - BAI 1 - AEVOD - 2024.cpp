#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,k,prime[MM],a[MM];

void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(int i = 2;i * i < MM;i++)
        if(prime[i])
            for(int j = i * i;j < MM;j += i)
                prime[j] = 0;
}

bool check(int length,int cnt)
{
    int sum = 0;
    for(int i = 1,j = 1;j <= n;j++) {
        sum += a[j];
        if(j - i + 1 > length) {
            sum -= a[i];
            i++;
        }
        if(j - i + 1 == length && sum == cnt) return 1;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "AEVOD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = (prime[ a[i] ] ? 1 : 0);
    }
    int ans = 0;
    for(int mid = n / (k+1);mid >= 1;mid--) {
        if(check(mid * (k+1),mid * k)) {
            ans = mid;
            break;
        }
    }
    cout << ans * (k+1) << '\n';
    int sum = 0;
     for(int i = 1,j = 1;j <= n;j++) {
        sum += a[j];
        if(j - i + 1 > ans * (k+1)) {
            sum -= a[i];
            i++;
        }
        if(j - i + 1 == ans * (k+1) && sum == ans * k) {
            cout << i << ' ';
        }
    }
    return 0;
}