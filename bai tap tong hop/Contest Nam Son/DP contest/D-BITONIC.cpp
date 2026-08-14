#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
pair<int,int> l[N],r[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BITONIC"
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
    for(int i = 1;i <= n;i++) {
        l[i].fi = 1;
        l[i].se = a[i];
        for(int j = 1;j < i;j++) {
            if(a[i] > a[j]) {
                l[i].fi = max(l[i].fi,l[j].fi+1);
                l[i].se = max(l[i].se,l[j].se+a[i]);
            }
        }
    }
    for(int i = n;i >= 1;i--) {
        r[i].fi = 1;
        r[i].se = a[i];
        for(int j = n;j > i;j--) {
            if(a[i] > a[j]) {
                r[i].fi = max(r[i].fi,r[j].fi+1);
                r[i].se = max(r[i].se,r[j].se+a[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(l[i].fi + r[i].fi - 1 >= 3) {
            ans = max(ans,l[i].se + r[i].se - a[i]);
        }
    }
    cout << ans;
    return 0;
}