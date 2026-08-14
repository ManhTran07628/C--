#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

int gt[N],ud[N],pick[N];
map<int,int> kt,f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "FOOD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int k,x,t;
    cin >> k;
    for(int i = 1;i <= k;i++) {
        cin >> gt[i];
    }
    cin >> x;
    for(int i = 1;i <= 4;i++) {
        cin >> ud[i];
        f[ud[i]]++;
    }
    cin >> t;
    int ans = 0;
    for(int i = 1;i <= t;i++) {
        cin >> pick[i];
        if(f[pick[i]]) kt[pick[i]]++;
        else ans += gt[pick[i]];
    }
    int phiud = 0;
    for(auto p:kt) {
        phiud += gt[p.fi];
    }
    if(x <= phiud) {
        int c = 0;
        while(kt.size() > 0) {
            int phiud = 0,mk = N;
            for(auto p:kt) {
                phiud += gt[p.fi];
                mk = min(p.se,mk);
            }
            if(phiud > x) ans += x*mk;
            else ans += phiud*mk;
            for(int i = 1;i <= 4;i++) {
                if(kt.find(ud[i]) == kt.end()) continue;
                kt[ud[i]] -= mk;
                if(kt[ud[i]] == 0) kt.erase(ud[i]);
            }
        }
    }
    cout << ans;
    return 0;
}