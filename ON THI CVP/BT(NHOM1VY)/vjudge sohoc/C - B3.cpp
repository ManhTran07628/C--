#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> ts;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;  
    for(int i = 2;i*i <= n;i++) {
        while(n % i == 0) {
            ts.push_back(i);
            n/=i;
        }
    }
    if(n > 1) ts.push_back(n);
    if(ts.size() < k) cout << -1;
    else {
        while(ts.size() != k) {
            ts[0] *= ts[ts.size()-1];
            ts.pop_back();
        }
        for(int i:ts) cout << i << ' ';
    }
    return 0;
}