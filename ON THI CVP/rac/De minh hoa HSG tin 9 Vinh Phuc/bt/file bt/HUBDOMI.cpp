#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+1;
vector<ll> a;
ll c[N];
ll n,dem = 0;

void inkq() 
{
    for(auto k:a) {
        dem += k;
    }
}

void bt(ll k,ll j)
{
    if(k == 2) {
        inkq();
        return;
    }
    for(int i = j;i <= n;i++) {
        if(c[i] == 0) {
            c[i] == 1;
            a.push_back(i);
            bt(k+1,j+1);
            a.pop_back();
            c[i] = 0;
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
    bt(0,0);
    cout << dem/2;
    return 0;
}