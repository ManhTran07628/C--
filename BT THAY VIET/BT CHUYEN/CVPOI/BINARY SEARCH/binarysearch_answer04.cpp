#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e6+7;
int n,q,p[MM];

struct QR{char type;int a,b;} qr[MM];



namespace sol
{
    int st[MM * 4],pos[MM],lim = 0;
    void update(int id,int l,int r,int pos,int val)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] += val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        st[id] = st[id*2] + st[id*2+1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }

    void process()
    {
        vector<int> v;
        for(int i = 1;i <= n;i++) v.push_back(p[i]);
        for(int i = 1;i <= q;i++) {
            if(qr[i].type == '!') {
                // v.push_back(qr[i].a); 
                v.push_back(qr[i].b);
            }
            else {
                v.push_back(qr[i].a); 
                v.push_back(qr[i].b);
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i = 1;i <= n;i++) {
            p[i] = lower_bound(v.begin(),v.end(),p[i]) - v.begin() + 1;
            pos[i] = p[i];
            lim = max(lim,p[i]);
        }
        
        for(int i = 1;i <= q;i++) {
            if(qr[i].type == '!') {
                // qr[i].a = lower_bound(v.begin(),v.end(),qr[i].a) - v.begin() + 1;
                qr[i].b = lower_bound(v.begin(),v.end(),qr[i].b) - v.begin() + 1;
                lim = max(lim,qr[i].b);
            }
            else {
                qr[i].a = lower_bound(v.begin(),v.end(),qr[i].a) - v.begin() + 1;
                qr[i].b = lower_bound(v.begin(),v.end(),qr[i].b) - v.begin() + 1;
                lim = max(lim,qr[i].a);
                lim = max(lim,qr[i].b);
            }
        }
    }

    void solve()
    {
        process();
        for(int i = 1;i <= n;i++) {
            update(1,1,lim,p[i],1);
        }
        for(int i = 1;i <= q;i++) {
            char type = qr[i].type;
            if(type == '!') {
                int k = qr[i].a, x = qr[i].b;
                update(1,1,lim,pos[k],-1);
                pos[k] = x;
                update(1,1,lim,pos[k],1);
            }
            else {
                int a = qr[i].a, b = qr[i].b;
                cout << get(1,1,lim,a,b) << '\n';
            }
        }

        // for(int i = 1;i <= n;i++) cout << p[i] << ' ';
        // cout << '\n';
        // for(int i = 1;i <= q;i++) {
        //     cout << qr[i].type << ' ' << qr[i].a << ' ' << qr[i].b << '\n';
        // }
    }
}

namespace brute
{
    void solve()
    {
        for(int i = 1;i <= q;i++) {
            if(qr[i].type == '!') {
                p[ qr[i].a ] = qr[i].b;
            }
            else {
                int res = 0;
                for(int j = 1;j <= n;j++)
                    if(qr[i].a <= p[j] && p[j] <= qr[i].b)
                        res++;
                cout << res << '\n';
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "sol"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> p[i];

    for(int i = 1;i <= q;i++) {
        cin >> qr[i].type >> qr[i].a >> qr[i].b;
    }

    sol::solve();

    return 0;
}