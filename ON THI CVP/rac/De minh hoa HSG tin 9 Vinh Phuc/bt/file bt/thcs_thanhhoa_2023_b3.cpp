#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],uoc3so[N];

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
    ll a1,b;
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[1]=a[0]=0;
    for(int i = 1;i <= sqrt(N);i++)
        if(a[i])
            for(ll j = i*i;j <= N;j+=i) 
                a[j] = 0;
    //215
    for(ll i = 2;i <= 215;i++) {
        for(ll j = i+1;j <= 215;j++) {
            for(ll k = j+1;k <= 215;k++) {
                if(a[i] == 1 && a[j] == 1 && a[k] == 1) {
                    uoc3so[i*j*k] = 1;
                }
            }
        }
    }
    for(int i = 1;i <= 88;i++) {
        cout << uoc3so[i] << " ";
    }
    return 0;
}