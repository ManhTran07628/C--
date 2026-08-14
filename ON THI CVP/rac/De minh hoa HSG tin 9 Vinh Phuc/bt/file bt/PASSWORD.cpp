#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "PASSWORD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    string k;
    cin >> n >> k;
    ll dem = 0,tmp = 0;
    if(n < 6) tmp = abs(n-6);
    for(int i = 0;k[i];i++) {
        if(isdigit(k[i])) {
            b[0] = 1;
        }
        if(k[i] >= 'a' && k[i] <= 'z') {
            b[1] = 1;
        }
        if(k[i] == '!' || k[i] == '@' || k[i] == '#' || k[i] == '$' || k[i] == '%' || k[i] == '^' ||
           k[i] == '&' || k[i] == '*' || k[i] == '(' || k[i] == ')' || k[i] == '-' || k[i] == '+') {
            b[3] = 1;
        }
        if(k[i] >= 'A' && k[i] <= 'Z') {
            b[2] = 1;
        }
    }
    for(int i = 0;i <= 3;i++) {
        if(b[i] != 1) dem++;
    }
    cout << max(tmp,dem);
    return 0;
}


