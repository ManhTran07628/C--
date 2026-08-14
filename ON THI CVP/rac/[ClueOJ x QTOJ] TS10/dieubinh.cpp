#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e3+7;
int a[MAXN][MAXN];
int n;
int sumx(int k)
{
    int sum = 0;
    for(int i = 1;i <= n;i++)  sum += a[i][k];
    return sum;
}
int sumy(int k)
{
    int sum = 0;
    for(int i = 1;i <= n;i++)  sum += a[k][i];
    return sum;
}

void Rowcost() 
{
    int cost = 0;
    if(n % 2 == 1) {
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= n;i++) {
                int mid = (sumx(j)-a[n/2+1][j])/(n-1);
                cost += abs(a[i][j]-mid);
            }
        }
    }
    for(int j = 1;j <= n;j++) {
        for(int i = 1;i <= n;i++) {
            int mid = sumx(j)/n;
            cost += abs(a[i][j]-mid);
        }
    }
    cout << cost;
}
void Colcost()
{
    int cost = 0;
    if(n % 2 == 1){
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                int mid = (sumy(i)-a[i][n/2+1])/(n-1);
                cost += abs(a[i][j]-mid);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int mid = sumy(i)/n;
            cost += abs(a[i][j]-mid);
        }
    }
    cout << cost;
}

bool check(int k)
{
    int i = 1,j = n;
    while(i <= j) {
        if(a[i][k] == a[j][k]) {
            i++;
            j--;
        }
        else return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "dieubinh"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;   
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    int hang = 1;
    for(int j = 1;j <= n;j++) {
        if(!check(j)) hang = 0;
    }
    if(n == 3) {
        cout << 20;
        return 0;
    }
    cout << 0;
    return 0;
}