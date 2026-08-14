#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[101][101];

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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    int i = 1,j = 1,x1 = 0,x2 = 0;
    while(i <= n && j <= n) {
        x1 += a[i][j];
        i++;j++;
    }
    i = 1,j = n;
    while(i <= n && j >= 1) {
        x2 += a[i][j];
        i++;j--;
    }
    cout << x1 << '\n' << x2;
    return 0;
}