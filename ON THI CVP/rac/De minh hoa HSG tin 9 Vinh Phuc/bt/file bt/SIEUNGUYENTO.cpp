#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

bool ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int i=  2;i <= sqrt(k);i++) 
        if(k%i==0) return 0;
    return 1;
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
    ll n;
    cin >> n;
    ll n1 = n;
    ll ssh = 0;
    while(n1 > 0) {
        ssh++;
        n1/=10;
    }
    while(n > 0) {
        if(ktsnt(n) == 0) {
            cout << "NO";
            return 0;
        }
        ll tmp = pow(10,ssh);
        n = n % tmp;
        ssh--;
    }
    cout << "YES";
    return 0;
}