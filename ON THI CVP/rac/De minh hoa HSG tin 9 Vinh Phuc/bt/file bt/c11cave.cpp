#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pb pop_back
/* mang da la duoi
nhu da la tren
*/
const int N = 2e6 + 7;
ll a[N],mangda[N],nhuda[N],kq[N],demda = 0,demnhu = 0;
int main()
{
    ll n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        ll x;
        cin >> x;
        if(i % 2 != 0) {
            mangda[x]++;
        }
        else {
            nhuda[h-x+1]++;
        }
    }
    for(int i = h;i >= 1;i--) {
        mangda[i] += mangda[i+1];
    }
    for(int i = 1;i <= h;i++) {
        nhuda[i] += nhuda[i-1];
    }
    ll min1 = 1e9;
    for(int i = 1;i <= h;i++) {
        min1 = min(min1,nhuda[i]+mangda[i]);
    }
    cout << min1 << " ";
    ll d = 0;
    for(int i = 1;i <= h;i++) {
        if(min1 == nhuda[i] + mangda[i]) {
            d++;
        }
    }
    cout << d;
    return 0;
}

