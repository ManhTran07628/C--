#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
stack<ll> t;

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
    string s;
    ll k;
    cin >> s >> k;
    string t;
    for(auto x:s) {
        while(k > 0 && t.size() > 0 && t.back() < x) {
            t.pop_back();k--;
        }
        t+=x;
    }
    while(k > 0) {
        t.pop_back();
        k--;
    }
    cout << t;
    return 0;
}