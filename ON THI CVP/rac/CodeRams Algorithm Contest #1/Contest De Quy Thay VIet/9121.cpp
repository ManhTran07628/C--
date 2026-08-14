#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int n,cnt = 0,cntans = 0;
int col[N],diag1[N],diag2[N];
vector<int> pos;



void printans()
{
    cntans++;
    if(cnt < 3) {
        for(auto i:pos) {
            cout << i << " ";
        }
        cout << '\n';
    }
    cnt++;
}


void backtrack(int x)
{
    for(int y = 1;y <= n;y++) {
        int dag1 = x + y;
        int dag2 = x - y + 14;

        if(col[y]) continue;
        if(diag1[dag1]) continue;
        if(diag2[dag2]) continue;

        pos.push_back(y);
        col[y] = 1;
        diag1[dag1] = 1;
        diag2[dag2] = 1;

        if(pos.size() == n) printans();
        else backtrack(x+1);

        pos.pop_back();
        col[y] = 0;
        diag1[dag1] = 0;
        diag2[dag2] = 0;
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
    cin >> n;
    backtrack(1);
    cout << cntans;
    return 0;
}