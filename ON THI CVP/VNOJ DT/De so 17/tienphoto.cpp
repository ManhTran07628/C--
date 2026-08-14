#include <bits/stdc++.h>
using namespace std;
#define ll long long
//const int N = 1e6+7;
//ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tienphoto"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ",out","w",stdout);
    }
    ll L,M,N;
    cin >> L >> M >> N;
    ll ans = 0;
    if(L == 3) {
        if(M == 1) {
            if(N < 100) 
                ans = 600 * N;
            else if(N >= 100) 
                ans = 500 * N;
        }
        else if(M == 2) {
            if(N < 100) 
                ans = 800 * N;
            else if(N >= 100)
                ans = 700 * N;
        }
    }
    else if(L == 4) {
        if(M == 1) {
            if(N < 100) 
                ans = 300 * N;
            else if(N >= 100) 
                ans = 250 * N;
        }
        else if(M == 2) {
            if(N < 100) 
                ans = 400 * N;
            else if(N >= 100)
                ans = 350 * N;
        }
    }
    cout << ans;
    return 0;
}