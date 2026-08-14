#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
ll n,k,a[MM];

namespace subtask1
{
    bool is_sorted(vector<int> vec)
    {
        for(int i = 0;i < vec.size() - 1;i++) 
            if(vec[i] > vec[i + 1]) return 0;
        return 1;
    }

    int cntstep(int l,int r)
    {
        vector<int> vec;
        for(int i = l;i <= r;i++) vec.push_back(a[i]);
        int cnt = 0;

        if(vec.empty()) return 0;

        while(!is_sorted(vec)) {

            for(int i = 0;i < vec.size() - 1;i++) {
                if(vec[i] > vec[i + 1]) {
                    swap(vec[i],vec[i + 1]);
                    cnt++;
                    break;
                }
            }

        }

        return cnt;
    }

    ll res = 0;
    vector<int> seg;

    ll isvalid()
    {
        // ll cnt = 0;
        seg.push_back(n);
        for(int i = 1;i < seg.size();i++) {
            int r = seg[i];
            int l = seg[i - 1] + 1;
            // cnt += cntstep(l,r);
            if(l > r) return 0;
            if(cntstep(l,r) > k) return 0;
        }
        return 1;
        // return cnt <= k;
    }

    void Try(int id,int seg_left)
    {
        if(id > n) {
            if(seg_left > 0) return;
            ll x = isvalid();
            if(x) {
                res++;
                // cout << x << '\n';
                // for(int i = 1;i < seg.size();i++) {
                //     cout << seg[i - 1] + 1 << ' ' << seg[i] << '\n';
                // }
                // cout << '\n' << '\n';
            }
            seg.pop_back();
            return;
        }
        if(seg_left > 0) {
            seg.push_back(id);
            Try(id + 1,seg_left - 1);
            seg.pop_back();
        }

        Try(id + 1,seg_left);
    }

    void solve()
    {
        // cout << cntstep(1,5);
        seg.push_back(0);
        for(int i = 0;i <= n;i++) 
            Try(1,i);
        cout << res;
    }
}

const int MS23 = 3007;
namespace subtask2
{
    bool is_sorted(vector<int> vec)
    {
        for(int i = 0;i < vec.size() - 1;i++) 
            if(vec[i] > vec[i + 1]) return 0;
        return 1;
    }

    int cntstep(int l,int r)
    {
        vector<int> vec;
        for(int i = l;i <= r;i++) vec.push_back(a[i]);
        int cnt = 0;

        if(vec.empty()) return 0;

        while(!is_sorted(vec)) {

            for(int i = 0;i < vec.size() - 1;i++) {
                if(vec[i] > vec[i + 1]) {
                    swap(vec[i],vec[i + 1]);
                    cnt++;
                    break;
                }
            }

        }

        return cnt;
    }

    ll dp[MS23] = {};

    void solve()
    {
        dp[0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = i;j >= 1;j--) {
                if(cntstep(j,i) <= k) {
                    dp[i] += dp[j - 1];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[n];
    }
}

namespace subtask3
{
    int bit[MM];
    int sz = 0;

    // Cập nhật tăng giá trị tại vị trí idx lên delta
    void update(int idx, int delta) {
        for (; idx <= sz; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Lấy tổng từ 1 đến idx
    int get(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    void coordcompress()
    {
        vector<int> vec;
        for(int i = 1; i <= n; i++) vec.push_back(a[i]);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for(int i = 1; i <= n; i++)
            a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        sz = vec.size();
    }

    ll dp[MM] = {};

    void solve()
    {
        coordcompress();
        // Khởi tạo mảng bit bằng 0
        for(int i = 1; i <= sz; i++) bit[i] = 0; 
        
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            ll cnt = 0;
            for(int j = i; j >= 1; j--) {
                // Đếm số phần tử nhỏ hơn a[j] đã được thêm vào (tức là nằm bên phải j)
                cnt += get(a[j] - 1);
                
                if(cnt > k) {
                    // Xóa các phần tử đã thêm vào BIT trong vòng lặp này để reset
                    for(int x = j; x <= i; x++) update(a[x], -1);
                    break; 
                }
                
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
                
                // Thêm a[j] vào BIT
                update(a[j], 1);
                
                // Nếu chạy đến tận phần tử j = 1 mà vẫn thỏa mãn, cần dọn dẹp BIT
                if (j == 1) {
                    for(int x = 1; x <= i; x++) update(a[x], -1);
                }
            }
        }

        cout << dp[n] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "NARR"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    subtask3::solve();
    return 0;
}