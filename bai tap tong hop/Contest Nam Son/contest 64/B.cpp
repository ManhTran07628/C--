#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],p[MAXN],d[MAXN],lt[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    int ans = 1;
    for(int i = 2;i < MAXN;i++) {
        int cnt = 0;
        for(int j = i;j < MAXN;j+=i) {
            cnt += d[j];
        }
        if(cnt >= 2) ans = i;
    }
    cout << ans;
    return 0;
}