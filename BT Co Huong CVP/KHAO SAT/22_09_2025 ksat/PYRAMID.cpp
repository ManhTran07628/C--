#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,r,c;

void solve1()
{
    int en = 0,row = 0;
    while(en < n) {
        row++;
        en += row*2-1;
    }
    cout << row << ' ';
    if(row % 2 == 0) {
        int st = en - (row*2-1) + 1;
        cout << abs(n-st+1);
    }
    else cout << abs(en-n+1);
}

void solve2()
{
    int en = 0,row = 0;
    while(row+1 <= r) {
        row++;
        en += row*2-1;
    }
    int st = en - (row*2-1) + 1;
    if(row % 2 == 0) {
        cout << st+c-1;
    }
    else cout << en-c+1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "PYRAMID"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> r >> c;
    solve1();
    cout << '\n';
    solve2();
    return 0;
}