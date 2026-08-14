#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int kt[MAXN],dd[MAXN];
vector<int> v[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        kt[a[i]]++;
    }
    sort(a+1,a+n+1);
    int cnt = 0;
    for(int i = 2;i < MAXN;i++) {
        if(kt[i] != 0 && dd[i] == 0) {
            for(int j = i;j < MAXN;j+=i) {
                if(kt[1] != 0 && dd[1] == 0) {
                    v[i].push_back(1);
                    dd[1]++;
                }
                if(dd[j] == 0 && kt[j] != 0) {
                    v[i].push_back(j);
                    dd[j]++;
                }
            }
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(int i = 1;i <= n;i++) {
        if(v[a[i]].size() != 0) {
            cout << v[a[i]].size() << ' ';
            for(auto j:v[a[i]]) cout << j << ' ';
            cout << '\n';
        }
    }
    return 0;
}