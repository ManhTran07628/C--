#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "RAB"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        string s;
        cin >> n >> k >> s;
        ll sla = 0,slb = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == 'a') sla++;
            else if(s[i] == 'b') {
                slb += sla;
            }
        }
        cout << slb + slb * k << '\n';
    }
    return 0;
}
