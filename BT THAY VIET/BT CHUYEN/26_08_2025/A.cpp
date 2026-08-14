#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 3e6+7;
int t;
pair<int,int> q[MM];

void init()
{
    cin >> t;
    for(int i = 1;i <= t;i++) cin >> q[i].first >> q[i].second;
}

string int_to_string(int k)
{
    string s;
    while(k > 0) {
        char c = k % 10 + '0';
        s.push_back(c);
        k /= 10;
    }
    reverse(s.begin(),s.end()); return s;
}
bool check(int k)
{
    string s = int_to_string(k);
    for(int i = 0;i < s.size()-1;i++) if(s[i] == '6' && s[i+1] == '8') return 1;
    return 0;
}
void generate_nums(vector<int> &v)
{
    int lim = 3e6;
    for(int i = 1;i <= lim;i++) if(check(i)) v.push_back(i);
    sort(v.begin(),v.end());
}

namespace subtask1
{
    vector<int> v;
    bool checksub1()
    {
        int lim = 1e5;
        for(int i = 1;i <= t;i++) {
            if(q[i].first == 1) return 0;
        }
        return 1;
    }

    void solve()
    {
        generate_nums(v);
        for(int j = 1;j <= t;j++) {
            cout << v[q[j].second-1] << '\n';
        }
    }
}

namespace subtask2
{
    vector<int> a,v,vals;

    bool checksub2()
    {
        int lim = 1e5;
        for(int j = 1;j <= t;j++) {
            if(q[j].first == 2 && q[j].second > lim) return 0;
        }
        return 1;
    }

    struct Segtree
    {
        vector<ll> st; // moi node luu 0/1 tuong ung ton tai hoac da xoa
        Segtree(int n) : st(n*4+1) {};

        void update(int id,int l,int r,int pos,int val) // val - 0/1
        {
            if(l > pos || r < pos) return;
            if(l == r) {
                st[id] = val;
                return;
            }
            int mid = (l+r)/2;
            update(id*2,l,mid,pos,val);
            update(id*2+1,mid+1,r,pos,val);
            st[id] = st[id*2] + st[id*2+1];
        }

        int get(int id,int l,int r,int k) {
            if(l == r) return l;
            int mid = (l+r)/2;
            if(st[id*2] >= k) return get(id*2,l,mid,k);
            else return get(id*2+1,mid+1,r,k-st[id*2]);
        }

    };

    map<int,int> lt;
    void solve()
    {
        vals.clear();
        generate_nums(vals); 
        for(int i = 1;i <= t;i++) {
            if(q[i].first == 1) {
                vals.push_back(q[i].second);
            }
        }
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        int n = vals.size();
        Segtree g(n);
        for(int x:vals) {
            if(check(x)) {  
                int id = lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
                g.update(1,1,n,id,1);
                lt[x] = 1;
            }
        }
        
        for(int i = 1;i <= t;i++) {
            int type = q[i].first,val = q[i].second;
            if(type == 1) {
                int id = lower_bound(vals.begin(),vals.end(),val)-vals.begin()+1;
                if(!lt[val]) {
                    lt[val] = 1;
                    g.update(1,1,n,id,1);
                }
                else {
                    lt[val] = 0;
                    g.update(1,1,n,id,0);
                }
            }
            else {
                int id = g.get(1,1,n,val);
                cout << vals[id-1] << '\n';
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    if(subtask1::checksub1()) subtask1::solve();
    else subtask2::solve();
    return 0;
}