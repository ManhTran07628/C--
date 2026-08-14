#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
map<int,int> lt;
int n;
bool check(ll k)
{
    int i = 1,pos = 1,ktr = 1;
    while(i <= n) {
        int kt = k;
        if(a[i] >= pos) {
            while(kt > 0 && i <= n) {
                i++;kt--;
            }
        }
        else {
            ktr = 0;
            break;
        }
        pos++;
    }
    if(ktr) return 1;
    else return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll l = 1,r = n,ans = n;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;   
}