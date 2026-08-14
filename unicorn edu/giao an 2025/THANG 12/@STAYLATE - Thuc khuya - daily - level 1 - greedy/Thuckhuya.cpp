#include<bits/stdc++.h>
using namespace std;
struct work{
    int t,d;
};
work a[1010];
bool cmp(work x, work y)
{
    if (x.d > y.d) return 1;
    return 0;
}
int n;
int main()
{
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i].t >> a[i].d;
    }
    sort(a+1, a+1+n, cmp);
    for (int i=1; i<=n; i++){
              a[i+1].d = min (a[i].d - a[i].t, a[i+1].d);
    }
    cout << (a[n].d - a[n].t <= 0 ? -1 : a[n].d-a[n].t);
    return 0;
}