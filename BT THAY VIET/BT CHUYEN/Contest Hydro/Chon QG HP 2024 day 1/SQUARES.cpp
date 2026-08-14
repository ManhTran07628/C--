#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
ll S;
void readinput()
{
    cin >> S;
}


namespace subtask12
{
    const int MS = 1e7+7;
    bool mp[MS];
    void solve()
    {
        int cnt = 0;
        for(int X1 = 1;X1*X1 <= S;X1++) { // hcn canh cheo
            for(int Y1 = 0;Y1*Y1 <= S;Y1++) {
                int dientich = (X1*X1+Y1*Y1);
                if(dientich <= S && !mp[dientich]) {
                    cnt++;
                    mp[dientich] = 1;
                }
            }
        }
        cout << cnt;
    }
}

namespace subtask3
{
    const int MS = 1e8+1;
    bool mp[MS];
    void solve()
    {
        int cnt = 0;
        for(int X1 = 1;X1*X1 <= S;X1++) { // hcn canh cheo
            for(int Y1 = 0;Y1*Y1 <= S;Y1++) {
                int dientich = (X1*X1+Y1*Y1);
                if(dientich <= S && !mp[dientich]) {
                    cnt++;
                    mp[dientich] = 1;
                }
            }
        }
        cout << cnt;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "SQUARES"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    readinput();
    if(S <= 10000000) subtask12::solve();
    else subtask3::solve();
}