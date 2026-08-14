#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int ans = 0,ans1 = 100;
        for(int i = 1;i <= n;i++) {
            int cnt = 1;
            for(int j = i;j < n;j++) {
                if(abs(a[j]-a[j+1]) <= 2) {
                    cnt++;
                }
                else break;
            }
            for(int j = i;j >= 2;j--) {
                if(abs(a[j]-a[j-1]) <= 2) {
                    cnt++;
                }
                else break;
            }
            ans = max(ans,cnt);
            ans1 = min(ans1,cnt);
        }
        cout << ans1 << ' ' << ans << '\n';

    }
    return 0;
}