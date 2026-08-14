#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    string s = "ROYGBIV";
    while(n >= 7) {
        cout << s;
        n-=7;
    }
    if(n == 6) {
        cout << "GBIVGB";
    }
    if(n == 5) {
        cout << "GBIVG";
    }
    if(n == 4) {
        cout << "GBIV";
    }
    if(n == 3) {
        cout << "GBI";
    }
    if(n == 2) {
        cout << "GB";
    }
    if(n == 1) {
        cout << "G";
    }
    return 0;
}