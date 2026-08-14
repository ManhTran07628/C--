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
    ll a,b;
    cin >> a >> b;
    ll a1 = a,b1 = b;
    if(a % 2 == 1) a++;
    if(b % 2 == 1) b--;
    if(a1 % 2 == 0) a1++;
    if(b1 % 2 == 0) b1--;
    ll sochan = ((b-a)/2+1);
    ll sole = (b1-a1)/2+1;
    if(sochan % 2 == 1) sochan--;
    if(sole % 2 == 1) sole--;
    cout << sochan + sole;
    return 0;
}