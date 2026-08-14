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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        ll dem = 0;
        for(int i = 0;i < n;i++) {
            if(s2[i] == '1' && s1[i] == '0') dem++;
            else if(s1[i-1] == '1' && s2[i] == '1') {
                dem++;
                s1[i-1] = '2';
            }
            else if(s1[i+1] == '1' && s2[i] == '1') {
                dem++;
                s1[i+1] = '2';
            }
        }
        cout << dem << '\n';
    }
    return 0;
}