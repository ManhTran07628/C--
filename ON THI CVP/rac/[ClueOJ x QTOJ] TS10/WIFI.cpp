#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int n,k;

bool check(int d)
{
    int r = d-a[1];
    int vitri = d,cnt = 1,i = 1;
    while(i <= n) {
        if(a[i] >= vitri-r && a[i] <= vitri+r) i++;
        else {
            vitri=a[i]+r;
            cnt++;
        }
        if(cnt > k) return 0;
    }
    if(cnt <= k) return 1;
    return 0;
}
void vitri(int d)
{
    int r = d-a[1];
    cout << r << '\n';
    int vitri = d,cnt = 1,i = 1;
    cout << vitri << ' ';
    while(i <= n) {
        if(a[i] >= vitri-r && a[i] <= vitri+r) i++;
        else {
            vitri=a[i]+r;
            cnt++;
            cout << vitri << ' ';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "wifi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int l = 1,r = 1e9,ans = n;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    vitri(ans);
    return 0;
}
