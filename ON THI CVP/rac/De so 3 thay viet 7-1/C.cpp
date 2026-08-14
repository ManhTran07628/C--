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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int crr = 0;
        for(int j = i+1;j <= n;j++) {
            if(a[j-1] < a[j]) {
                crr = max(ans,a[j] - a[i]);
            }
            else break;
        }
        ans = max(ans,crr);
    }
    cout << ans;
    return 0;
}