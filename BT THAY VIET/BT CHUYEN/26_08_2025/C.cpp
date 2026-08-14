#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 100;
int m,n,P[MM][MM],T[MM][MM],Q[MM][MM];
string s;

void init()
{
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> P[i][j];
            Q[i][j] = P[i][j];
        }
    }
    cin >> s;
}

namespace subtask1
{

    void applyA(int a[][MM])
    {
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= m;i++) {
                b[i][j] = a[i][j];
            }
        }
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= m;i++) {
                a[j][m-1-i] = b[i][j];
            }
        }
    }


    void solve()
    {
        // for(int i = 0;i < s.size;i++) 
        // {
        //     if(s[i] == 'X') s[i] = 'C';
        //     if(s[i] == 'Y') s[i] = 'B';
        //     if(s[i] == 'Z') s[i] = 'A';
        // }
        
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                cout << P[i][j] << ' ';
            }
            cout << '\n';
        }
        
        applyA(Q,Q);
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= m;i++) {
                cout << Q[i][j] << ' ';
            }
            cout << '\n';
        }   
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> m;
    subtask1::solve();
    return 0;
}