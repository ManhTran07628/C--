#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,int> p;
pair<int,int> a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[a[i].fi].se = i;
        p[a[i].fi]++;
    }
    for(int i = n;i >= 1;i--) {
        if(p[i] > 1) {
            for(int j = n;j >= 1;j--) {
                if(p[j] == 0) {
                    cout << a[i].se << ' ' << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}