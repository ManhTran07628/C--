#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
map<char,ll> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "icpc"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    ll dem = 0,sl = 0;
    char p;
    while(true) {
        ll t;
        cin >> t;
        if(t != -1) {
            cin >> p >> s;
        }
        else break;
        if(s == "right") {
            a[p] += t;
            dem++;
            sl += a[p];
        }
        else if(s == "wrong") {
            a[p] += 20;
        }
    }
    cout << dem << " " << sl;
    return 0;
}