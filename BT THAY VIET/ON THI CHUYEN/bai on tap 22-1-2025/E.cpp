#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int n,k,ans = 0;
int a[5001],f[5001];

void backtrack(int s,int id,int cr)
{
    if(s > n) return;
    if(s == n) {
        ans += f[id];
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(id == 1) {
            a[id] = i;
            backtrack(s+i,id+1,cr+1);
        }
        else {
            if(a[id-1] < a[id]) backtrack()
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    return 0;
}