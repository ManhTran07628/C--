#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+1;
ll a[N][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "NUMFILL"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a1,b,c,d,e,f,dem = 0;
    cin >> a1 >> b >> c >> d >> e >> f;
    ll kt = max({a1,b,c,d,e,f});
    for(int i = 1;i <= kt;i++) {
        for(int j = 1;j <= kt;j++) {
            for(int k = 1;k <= kt;k++) {
                for(int h = 1;h <= kt;h++) {
                    a[1][1] = i;
                    a[1][2] = j;
                    a[2][1] = k;
                    a[2][2] = h;
                    a[1][3] = a1- a[1][2] - a[1][1];
                    a[2][3] = b - a[2][2] - a[2][1];
                    a[3][1] = d - a[2][1] - a[1][1];
                    a[3][2] = e - a[2][2] - a[1][2];
                    a[3][3] = c - a[3][2] - a[3][1];
                    ll tmp = 0;
                    for(int I = 1;I <= 3;I++) {
                        for(int J = 1;J <= 3;J++) {
                            if(a[I][J] > 0) tmp++;
                        }
                    }
                    if(a[1][3] + a[2][3] + a[3][3] == f) {
                        if(tmp == 9) dem++;
                    }
                }
            }
        }
    }
    cout << dem;
    return 0;
}
