#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 2e9
const int MM = 1e3 + 7;
int num_row,num_col,k,a[MM][MM],vmax[MM][MM],vmin[MM][MM];
int b[MM][MM],c[MM][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> num_row >> num_col >> k;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) 
            cin >> a[i][j];

    for(int row = 1;row <= num_row;row++) {

        deque<int> dqmax,dqmin;

        for(int i = 1;i <= num_col;i++) {
            while(!dqmax.empty() && i - k >= dqmax.front()) dqmax.pop_front();
            while(!dqmin.empty() && i - k >= dqmin.front()) dqmin.pop_front();

            while(!dqmax.empty() && a[row][dqmax.back()] < a[row][i]) dqmax.pop_back();
            while(!dqmin.empty() && a[row][dqmin.back()] > a[row][i]) dqmin.pop_back();

            dqmax.push_back(i);
            dqmin.push_back(i);

            if(i >= k) {
                vmax[row][i - k + 1] = a[row][dqmax.front()];
                vmin[row][i - k + 1] = a[row][dqmin.front()];
                // cout << vmin[row][i - k + 1] << ' ';
            }
        }

        // cout << '\n';

    }

    for(int col = 1;col <= num_col - k + 1;col++) {

        deque<int> dqmax,dqmin;

        for(int i = 1;i <= num_row;i++) {
            while(!dqmax.empty() && i - k >= dqmax.front()) dqmax.pop_front();
            while(!dqmin.empty() && i - k >= dqmin.front()) dqmin.pop_front();

            while(!dqmax.empty() && vmax[dqmax.back()][col] < vmax[i][col]) dqmax.pop_back();
            while(!dqmin.empty() && vmin[dqmin.back()][col] > vmin[i][col]) dqmin.pop_back();

            dqmax.push_back(i);
            dqmin.push_back(i);

            if(i >= k) {
                b[i - k + 1][col] = vmax[dqmax.front()][col];
                c[i - k + 1][col] = vmin[dqmin.front()][col];
                // cout << row << ' ' << i << ' ' << b[row][i - k + 1] << '\n';
                // cout << c[i - k + 1][col] << ' ';
            }
        }
        
        // cout << '\n';

    }

    int res = oo;
    for(int i = 1;i + k - 1 <= num_row;i++)
        for(int j = 1;j + k - 1 <= num_col;j++) {
            res = min(res,b[i][j] - c[i][j]);
        }

    cout << res;
    return 0;
}