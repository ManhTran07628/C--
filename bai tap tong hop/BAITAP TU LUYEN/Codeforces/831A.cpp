#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e3+7;
int n;
vector<int> a;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.reserve(n + 7);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int sum1 = 0,sum2 = 0;
    for(int i = 1,j = n,t = 0;i <= j;) {
        if(t % 2 == 0) {
            if(a[i] > a[j]) {
                sum1 += a[i];
                i++;
            }
            else {
                sum1 += a[j];
                j--;
            }
        }
        else {
            if(a[i] > a[j]) {
                sum2 += a[i];
                i++;
            }
            else {
                sum2 += a[j];
                j--;
            }
        }
        t++;
    }   
    cout << sum1 << ' ' << sum2;
    return 0;
}