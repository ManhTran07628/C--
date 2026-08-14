#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p,q,a,b;
    cin >> p >> q >> a >> b;
    if(q < p) {
        cout << q*a;
    }
    else cout << p*a+(q-p)*b;
    return 0;   
}