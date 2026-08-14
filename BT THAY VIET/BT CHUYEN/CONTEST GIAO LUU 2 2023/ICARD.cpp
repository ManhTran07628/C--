#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,ll>
const int MM = 2e5+7;
int n,m;
struct A{int id;ll val;} a[MM];
struct B{int id;ll cnt,val;} b[MM];
ll ps[MM],mp[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "ICARD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    vector<int> v;

    for(int i = 1;i <= n;i++) {
        cin >> a[i].val;
        v.push_back(a[i].val);
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i].cnt >> b[i].val;
        v.push_back(b[i].val);
    }
    sort(v.begin(),v.end());
    for(int i = 1;i <= n;i++) {
        a[i].id = lower_bound(v.begin(),v.end(),a[i].val) - v.begin() + 1;
        mp[ a[i].id ]++;
    }
    for(int i = 1;i <= m;i++)
        b[i].id = lower_bound(v.begin(),v.end(),b[i].val) - v.begin() + 1;

    sort(a+1,a+n+1,[] (A a,A b){
        return a.id < b.id;
    });
    sort(b+1,b+m+1,[] (B a,B b){
        return a.id > b.id;
    });
    // for(int i = 1;i <= n;i++) cout << a[i].val << ' ';
    // int lim = v.size();
    // for(int i = 1;i <= lim;i++) {
    //     ps[i] = ps[i-1] + mp[i];
    // }
    // for(int i = 1;i <= lim;i++) cout << i << ' ' << ps[i] << '\n';
    ll res = 0;
    for(int i = 1,j = 1;j <= m;j++) {
        while(i <= n && a[i].val < b[j].val && b[j].cnt > 0) {
            if(a[i].val < b[j].val) {
                a[i].val = b[j].val;
                b[j].cnt--;
                i++;
            }
        }
    }
    for(int i = 1;i <= n;i++) res += a[i].val;
    // for(int i = 1;i <= m;i++) {
    //     cout << b[i].id << ' ' << b[i].cnt << ' ' << b[i].val << '\n';
    //     if()
    // }
    cout << res;
    return 0;
}