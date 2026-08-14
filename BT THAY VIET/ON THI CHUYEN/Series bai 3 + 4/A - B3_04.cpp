#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "div7"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].fi = (a[i-1].fi + a[i].fi) % 7;
        a[i].se = i;
    }
    int ans = 0;
    sort(a+1,a+n+1);
    int i = 1,j = 1;
    while(i <= n && j <= n) {
        if(a[i].fi == a[j].fi) {
            ans = max(ans,a[j].se - a[i].se);
            j++;
        }
        else i++;
    }
    cout << ans;
    return 0;
}