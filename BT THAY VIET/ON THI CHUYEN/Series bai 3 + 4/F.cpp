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
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = 1,ans = 0,d = 0;
    while(j <= n) {
        b[a[j]]++;
        if(b[a[j]] == 1) {
            d++;
        }
        while(d >= k) {
            ans += n - j  + 1;
            b[a[i]]--;
            if(b[a[i]] == 0) d--;
            i++;
        }
        j++;
    }
    cout << ans;
    return 0;
}