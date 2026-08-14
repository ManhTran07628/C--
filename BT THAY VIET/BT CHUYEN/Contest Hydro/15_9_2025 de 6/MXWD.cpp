#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 4000+7;
int n,m,a[MM][MM],r,s;

void readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    cin >> r >> s;
}

namespace subtask2
{
    void solve()
    {
        for(int X = 1;X+r-1 <= n;X++) {
            for(int Y = 1;Y+s-1 <= m;Y++) {
                int U = X+r-1, V = Y+s-1;
    
                int maxn = -oo;
                for(int i = X;i <= U;i++) {
                    for(int j = Y;j <= V;j++) {
                        maxn = max(maxn,a[i][j]);
                    }
                }

                cout << maxn << ' ';
            }
            cout << '\n';
        }
    }
}


namespace subtask4
{
    int Ma[MM][MM],MaxSP[MM][MM];
    deque<int> dq;
    void buildRow(int row)
    {   
        dq.clear();
        for(int i = 1;i <= m;i++) {
            while(!dq.empty() && dq.front()+s-1 < i) dq.pop_front();
            while(!dq.empty() && a[row][dq.back()] < a[row][i]) dq.pop_back();
            dq.push_back(i);
            if(i >= s) {
                Ma[row][i-s+1] = a[row][dq.front()];
            }
        }
    }

    void buildCol(int col)
    {
        dq.clear();
        for(int i = 1;i <= n;i++) {
            while(!dq.empty() && dq.front()+r-1 < i) dq.pop_front();
            while(!dq.empty() && Ma[dq.back()][col] < Ma[i][col]) dq.pop_back();
            dq.push_back(i);
            if(i >= r) {
                MaxSP[i-r+1][col] = Ma[dq.front()][col];
            }
        }
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            buildRow(i);
        }
        for(int i = 1;i <= m;i++) {
            buildCol(i);
        }
        for(int i = 1;i+r-1 <= n;i++) {
            for(int j = 1;j+s-1 <= m;j++) {
                cout << MaxSP[i][j] << ' ';
            }
            cout << '\n';
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask4::solve();
    return 0;   
}