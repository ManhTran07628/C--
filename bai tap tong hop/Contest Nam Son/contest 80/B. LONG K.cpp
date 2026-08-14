#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "LONGK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1;i <= MAXN;i++) {
        cnt += (d[i]-1)*d[i]/2;
    }
    for(int i = 1;i <= n;i++) {
        int p = d[a[i]]-1;
        cout << cnt-(d[a[i]]-1)*d[a[i]]/2+p*(p-1)/2 << '\n';
    }
    return 0;
}