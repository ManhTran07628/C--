#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
vector<ll> year = {31,28,31,30,31,30,31,31,30,31,30,31};
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
    ll fd,isl;
    cin >> fd >> isl;
    for(int i = 0;i < 12;i++) {
        if(fd == 0) cout << 1 << " ";
        else cout << 0 << " ";
        if(i == 1 && isl == 1) {
            fd = (fd+year[i]+1)%7;
        }
        else fd = (fd+year[i])%7;
        //cout << fd << " ";
    }
    return 0;
}