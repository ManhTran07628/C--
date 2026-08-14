#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<ll> f;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        ll pos = lower_bound(f.begin(),f.end(),a[i]) - f.begin(); // tìm phần tử đầu tiên mà nó >= a[i]
        // kiểm tra xem nếu không có phần tử nào trong mảng vector >= a[i]
        if(pos == f.size()) f.push_back(a[i]);//  nếu không có thì thêm vào cuối vector
        else f[pos] = a[i]; // còn không thì thay phần tử ở vị trí pos là a[i];
    }
    cout << f.size(); // in ra kết quả
    return 0;
}