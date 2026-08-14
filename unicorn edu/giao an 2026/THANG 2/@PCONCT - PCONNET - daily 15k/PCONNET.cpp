#include<bits/stdc++.h>
using namespace std;
const int P=2*1e5+10;
deque <int> t,d;
struct work{
    char c;
    int x;
    int v;
};
int n ;
work a[P];
char c[P];
int b[P];
bool cmp(work e, work h)
{
    if (e.x < h.x) return 1;
    return 0;
}
void show()
{
    for (int i=1; i<=2*n; i++)
        cout << a[i].c << " " << a[i].x << " " << a[i].v <<"\n";
}
int main()
{
    cin >> n;
    for (int i=1; i<=2*n; i++){
        cin >> a[i].c >> a[i].x;
        a[i].v = i;
        b[i] = a[i].x;
    }
    sort(a+1, a+1+2*n, cmp);
     for (int i=1; i<=2*n; i++){
        if (a[i].c == 'B') t.push_back(a[i].v);
        else d.push_back(a[i].v);
    }
    long long ans = 0;
    for (int i=0; i<n; i++){
        ans += max(b[t[i]],b[d[i]]) - min(b[t[i]],b[d[i]]);
    }
    cout << ans << "\n";
    for (int i=0; i<n; i++)
        cout << t[i] << " " << d[i] << "\n";
    return 0;
}