#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;

ll ktra(string s,string t,ll n)
{
    for(int i = 0;i < n;i++) {
        if(s[i] != t[i]) {
            a.push_back(i);
        }
    }
    if(a.size() != 2) return 0;
    swap(s[a[0]],t[a[1]]);
    if(s == t) {
        return 1;
    }
    swap(s[a[0]],t[a[1]]);
    swap(s[a[1]],t[a[0]]);
    if(s == t) {
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Manipstr"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        if(ktra(s,t,n)) {
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
        a.clear();
    }
    return 0;
}