#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;
ll b[N];
ll n;
void inkq()
{
    for(auto c:a) cout << c << " ";
    cout << '\n';
}


void lietkehoanvi(ll tong)
{
    ll ans = 0;
    if(!a.empty()) ans = a.back();
    if(tong > n) return;
    if(tong == n)
    {
        inkq();
        return;
    } 
    for(int i = ans+1;i <= n;i++) {
        if(b[i] == 0) {
            b[i] = 1;
            a.push_back(i);
            lietkehoanvi(tong+i);
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
    return 0;
}