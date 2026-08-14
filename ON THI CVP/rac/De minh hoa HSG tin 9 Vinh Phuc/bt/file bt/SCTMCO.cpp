#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+2;
string a[N];
string bignum(string a,string b)
{
    while(a.size() != b.size()) {
            if(a.size() < b.size()) {
                a = '0' + b;
            }
            else b = '0' + b;
        }
    ll nho = 0;
    string kq = "";
    for(int j = a.size()-1;j >= 0;j--) {
        ll tmp = (a[j] - '0') + (b[j] - '0') + nho;
        kq += (tmp % 10 + '0');
        nho = tmp / 10;
    }
    if(nho > 0) {
        kq += '1';
    }
    reverse(kq.begin(),kq.end());
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SCTMCO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    a[2] = a[1] = "1";
    for(int i = 3;i <=500;i++) {
        a[i] = bignum(a[i-1],a[i-2]);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << a[n] << '\n';
    }
    return 0;
}