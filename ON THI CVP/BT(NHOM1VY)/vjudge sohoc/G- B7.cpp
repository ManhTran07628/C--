#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[1001];
vector<int> f[33],k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i <= 1000;i++) {
        for(int j = 1;j <= sqrt(i);j++) {
            if(i % j == 0) {
                a[i]++;
                if(i / j != j) a[i]++;
            }
        }
        f[a[i]].push_back(i);
    }
    for(int i = 1;i <= 32;i++) {
        sort(f[i].begin(),f[i].end());
        reverse(f[i].begin(),f[i].end());
        for(auto it:f[i]) k.push_back(it);
    }

    int t;
    cin >> t;
    int i = 1;
    while(t--) {
        int n;
        cin >> n;
        cout << "Case "<<i<<": " << k[n-1] << '\n';
        i++;
    }
    return 0;
}