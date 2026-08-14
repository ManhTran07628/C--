#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+10;
long long a[N], s[N];
int n,q;
int vt(long long key, int l, int r)
{
   while (l +1 < r){
    int mid = (l+r)/2;
    if (a[mid] + key > 0 ) r = mid -1;
    else l = mid;
   }
   if (a[r] + key <= 0) return r;
   else return l;
}
int main()
{
    ios_base :: sync_with_stdio(0);
        cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    s[0] = 0;
    long long k = 0;
    for (int i=1; i<=n; i++){
      s[i] = s[i-1] + a[i];
    }
    a[0] = -1e14;
    for (int i=1; i<=q; i++){
        long long x;
        cin >> x;
        k += x;
        int pos = vt(k, 0, n);
        cout << abs(s[pos] - s[0] + k*pos) + abs(s[n] - s[pos] + k*(n-pos)) << '\n';
    }
    return 0;
}