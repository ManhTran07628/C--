#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    cin >> n;
    string s,k;
    cin >> s;
    if(n % 2 == 0) {
        for(int i = n-2;i >= 0;i-=2)  k += s[i];
        for(int i = 1;i < n;i+=2)  k += s[i];
    }
    else if(n % 2 == 1){
        for(int i = n-1;i >= 1;i-=2) k += s[i-1];
        for(int i = 1;i <= n;i+=2) k += s[i-1];
    }
    cout << k;
    return 0;
}