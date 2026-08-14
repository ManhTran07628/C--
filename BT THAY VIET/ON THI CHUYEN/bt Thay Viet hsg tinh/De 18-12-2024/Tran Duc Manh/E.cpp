#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
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
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll i = 1,j = 1,p1 = 1,p2 = n,cnt = 0;
    while(i <= n && j <= n) {
        b[a[j]]++;
        if(b[a[j]] == 1) cnt++;
        while(cnt == m) {
            if(p2 - p1 > j - i) {
                p1 = i;p2 = j;
            }
            b[a[i]]--;
            if(b[a[i]] == 0) cnt--;
            i++;
        }
        j++;
    }
    cout << p1 << " " << p2;
    return 0;
}