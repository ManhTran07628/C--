#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

bool isprime(int k)
{
    if(k < 2) return 0;
    for(int i = 2;i*i <= k;i++) 
        if(k%i==0) return 0;
    return 1;
}

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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i = a;i <= b;i++) {
        int kt = 1;
        for(int j = c;j <= d;j++) {
            cout << i << ' ' << j << ' ' << (isprime(i+j) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}