#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int scs(int k)
{
    int cnt = 0;
    while(k > 0) {
        cnt++;
        k/=10;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    ll gtri,n1 = n;
    if(n > 18) {
        gtri = 1e9;
        n-=9;
    }
    else {
        gtri = pow(10,n-1);
        n = 0;
    }
    gtri = gtri / k * k;
    string s = to_string(gtri);
    if(n > 0) {
        while(n > 1) {
            s = '0' + s;
            n--;
        }
        s = '1' + s;
    }
    cout << s;
    return 0;
}