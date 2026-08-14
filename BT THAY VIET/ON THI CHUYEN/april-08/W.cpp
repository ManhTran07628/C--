#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> v;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    n = min(n,1000000);
    for(int i = 1;i <= n;i++) {
        v.push_back(i);
    }
    while(1) {
        if(v.size() < k) break;
        int vt = 0;
        for(int i = 0;i < v.size();i++) {
            if(vt == k) {
                
            }
        }
    }
    return 0;
}