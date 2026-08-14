#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int f[N],b[N];
vector<int> v;
int M = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "QUASONG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    while(k--) {
        int l,r;
        cin >> l >> r;
        for(int j = l;j <= r;j++) {
            if(b[j] == 0) {
                v.push_back(j);
                b[j] = 1;
            } 
        }
    }
    f[1] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j:v) {
            if(i - j >= 1) {
                f[i] = (f[i] + f[i-j]) % M;
            }
        }
    }
    cout << f[n];
    return 0;
}