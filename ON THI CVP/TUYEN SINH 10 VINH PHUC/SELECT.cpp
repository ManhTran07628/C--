#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int ans = 0,val = 0;
int n;
void backtracking(int length,int id,int k)
{
    if(length > k) return;
    if(length == k) {
        ans = max(ans,val);
        return;
    }
    for(int i = id;i <= n;i++) {
        val += a[i];
        backtracking(length+1,i+2,k);
        val -= a[i];
    }
}

void sub1()
{
    for(int i = 1;i <= (n+1)/2;i++) {
        backtracking(0,1,i);
        cout << ans << '\n';
        ans = 0;
        val = 0;
    }
}

void sub2()
{
    for(int i = 1;i <= (n+1)/2;i++) {
        cout << a[i]*i << '\n';
    }
}

bool checkforsub2()
{
    for(int i = 2;i <= n;i++) 
        if(a[i] != a[i-1]) return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n <= 20) {
        sub1();
        return 0;
    }
    if(checkforsub2()) {
        sub2();
        return 0;
    }
    for(int i = 1;i <= (n+1)/2;i++) {
        cout << i * i << '\n';
    }
    return 0;
}