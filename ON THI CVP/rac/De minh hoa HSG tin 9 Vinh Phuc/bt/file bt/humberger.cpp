#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
string s;
ll nb,ns,nc,pb,ps,pc,r;
ll nlb = 0,nls = 0,nlc = 0;
bool check(ll mid) {
    ll tr = r;
    if(nlb > 0) {
        if((nlb*mid-nb)*pb > 0)
            tr = tr - (nlb*mid-nb)*pb;
        if(tr < 0) return 0;
    }
    if(nls > 0) {
        if((nls*mid-ns)*ps > 0)
            tr = tr - (nls*mid-ns)*ps;
        if(tr < 0) return 0;
    }
    if(nlc > 0) {
        if((nlc*mid-nc)*pc > 0)
            tr = tr - (nlc*mid-nc)*pc;
        if(tr < 0) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "humberger"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;


    for(int i = 0;i < s.size();i++) {
        if(s[i] == 'B') nlb++;
        if(s[i] == 'S') nls++;
        if(s[i] == 'C') nlc++;
    }
    //cout << nlb << " " << nls << " " << nlc;
    ll L = 0,R = 1e15,kt = 0;
    while(L <= R) {
        ll mid = (L+R)/2;
        if(check(mid)) {
            kt = mid;
            L = mid + 1;
        }
        else R = mid - 1;
        //cout << mid << " ";
    }
    cout << kt;
    return 0;
}