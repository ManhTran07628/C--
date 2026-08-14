#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CPHUONG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= 200;i++) {
        for(int i1 = 1;i1 <= 200;i1++) {
            for(int i2 = 1;i2 <= 200;i2++) {
                for(int i3 = 1;i3 <= 200;i3++) {
                    if(i*i+i1*i1+i2*i2+i3*i3 == n) {
                        cout << i << " "<< i1 << " " << i2 << " " << i3;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}