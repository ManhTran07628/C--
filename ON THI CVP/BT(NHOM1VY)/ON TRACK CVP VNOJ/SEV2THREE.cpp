#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 7;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 3;i <= n;i++) {
        if(a[1] + a[2] + a[i] == a[n]) {
            cout << a[1] << ' ' << a[2] << ' ' << a[i];
            return 0;
        }
    }
    return 0;
}