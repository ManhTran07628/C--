#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll solve(int a,int b)
{
    string t1 = to_string(a);
    string t2 = to_string(b);
    t1.erase(2);
    t2.erase(1);
    a = stoi(t1);
    b = stoi(t2);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S,kt = 0;
    cin >> S;
    int A = 0,B = 0,ans = 0;
    for(int a = 100;a <= 999;a++) {
        if(a % 10 != 0) continue;
        for(int b = 100;b <= 999;b++) {
            string s = to_string(b);
            if(s[1] != '0') continue;
            string t1 = to_string(a);
            string t2 = to_string(b);
            t1.erase(2,2);
            t2.erase(1,1);
            int i = stoi(t1);
            int j = stoi(t2);
            if(i+j < S && i+j > ans && i == j) {
                kt = 1;
                ans = i+j;
                A = a;
                B = b;
            }
        }
    }
    cout << ans << ' ' << A << ' ' << B;
    return 0;
}