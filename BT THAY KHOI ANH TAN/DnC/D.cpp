#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,a[MM],Left[MM],Right[MM],laspos[MM];


bool dnc(int L,int R)
{
    if(L > R) return 1;
    if(L == R) return 1;

    int pos = -1;
    for(int i = L,j = R;i <= j;) {
        if(Left[i] < L && R < Right[i]) {
            pos = i;
            break;
        }
        if(Left[j] < L && R < Right[j]) {
            pos = j;
            break;
        }
        i++;
        j--;
    }

    if(pos != -1) {
        bool ok = (dnc(L,pos - 1) && dnc(pos + 1,R));
        return ok;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        Left[i] = laspos[ a[i] ];
        laspos[ a[i] ] = max(laspos[ a[i] ],i);
    }
    for(int i = 1;i <= n;i++) laspos[ a[i] ] = n + 1;
    for(int i = n;i >= 1;i--) {
        Right[i] = laspos[ a[i] ];
        laspos[ a[i] ] = min(laspos[ a[i] ],i);
    }

    // for(int i = 1;i <= n;i++) cout << Left[i] << ' '; cout << '\n';
    // for(int i = 1;i <= n;i++) cout << Right[i] << ' ';

    cout << (dnc(1,n) ? "YES" : "NO");
    return 0;
}