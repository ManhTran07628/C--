#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

bool prime_check(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++) 
        if(k % i == 0) return 0;
    return 1;
}


void checkpnt(ll n)
{
    ll check = 0,size_n = 0;
    ll n1 = n;
    while(n1 > 0) {
        size_n++;
        n1 /= 10;
    }

    while(n > 0) {
        if(!prime_check(n)) check++;
        n /= 10;
    }
    if(check == size_n) cout << 1;
    else cout << 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "pnt"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= 3;i++) {
        cin >> a[i];
        checkpnt(a[i]);
        cout << '\n';
    }
    return 0;
}