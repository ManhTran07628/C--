#include<bits/stdc++.h>
using namespace std;
bool check(long long k)
{
    if (k == 2) return 1;
    if (k < 2) return 0;
    int l = sqrt(k);
    for (int i=2;  i <= l; i++)
        if (k % i == 0) return 0;
    return 1;
}
long long a, b, k, s;
vector <long long > f;
int main()
{
    #define TASKNAME "primetuple"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" )) {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout); }
    cin >> a >> b >> k >> s;
    long long ans = 0;
    for (long long i=a; i<=b; i++)
        if (check(i)) f.push_back(i);
    for (int i=k-1; i<f.size(); i++){
        if (f[i-k+1] == f[i] - s) ans ++;
    }
    cout << ans;
    return 0;
}