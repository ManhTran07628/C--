#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "marbles"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    while(q--) {
        int l,r;
        cin >> l >> r;
        int vtd = lower_bound(a+1,a+n+1,l) - a;
        int vtc = upper_bound(a+1,a+n+1,r) - a;
        cout << vtc - vtd << '\n';
    }
    return 0;
}