#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;
ll n,dem = 0;


void xep_hang(ll k)
{
    if(k >= 3 && a[k-1] == 1 && a[k-2] == 1 && a[k-3] == 1) {
        return;
    }
    if(k == n) {
        dem++;
        return;
    }
    for(int i = 0;i <= 1;i++) {
        a.push_back(i);
        xep_hang(k+1);
        a.pop_back();
    }
}


// 0 nu 1 nam
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BAI3"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    xep_hang(0);
    cout << dem;
    return 0;
}