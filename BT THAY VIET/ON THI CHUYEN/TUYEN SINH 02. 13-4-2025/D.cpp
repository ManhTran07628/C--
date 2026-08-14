#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll n,a,b;
ll MM = 1e18;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    ll l = 1,r = log2(n),ans = 1e18;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll k = mid,giatri = 1e18;
        for(int i = k;i >= 1;i--) {
            ll chiphi = 1;
            for(int j = k;j >= i;j--) {
                chiphi *= (a+b*(k-1)); 
            }
            for(int j = i-1;j >= 1;j--) {
                chiphi *= (a+b*(k-2)); 
            }
            if(chiphi >= n+1) giatri = min(giatri,chiphi);
        }
        if(giatri == MM) {
            l = mid + 1;
        }
        else {
            ans = min(ans,giatri);
            r = mid - 1;
        }
    }
    cout << ans-1;
    return 0;
}


// yêu cầu số mô hình tạo ra > n  
// p1 <= p2 <= ... <= pk  

// p1 > 1
// dãy ít nhất là: 2....2

// thử lần lượt từng giá trị có thể của k   

// với k cố định, n đã biết -> xác định nhanh giá trị gần tối ưu nhất của p_k  
 

// tìm giá trị gần tối ưu nhất của p_k:

// r^k > n

// p_k tối ưu nhất khi p1 = p2 = .. p_k  Nếu mà không chia đều được số thao tác thì  
// thì pi có dạng :

// p_k - 1, ..., p_k - 1,p_k,p_k

// chi phí bước thứ i là :

// b_i * (a+b*(p_i-1))

// với b_i là số bước trước đó