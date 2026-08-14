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
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = n,ans = 0;
    while(i < j) {
        if(a[i] + a[j] == x) {
            ans++;
            i++;
            j--;
        }
        else if(a[i] + a[j] > x) j--;
        else i++;
    }
    cout << ans;
    return 0;
}