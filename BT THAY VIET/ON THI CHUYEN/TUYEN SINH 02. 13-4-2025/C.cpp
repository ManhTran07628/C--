#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int n;
void sub12()
{
    int ans = 1e9;
    for(int i = 1;i <= n;i++) {
        int max1 = a[i],min1 = a[i];
        for(int j = i+1;j <= n;j++) {
            max1 = max(max1,a[j]);
            min1 = min(min1,a[j]);
            ans = min(ans,max1-min1);
        }
    }
    cout << ans;
}

void sub3()
{
    int ans = 1e9;
    for(int i = 1;i <= n;i++) {
        ans = min(ans,abs(a[i]-a[i+1]));
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n <= 2000) sub12();
    else sub3();
    return 0;
}