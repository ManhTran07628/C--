#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+1;
ll f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "gold"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll lq = 1;
    for(int i = 1;i <= n;i++) {
        ll tm = i;
        for(int j = 2;j <= sqrt(i);j++) {
            while(tm % j == 0) {
                f[j]++;
                tm /= j;
            }
        }
        if(tm > 1) f[tm]++;
    }
    f[2] -= f[5];
    f[5] = 0;
    for(int i=0;i<N;i++)
        if(f[i]>0)
            for(int manh=0;manh<f[i];manh++)
                lq=(lq*i)%10;
    cout << lq%10;
    return 0;
}