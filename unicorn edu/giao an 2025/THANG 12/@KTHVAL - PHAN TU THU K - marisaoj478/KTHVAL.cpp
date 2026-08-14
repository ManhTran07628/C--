#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pp pop_back
typedef map<int,int> se;
const int N = 1e6 + 7;
ll b[N],c[N];
ll n,m,v,ln = -1e9 + 1,vt1,vt2,q,k1 = 1,k2 = 2,k3 = 3;
ll a[N],k[N];
vector <ll> u;
int main() {
    cin >> n >> q;
    for(int i = 0;i < n;i++) {
        ll a1;
        cin >> a1;
        u.push_back(a1);
    }
    for(ll i = 0;i < q;i++) {
        ll a1,a2;
        cin >> a1;
        if(a1 == k1) {
            cin >> a2;
            u.pb(a2);
        }
        else if (a1 == k2) {
            if(!u.empty()) {
                u.pop_back();
            }
        } else if (a1 == k3) {
            cin >> a2;
            if (!u.empty() && a2 <= u.size() && a2 > 0) 
                cout << u[a2-1] << endl;
        }
    }
    return 0;
}