#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PALINDROME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b;
    string k;
    cin >> k >> a >> b;
    ll min1 = min(a,b);
    map<char,ll> cp = {{'a',a},{'b',b}};
    ll dem = 0,n = k.size();
    for(int i = 0;i < n/2;i++) { 
        if(k[i] == '/' && k[n-i-1] == '/') {
            dem += 2*min1;
            continue;
        }
        if(k[i] != k[n-i-1]) {
            if(k[i] == '/' && k[n-i-1] != '/') {
                dem += cp[k[n-i-1]];
            }
            else if(k[i] != '/' && k[n-i-1] == '/') {
                dem += cp[k[i]];
            }
            else {
                cout << -1;
                return 0;
            }
        }
    }
    if (n % 2 == 1) {
        char mid = k[n / 2];
        if (mid == '/') {
            dem += min1;
        }
    }
    cout << dem;
    return 0;
}