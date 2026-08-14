#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k = 1;
    for(int i = 1;i <= n;i++) {
        if(i % 2 == 1) {
            for(int j = 1;j <= n;j++) cout << (i-1)*n+j << ' ';
            cout << '\n';
        }
        else {
            for(int j = 1;j <= n;j++) cout << (i-1)*n+(n-j+1) << ' ';
            cout << '\n';
        }
    }
    return 0;
}