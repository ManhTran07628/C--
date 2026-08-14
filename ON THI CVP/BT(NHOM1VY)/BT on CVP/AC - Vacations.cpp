#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],f[101][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) { //1 tap - 2 thi
        cin >> a[i];
    
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] == 3) continue;
        if(a[i] == 0) ans++;
        if(a[i] == 2 && a[i+1] == 3) a[i+1] = 1;
        
        if(a[i] == 1 && a[i+1] == 3) a[i+1] = 2;
        if(a[i] == 2 && a[i+1] == 2) a[i+1] = 0;
        if(a[i] == 1 && a[i+1] == 1) a[i+1] = 0;
    }
    cout << ans;
    return 0;
}