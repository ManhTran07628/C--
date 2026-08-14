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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll max1 = 1,crr = a[1],cnt = 1;
    for(int i = 2;i <= n;i++) {
        if(a[i] >= crr) 
            cnt++;
        else cnt = 1;
        crr = a[i];
        max1 = max(max1,cnt);
    }
    max1 = max(max1,cnt);
    cout << max1;
    return 0;       
}