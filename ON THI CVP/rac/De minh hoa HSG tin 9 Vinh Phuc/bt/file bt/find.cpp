#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "find"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m;
    cin >> m;
    if(m == 0) {
        cout << 10;
        return 0;
    }
    if(m == 1) {
        cout << 1;
        return 0;
    }
    for(int i = 9;i >= 2;i--) {
        while(m % i == 0) {
            a.push_back(i);
            m /= i;
        }
    }
    if(m > 1) {
        cout << -1;
        return 0;
    }
    sort(a.begin(),a.end());
    ll kq = 0;
    for(auto c:a) {
        kq = kq * 10 + c;
    }
    cout << kq;
    return 0;
}