#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
const int MM = 1e8;
bool p[MM+7];
ll a[5000001],k = 0,i,j;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    p[1] = 1;
    for(i = 2;i <= MM;i++) {
        if(p[i] == 0) {
            a[++k] = i;
            if(k > 5e6) break;
            for(j = i;j <= MM/i;j++) 
                p[i*j] = 1;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }
    return 0;
}
