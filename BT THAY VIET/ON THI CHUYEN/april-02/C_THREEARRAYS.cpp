#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll d[MAXN],l[MAXN],r[MAXN];
ll a[MAXN],b[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a0,b0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> d[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> l[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> r[i];
    }
    for(int i = 1;i <= )
    return 0;
}


// a0, A1 = min(a0,L1)
// thử các giá trị có thể có của An là các Li <= a0
// với mỗi giá trị An đang tuhuwr cần tính Bn mã là bao nhiêu ?
// Bi chỉ bị setmin khi Li <= An,Nghĩa là Bn là min (Ri) sao cho Li < and
// sort các cặp (Li,Ri) theo tăng dần.
// tiền xử lí prefixmin[i]:min(R_i) tính từ 1 đến vị trí i
// với giá trị An cố định,tìm kiếm nhị phần j lớn nhất sao cho Lj < An

// sub6
// An cuối cùng phải có dạng Lp + D_(p+1) ... +D_n