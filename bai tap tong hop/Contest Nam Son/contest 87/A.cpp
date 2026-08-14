#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;
vector<int> vt;
void backtracking(int length,int s,int ok)
{
    if(ok < 0 || ok > n/2) return;
    if(length == n) {
        if(ok == 0) vt.push_back(s);
        return;
    }
    backtracking(length+1,s*2,ok+1);
    backtracking(length+1,s*2+1,ok-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtracking(0,0,0);
    cout << vt.size() << '\n';
    for(auto i:vt) {
        for(int j = n-1;j >= 0;j--) {
            int d = i >> j;
            if(d % 2 == 0) cout << '(';
            else cout << ')';
        }
        cout << '\n';
    }
    return 0;
}   