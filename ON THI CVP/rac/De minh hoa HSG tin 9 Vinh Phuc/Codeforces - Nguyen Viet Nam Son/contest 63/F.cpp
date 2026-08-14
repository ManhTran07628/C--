#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<int> a;
bool check(int k)
{
    while(k > 0) {
        if(k % 10 == 4) return 0;
        k/=10;
    }
    return 1;
}

void sinhkq()
{
    for(int i = 1;i <= N;i++) {
        if(check(i)) a.push_back(i);
    }
}

int main()
{
    int n;
    cin >> n;
    ll min1 = n,l,r;
    for(int i:a) {
        auto p = lower_bound(a.begin(),a.end(),n-i);
        if(*p+i == n) {
            if(abs(*p-i) < min1) {
                l = min(*p,i);
                r = max(*p,i);
                min1 = abs(*p-i);
            }
        }
    }
    cout << l << ' ' << r;
    return 0;
}