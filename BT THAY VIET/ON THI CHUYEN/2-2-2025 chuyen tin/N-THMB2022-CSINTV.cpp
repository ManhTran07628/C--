#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<pair<int,int>> a,t;
int f[N];
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.fi != b.fi) return a.fi > b.fi;
    return a.se < b.se; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int A,B;
        cin >> A >> B;
        a.push_back({A,B});
    }
    sort(a.begin(),a.end(),cmp);
    // for(pair<int,int> f: a) {
    //     cout << f.fi << ' ' << f.se << '\n';
    // }
    vector<int> f;
    for(int i = 0;i < n;i++) {
        int pos = upper_bound(f.begin(),f.end(),a[i].se) - f.begin();
        if(pos == f.size()) {
            f.push_back(a[i].se);
            t.push_back({a[i].fi,a[i].se});
        }
        else {
            f[pos] = a[i].se;
            t[pos].fi = a[i].fi;
            t[pos].se = a[i].se;
        }
    }
    cout << f.size() << '\n';
    reverse(t.begin(),t.end());
    for(auto i:t) {
        cout << i.fi << ' ' << i.se << '\n';
    }
    return 0;
}