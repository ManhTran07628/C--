#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[8][8];
ll n,m,pos = 1;
ll dx[9] = {-2,-1,1,2,2,1,-1,-2};
ll dy[9] = {1,2,2,1,-1,-2,-2,-1};

void backtrack(ll x,ll y,ll pos)
{
    a[x][y] = pos;
    if(pos == n*m) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    for(int i = 0;i < 8;i++) {
        if(x+dx[i] < n && x+dx[i]>= 0) 
            if(y+dy[i] < m && y + dy[i] >= 0 ) 
                if(a[x+dx[i]][y+dy[i]] == 0) 
                    backtrack(x+dx[i],y+dy[i],pos+1);
    }
    if(pos==1) {
        y++;
        if(y==m-1)
        {
            if(x == n-1)
                return;                      
            else {
                y=0;
                x++;
                backtrack(x,y,pos);
            }
        }
    }
    else
    {
        a[x][y]=0;
        return;
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
    cin >> n >> m;
    backtrack(0,0,1);
    return 0;
}