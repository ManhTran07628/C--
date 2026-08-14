#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],b[N];
vector<pair<int,int>> f;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int pos = -1,cnt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) {
        int l = i;
        while(a[i] != b[i] && i <= n) i++;
        cout << l << ' ' << i << '\n';
        if(l != i) {
            cnt++;
            f.push_back({l,i-1});
        }
        if(cnt > 1) {
            cout << "no";
            return 0;
        }
    }
    reverse(a+f[0].fi,a+f[0].se+1);
    for(int i = 1;i <= n;i++) {
        if(a[i] != b[i]) {
           // cout << "no";
            //return 0;
        }
        cout << a[i] << ' ' << b[i] << '\n';
    }
    cout << "yes" << ' ' << '\n' << f[0].fi << ' ' << f[0].se;
    return 0;
}