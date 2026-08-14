#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+7;
ll w[N];
ll n;
string ans = "0";

string bignums(string a,string b) 
{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) {
            a = '0' + a;
        }
        else if(a.size() > b.size()) {
            b = '0' + b;
        }
    }
    ll nho = 0;
    string ab; 
    for(int i = a.size()-1;i >= 0;i--) {
        ll tmp = (a[i]-'0')+(b[i]-'0')+nho;
        ab += (tmp%10+'0');
        nho = tmp / 10;
    }
    if(nho > 0) {
        ab += '1';
    }
    reverse(ab.begin(),ab.end());
    return ab;
}

void xnp(ll a)
{
    string k;
    while(a > 0) {
        k += (a%2+'0');
        a /= 2;
    }
    //reverse(k.begin(),k.end());
    for(int i = 0;i < k.size();i++) {
        if(k[i] == '1') {
            string a1 = to_string(w[i]);
            string tmp = bignums(a1,ans);
            ans = tmp;
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
    for(int i = 0;i < n;i++) {
        cin >> w[i];
    }
    ll k;
    cin >> k;
    ll m = pow(2,n);
    if(k > m) {
        cout << -1;
        return 0;
    }
    xnp(k-1);
    cout << ans;
    return 0;
}