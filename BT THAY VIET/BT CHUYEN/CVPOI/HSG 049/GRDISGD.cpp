#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 32 + 7;
const int LOG = 16;
int n;
ll l,r,w[MM],v[MM];
struct Node{ll wei,val; vector<int> comps;};
vector<Node> A,B;
pii st[1 << 16][LOG + 1];

bool Cmp(Node a,Node b)
{
    return a.wei < b.wei;
}

vector<int> cmp;
void TryA(int L,int R,int id,ll cur_w,ll cur_val,vector<Node> &f)
{
    if(id > R) {
        if(cur_w > r) return;
        f.push_back({cur_w,cur_val,cmp});
        return;
    }
    cmp.push_back(id);
    TryA(L,R,id+1,cur_w + w[id],cur_val + v[id],f);
    cmp.pop_back();

    TryA(L,R,id+1,cur_w,cur_val,f);
}

int getpos(int l,int r)
{
    int k = __lg(r - l + 1);
    if(st[l][k].fi > st[r - (1 << k) + 1][k].fi) return st[l][k].se;
    return st[r - (1 << k) + 1][k].se;
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
    cin >> n >> l >> r;
    for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
    TryA(1,n/2,1,0,0,A);
    TryA(n/2+1,n,n/2+1,0,0,B);
    sort(A.begin(),A.end(),Cmp);
    sort(B.begin(),B.end(),Cmp);
    ll res = 0;
    int sz1 = A.size() - 1;
    int sz2 = B.size() - 1;

    for(int i = 0;i <= sz2;i++)
        st[i][0] = {B[i].val,i};

    for(int j = 1;j <= LOG;j++)
        for(int i = 0;i + (1 << j) - 1 <= sz2;i++) {
            if(st[i][j-1].fi > st[i + (1 << (j-1))][j-1].fi) st[i][j] = st[i][j-1];
            else st[i][j] = st[i + (1 << (j-1))][j-1];
        }


    // for(int i = 0;i <= sz1;i++) cout << i << ' ' << A[i].wei << ' ' << A[i].val << '\n'; cout << '\n';
    // for(int i = 0;i <= sz2;i++) cout << i << ' ' << B[i].wei << ' ' << B[i].val << '\n';
    vector<int> ans;
    for(int i = 0, j1 = sz2, j2 = sz2;i <= sz1;i++) {
        // cout << i << ' ' << j1 << ' ' << j2 << '\n';
        // cout << i << ' ' << A[i].wei << ' ' << j1 << ' ' << B[j1].wei << ' ' << j2 << ' ' << B[j2].wei << '\n';
        while(0 <= j1 && A[i].wei + B[j1].wei >= l) j1--;
        // j1++;
        while(0 <= j2 && A[i].wei + B[j2].wei > r) j2--;
        if(j1 + 1 > j2) continue;
        ll maxpos = getpos(j1+1,j2);
        // cout << B[maxpos].val << '\n';
        if(res < A[i].val + B[maxpos].val) {
            res = A[i].val + B[maxpos].val;
            ans = A[i].comps;
            for(auto x:B[maxpos].comps) ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for(auto x:ans) cout << x << ' ';

    return 0;
}