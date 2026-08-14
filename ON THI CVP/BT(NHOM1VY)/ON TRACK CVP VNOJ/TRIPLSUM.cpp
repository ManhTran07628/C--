#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int check = 0;
        for(int j = 1;j <= n;j++) {
            if(i != j) {
                for(int k = 1;k <= n;k++) {
                    if(k != j && k != i && a[i] == a[j] + a[k])  check = 1;
                    if(check == 1) break;
                }
            }
            if(check == 1) break;
        }
        ans += check;
    }
    cout << ans;
    return 0;
}