#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll n,dem = 0;
vector<ll> a;
ll b[N],c[N];
ll tmp = 1e9+7;

void inkq()
{
    ll ans = 0;
    for(auto c: a) {
        ans = ans * 10 + c;
    }
    if(ans % 16 == 0) dem++;
}


void lietkehoanvi(ll k)
{
    if(k == 4)
    {
        inkq();
        return;
    } 
    for(int i = 1;i <= n;i++) {
        if(b[i] == 0) {
            b[i] = 1;
            a.push_back(i);
            lietkehoanvi(k+1);
            a.pop_back();
            b[i] = 0;
        }
    }
}


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
    cin >> n;
    lietkehoanvi(0);
    cout << dem % tmp;
    return 0;
}
