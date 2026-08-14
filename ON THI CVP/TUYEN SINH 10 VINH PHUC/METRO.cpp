#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int s[MAXN];
vector<int> times;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d,t;
    cin >> n >> d >> t;
    for(int i = 1;i < MAXN;i++) {
        times.push_back(t+(i-1)*d);
    }
    for(int i = 1;i <= n;i++) {
        cin >> s[i];
        int p = lower_bound(times.begin(),times.end(),s[i])-times.begin();
        cout << p+1 << ' ';
    }
    return 0;
}