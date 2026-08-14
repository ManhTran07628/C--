#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<pair<int,int>,int> a[N];

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
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        cout << a[i].fi.fi << ' ' << a[i].fi.se << ' ' << a[i].se << '\n';
    }
    return 0;
}