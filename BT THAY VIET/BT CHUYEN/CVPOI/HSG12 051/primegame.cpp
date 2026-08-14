#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll Max = 2e9 + 11;
int t;

// Tính a^k mod n
long long binaryPower(long long a, long long k, long long n)
{
    a = a % n;
    long long res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        k /= 2;
    }
    return res;
}

// Kiểm tra điều kiện thuật toán với a cố định
bool test(long long a, long long n, long long k, long long m)
{
    long long mod = binaryPower(a, m, n);
    if (mod == 1 || mod == n - 1)
            return true;
    for (int l = 1; l < k; ++l)
    {
        mod = (mod * mod) % n;
        if (mod == n - 1)
            return true;
    }
    return false;
}

bool RabinMiller(long long n)
{
    // Kiểm tra với các giá trị nhỏ
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n < 11)
        return false;

    // Tính m và k
    long long k = 0, m = n - 1;
    while (m % 2 == 0)
    {
        m /= 2;
        k++;
    }

    // Lặp lại bước kiểm tra với a ngẫu nhiên
    const static int repeatTime = 3;
    for (int i = 0; i < repeatTime; ++i)
    {
        long long a = rand() % (n - 3) + 2;
        if (!test(a, n, k, m))
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        ll A,B,k; cin >> A >> B >> k;
        bool ok = 0;

        for(ll i = 1;i <= k;i++) 
            if(A - i >= 1 && RabinMiller(B + A - i)) {
                ok = 1;
                break;
            }
            
        for(ll i = 1;i <= k;i++) {
            if(RabinMiller(A + B + i)) {
                ok = 1;
                break;
            }
        }

        if(ok) cout << "Yes" << '\n';
        else {
            ll s = A + B;
            ll r = s;
            for(;;r++) {
                if(RabinMiller(r)) break;
            }
            // cout << s << ' ' << r << ' ';
            if((r - s) % (k + 1) == 0) cout << "No" << '\n';
            else cout << "Yes" << '\n';
        }
    }
    return 0;
}