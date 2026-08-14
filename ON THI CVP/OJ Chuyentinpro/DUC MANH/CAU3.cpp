#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],b[MAXN],da[MAXN],db[MAXN],dda[MAXN],ddb[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dda[++da[a[i]]]++;
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        ddb[++db[b[i]]]++;
    }
    while(q--) {
        int k;
        cin >> k;
        cout << dda[k] << ' ' << ddb[k] << '\n';
    }
    return 0;
}