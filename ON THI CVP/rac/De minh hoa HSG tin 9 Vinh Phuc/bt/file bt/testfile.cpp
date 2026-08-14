#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

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
    string s;
    ll nb,ns,nc,pb,ps,pc,r;
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    ll mid = 1;
    ll nlb = 0,nls = 0,nlc = 0;

    for(int i = 0;i < s.size();i++) {
        if(s[i] == 'B') nlb++;
        if(s[i] == 'S') nls++;
        if(s[i] == 'C') nlc++;
    }
    //cout << nlb << " " << nls << " " << nlc;
    ll bld = 1e18;
    if(nlb > 0) bld = min(bld,nb / nlb);
    if(nls > 0) bld = min(bld,nb / nls);
    if(nlc > 0) bld = min(bld,nb / nlc);
    //cout << bld;
    nb = nb - nlb*bld;
    ns = ns - nls*bld;
    nc = nc - nlc*bld;
    //cout << nb << " " << ns << " " << nc;
    mid -= bld;
    //cout << mid;
    ll nbcan = mid * nlb - nb;
    ll nscan = mid * nls - ns;
    ll nccan = mid * nlc - nc;
    //cout << nbcan << " " << nscan << " " << nccan;
    ll tongtien = nbcan * pb + nscan * ps + nccan * pc;
     if(tongtien <= r) cout << 1;
     else cout << 0;
    return 0;
}
// 6 4 1
// 3 2 1 