#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+5000;
ll a[N],p[N];
vector<ll> v;
ll n;
void sub1()
{
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i == 1) v.pop_back();
            if(n / i != i) v.push_back(n/i);
        }
    }
    for(auto i:v) {
        for(int j = i;j < n;j+=i) {
            a[j] = 1;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ntcn"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    ll cnt = 0;
    sub1();
    for(int i = 1;i < n;i++) {
        if(a[i] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}