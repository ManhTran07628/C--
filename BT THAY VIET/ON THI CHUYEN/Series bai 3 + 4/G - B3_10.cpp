#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],b[N];

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
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int i = 1,j = 1,ans = 0;
    while(i <= n && j <= m) {
        if(b[j]-k <= a[i] && a[i] <= b[j]+k) {
            i++;j++;
            ans++;
        }
        else {
            if(a[i] < b[j]-k) i++;
            else j++;
        }
    }
    cout << ans;
    return 0;
}