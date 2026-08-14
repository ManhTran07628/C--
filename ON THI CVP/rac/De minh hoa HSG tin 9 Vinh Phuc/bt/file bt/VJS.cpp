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
    ll n,d;
    cin >> n >> d;
    string s;
    cin >> s;
    ll dem = 0;
    for(int i = 0;i < n;) {
        ll vt = -1;
        for(int j = 1;j <= d && i + j < s.size();j++) {
            if(s[i+j] == '1' || i+j == s.size()) {
                vt = i+j;
            }
        }
        if(vt == -1){
            cout << -1;
            return 0;
        }
        i = vt;
        dem++;
        if(i == n-1) break;
    }
    cout << dem;
    return 0;
}