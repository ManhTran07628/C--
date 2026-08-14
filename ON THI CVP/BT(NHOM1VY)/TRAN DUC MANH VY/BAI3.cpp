#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],l[MAXN],r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int dn = 0,vitri = 1;
    for(int i = 2;i <= n-1;i++) {
        if(a[i] > dn) {
            vitri = i;dn = a[i];
        }
    }
    int chiphi = 0;a[0] = -1;
    for(int i = 1;i < vitri;i++) {
        if(a[i-1] >= a[i]) {
            chiphi += a[i-1]-a[i]+1;a[i] = a[i-1]+1;
        }
    }
    a[n+1] = -1; 
    for(int i = n;i > vitri;i--) {
        if(a[i+1] >= a[i]) {
            chiphi += a[i+1]-a[i]+1; a[i] = a[i+1]+1;
        }
    }
    for(int i = 2;i <= (n)/2;i++) {
        if(a[i-1] >= a[i]) {
            chiphi += a[i-1]-a[i]+1;a[i] = a[i-1]+1;
        }
    }
    for(int i = (n)/2+1;i <= n-1;i++) {
        if(a[i+1] >= a[i]) {
            chiphi += a[i+1]-a[i]+1;a[i] = a[i+1]+1;
        }
    }
    cout << chiphi;
    return 0;
}