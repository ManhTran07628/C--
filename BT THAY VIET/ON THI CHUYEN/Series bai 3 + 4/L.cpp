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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> k;
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
    }
    cin >> n;
    sort(a+1,a+k+1);
    while(n--) {
        int x;
        cin >> x;
        int p = upper_bound(a+1,a+k+1,x) - a - 1;
        cout << x - p << '\n';
    }
    return 0;
}