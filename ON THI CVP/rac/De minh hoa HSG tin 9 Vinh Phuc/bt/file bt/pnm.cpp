#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a;
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
    string k;
    cin >> n >> k;
    for(int i = 0;k[i];i++) {
        if(k[i] >= 'A' && k[i] <= 'Z') {
            k[i] += 32;
        }
        a[k[i]]++;
    }
    for(char i = 'a';i <= 'z';i++) 
        if(a[i] == 0) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}