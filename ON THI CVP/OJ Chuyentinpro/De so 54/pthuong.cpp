#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

bool check(string a)
{
    if((a[a.size()-1] - '0') != 0) return 0;
    int cnt = 0;
    for(char i:a) cnt += (i-'0');
    return cnt % 9 == 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "pthuong"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        string a;
        cin >> a;
        ans += check(a);
    }
    cout << ans;
    return 0;
}