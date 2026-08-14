#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while(n != m) {
        if(n > m) n--;
        if(n*2 <= m) {
            n *= 2;
            continue;
        }
        if(n < m) {
            int t = n*2-m;
            int t1 = n-(m/2);
        }
    }
    return 0;
}