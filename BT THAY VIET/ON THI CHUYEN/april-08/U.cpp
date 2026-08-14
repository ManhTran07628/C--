#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++) {
        int b[11];
        for(int j = 1;j <= n-i;j++) {
            b[j] = a[j]+a[j+1];
            cout << b[j] << ' ';
        }
        for(int j = 1;j <= n-i;j++) {
            a[j] = b[j];
        }
        cout << '\n';
    }
    return 0;
}