#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 3e5+7;
int a[MAXN],b[MAXN],pre[MAXN],suf[MAXN];
int n,m,k;
vector<int> v[MAXN];

void xuly1()
{
    int i = 1,j = 1;
    while(i <= n) {
        if(a[i] == b[j]) {
            pre[i]++;
            j++;
        }
        pre[i] += pre[i-1];
        i++;
    }
}
void xuly2()
{
    int i = n,j = m;
    while(i >= 1) {
        if(a[i] == b[j]) {
            suf[i]++;
            j--;
        }
        suf[i] += suf[i+1];
        i--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
        v[b[i]].push_back(i);
    }
    xuly1();xuly2();
    for(int i = 1;i <= n;i++) {
        int j = upper_bound(v[a[i]].begin(),v[a[i]].end(),m-suf[i+1])-v[a[i]].begin()+1;
        if(j < v[a[i]].size() && j <= pre[i-1]+1) cout << 1;
        else cout << 0;
        cout << ' ';
    }
    return 0;
}

// pre[i] so phan tu dau tien cua B ta co the khop thanh cong trong prefix A1..i
// suf[i] so phan tu cuoi cung cua B ta co the khop thanh cong trong suffix Ai..n(khop tu B[m] tro ve)
// m - suf[i+1] <= j <= pref[i-1]+1
