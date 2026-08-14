#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
vector<int> b;
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
    ll cnt = 0;
    int i = 1;
    while(i < n) {
        int crr = i;
        for(int j = k;j >= 1;j--) {
            if(a[i+j] && i + j <= n) {
                i += j;
                break;
            }
        }
        if(crr == i) {
            cout << -1;
            return 0;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}