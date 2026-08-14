#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = n,id = 1;
    while(i <= j) {
        if(a[i] > a[j]) {
            ans += a[j]*id;j--;
        }
        else {
            ans += a[i]*id;i++;
        }
        id++;
    }
    cout << ans;
    return 0;
}