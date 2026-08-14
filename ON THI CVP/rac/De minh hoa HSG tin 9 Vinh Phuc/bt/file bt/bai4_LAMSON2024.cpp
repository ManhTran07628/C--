#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll m;
    cin >> s >> m;
    ll n = s.size();
    for(int i = 0;i < m;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < m;i++) {
        string tmp = s.substr(n-a[i],a[i]-1);
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        cout << s << '\n';
        // string k = s.substr(0,n-a[i]) + tmp + s.substr(a[i]);
        // s = k;
    }
    //cout << s;
    return 0;
}