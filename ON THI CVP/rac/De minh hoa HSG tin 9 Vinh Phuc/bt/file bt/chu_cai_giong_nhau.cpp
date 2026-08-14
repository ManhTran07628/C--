#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],lt = -1e9;

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
    string k;
    cin >> k;
    for(int i = 0;i <= k.size();i++) 
        a[k[i]-'0']++;
    char n;
    for(int i = 0;i <= k.size();i++) {
        if(a[k[i] - '0'] > lt || (a[k[i] - '0'] == lt && k[i] < n)) {
            lt = a[k[i] - '0'];
            n = k[i];
        }
    }
    for(int i = 0;i <= k.size();i++) {
        if(k[i] == n) cout << n;
    }
    return 0;
}