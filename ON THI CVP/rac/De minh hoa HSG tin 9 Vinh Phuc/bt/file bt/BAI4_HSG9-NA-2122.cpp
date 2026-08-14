#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll vt[N];

struct host
{
    int a,b;
    bool operator<(const host &other)
    const
    {
        if(a == other.a) return other.b < b;
        return a < other.a;
    }
};
vector<host> mang;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHONSACH"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        ll a1,a2;
        cin >> a1 >> a2;
        mang.push_back({a1,a2});
    }
    ll dem = 0;
    sort(mang.begin(),mang.end());
    for(int i = 0;i < n;i++) {
        ll ans = lower_bound(vt,vt+dem+1,mang[i].b)-vt;
        if(ans == dem+1) {
            dem++;
        }
        vt[ans] = mang[i].b;
    }
    cout << dem;
    return 0;
}

