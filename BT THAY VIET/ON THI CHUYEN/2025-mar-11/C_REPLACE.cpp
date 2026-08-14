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
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int x = 0;x <= 30;x++) {
        int i = 1,j = 1,cnt = 0,h = k;
        while(i <= n && j <= n) {
            if(a[j] == x) j++;
            else {
                if(h >= 0) {
                    h--;
                    j++;
                }
                while(h < 0 && i <= n) {
                    if(a[i] != x) h++;
                    i++;
                }
            }
            ans = max(ans,j-i);
        }
    }
    cout << ans;
    return 0;
}