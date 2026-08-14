#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],b[N];

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
    int n,p,q;
    cin >> n >> p >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    if(b[n] != p+q) {
        cout << -1;
        return 0;
    }
    int p = lower_bound(b+1,b+n+1,p+q-a[1]);
    if(b[p] == p + q) {
        
    }
    return 0;
}