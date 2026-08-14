#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int f[31][31];
int n,m;

void backtrack(int x,int y)
{
    if(f[x][y] || x < 1 || x > n || y > m || y < 1) return;
    f[x][y] = 1;
    cout << x << ' ' << y << '\n';
    backtrack(x+1,y);
    backtrack(x,y+1);
    backtrack(x-1,y);
    backtrack(x,y-1);
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
    cin >> n >> m;
    backtrack(1,1);
    return 0;
}