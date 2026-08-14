#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LG = 16;
int t,n,a[MM],lg2[MM];
int st[LG+1][MM];
void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}

void STbuild()
{
    for(int i = 1;i <= n;i++) {
        st[0][i] = a[i];
    }
    for(int j = 1;j <= LG;j++) {
        for(int i = 1;i+(1 << j)-1 <= n;i++) {
            st[j][i] = __gcd(st[j-1][i],st[j-1][i + (1 << (j-1)) ]);
        }
    }
}

int Get(int l,int r)
{
    int k = lg2[r-l+1];
    int answer = __gcd(st[k][l],st[k][r - (1 << k) + 1]);
    return answer;  
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    BuildLog2Arr();
    cin >> t;
    while(t--) {
        cin >> n;
        int t1 = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            t1 = max(t1,a[i]);
        }
        STbuild();
        // cout << t1 << ' ';
        for(int i = 1;i <= n;i++) {
            cout << Get(i,i) << ' ';
        }
        cout << '\n';
    }
    return 0;
}