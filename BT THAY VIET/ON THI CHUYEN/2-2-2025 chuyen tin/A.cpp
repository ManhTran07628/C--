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
    int n,t;
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        a[i] = a[n+i] = i;
    }
    int j = t%(n+1);
    for(int i = (n+n-j)-n+1;i <= n+n-j;i++) cout << a[i] << ' ';
    return 0;
}