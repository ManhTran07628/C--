#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 2e6+7;
int p[MAXN];
vector<int> v[MAXN];
void sieve()
{
    for(int i = 1;i < MAXN-1;i++)
        for(int j = i;j < MAXN-1;j+=i) 
            p[j]++;
    for(int i = 1;i < MAXN-1;i++) {
        v[p[i]].push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,k;
    cin >> n >> k;
    int pos = upper_bound(v[k].begin(),v[k].end(),n)-v[k].begin();
    cout << pos;
    return 0;
}