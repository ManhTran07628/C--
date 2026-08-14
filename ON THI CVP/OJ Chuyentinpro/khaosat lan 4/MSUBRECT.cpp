#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[3001][3001],p[3001][3001],p1[3001][3001];
int n,m,r,s;
void xuly1(int x)
{
    multiset<int> ms;
    int i = 1,j = 1;
    while(i <= m && j <= m) {
        if(j-i+1 > s) {
            p[x][i] = *ms.rbegin();
            ms.erase(ms.find(a[x][i]));
            i++;
        }
        else {
            ms.insert(a[x][j]);
            j++;
        }
    }
    p[x][i] = *ms.rbegin();
}
void xuly2(int y)
{
    multiset<int> ms;
    int i = 1,j = 1;
    while(i <= n && j <= n) {
        if(j-i+1 > r) {
            p1[i][y] = *ms.rbegin();
            ms.erase(ms.find(p[i][y]));
            i++;
        }
        else {
            ms.insert(p[j][y]);
            j++;
        }
    }
    p1[i][y] = *ms.rbegin();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j]; 
            p1[i][j] = INT_MIN;
            p[i][j] = INT_MIN;
        }
    }

    cin >> r >> s;
    for(int i = 1;i <= n;i++) xuly1(i);
    for(int i = 1;i <= m;i++) xuly2(i);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(p1[i][j] != INT_MIN) cout << p1[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}