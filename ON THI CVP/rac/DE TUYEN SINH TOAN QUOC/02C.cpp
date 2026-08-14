#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll cnt = 0,id = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    string s;
    cin >> k;
    ll start = 1,end = 9;
    while(1) {
        if((end-start)*id+cnt > k) break;
        else cnt += (end-start)*id+cnt;
        start *= 10;
        end = end*10+9;
        id++;
    }
    ll pos = k-cnt+1;
    cout << pos << ' ' << k;
    return 0;
}