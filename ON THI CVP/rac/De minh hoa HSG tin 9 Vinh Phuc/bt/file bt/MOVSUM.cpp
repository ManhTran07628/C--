#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],l[N],r1[N],s[N];

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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= k;i++) {
        cin >> s[i];
    }
    fill(l, l + n + 1, -1e15);
    l[1] = a[1];
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i - s[j] >= 1 && a[i] + l[i-s[j]] > l[i]) 
                l[i] = l[i-s[j]] + a[i];
        }
        l[i] = max(l[i-1],l[i]);
    }
    fill(r1, r1 + n + 1, -1e15);
    r1[n] = a[n];
    for(int i = n-1;i >= 1;i--) {
        for(int j = 1;j <= k;j++) {
            if(i + s[j] <= n && r1[i] < r1[i+s[j]] + a[i]) 
                r1[i] = r1[i+s[j]] + a[i];
        }
        r1[i] = max(r1[i],r1[i+1]);
    }
    ll max1 = -1e15;
    for(int i = 1;i < n;i++) {
        max1 = max(max1,l[i]+r1[i+1]);
    }
    cout << max1;
    return 0;
}