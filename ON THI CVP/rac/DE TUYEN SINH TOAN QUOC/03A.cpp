#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<ll,ll> x[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i <= 3;i++) {
        cin >> x[i].fi >> x[i].se;
    }
    sort(x+1,x+4);
    ll d1 = x[1].se-x[1].fi;
    ll d2 = x[2].se-x[2].fi;
    ll d3 = x[3].se-x[3].fi;
    cout << d1 << ' ' << d2 << ' ' << d3 << '\n';
    
    if(d1*d1+d2*d2==d3*d3) cout <<  "TAM GIAC VUONG";
    else cout << "KHONG PHAI TAM GIAC VUONG";
    return 0;
}