#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> d = {6,2,5,5,4,5,6,3,7,6};

int que(int x) {
    if (x == 0) return d[0];
    int cnt = 0;
    while (x > 0) {
        cnt += d[x%10];
        x /= 10;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int A = 0;A <= 1000;A++) {
        for(int B = 0;B <= 1000;B++) {
            int C = A+B;
            int sum = que(A)+que(B)+que(C)+4;
            if(sum == n) ans++;
        }
    }
    cout << ans;
    return 0;
}