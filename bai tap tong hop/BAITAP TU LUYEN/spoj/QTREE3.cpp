#include <bits/stdc++.h>
#define NAME ""
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
const ll INF=1e18; // Dùng INF lớn hơn để không trùng với giá trị có thể có
int n,q;
int x[N],nx[N];
vector<int> g[N];
int par[N],h[N],num[N],timed=0;
int heavy[N],head[N];

struct dl{
	ll sum,maxps,maxss,maxc;
	dl(ll _sum=0,ll _maxps=0,ll _maxss=0,ll _maxc=0){
		sum=_sum; maxps=_maxps; maxss=_maxss; maxc=_maxc;
	}
} st[4*N];

ll lz[4*N];

// --- CÁC HÀM HLD VÀ SEGMENT TREE ---
int dfs(int u){
	int maxsz=0,cursz=1;
	for(int v:g[u]){
		if(v==par[u]) continue;
		h[v]=h[u]+1;
		par[v]=u;
		int t=dfs(v);
		cursz+=t;
		if(t>maxsz){
			maxsz=t;
			heavy[u]=v;
		}
	}
	return cursz;
}
void dfs2(int u,int hd){
	num[u]=++timed;
	head[u]=hd;
	if(heavy[u]) dfs2(heavy[u],hd);
	for(int v:g[u]){
		if(v!=par[u]&&v!=heavy[u]) dfs2(v,v);
	}
}

dl merge(dl a,dl b){
	dl ret;
	ret.sum=a.sum+b.sum;
	ret.maxps=max(a.maxps, a.sum+b.maxps);
	ret.maxss=max(b.maxss, b.sum+a.maxss);
	ret.maxc=max({a.maxc, b.maxc, a.maxss+b.maxps});
	return ret;
}

// THÊM: Hàm lật ngược một node (đảo prefix và suffix sum)
dl flip(dl node) {
    swap(node.maxps, node.maxss);
    return node;
}

// THÊM: Hàm tiện ích để tạo node từ một giá trị và độ dài
dl create_node_val(ll val, int len) {
    ll sum = val * len;
    ll best_val = (val > 0) ? sum : val;
    // Cho phép chọn đoạn con rỗng nên kết quả không thể nhỏ hơn 0
    return dl(sum, max(0LL, best_val), max(0LL, best_val), max(0LL, best_val));
}


void build(int id,int l,int r){
	lz[id]=INF;
	if(l==r){
		st[id] = create_node_val(nx[l], 1);
		return;
	}
	int m=(l+r)/2,ln=2*id,rn=2*id+1;
	build(ln,l,m);
	build(rn,m+1,r);
	st[id]=merge(st[ln],st[rn]);
}

void pushdown(int id,int l,int r){
	if(lz[id]==INF) return;
	int m=(l+r)/2,ln=2*id,rn=2*id+1;
	ll val = lz[id];

	// SỬA LỖI 1: Dùng hàm create_node_val
	st[ln] = create_node_val(val, m - l + 1);
	st[rn] = create_node_val(val, r - m);
	lz[ln]=lz[rn]=val;
	lz[id]=INF;
}

void update(int id,int l,int r,int u,int v,int val){
	if(r<u||v<l) return;
	if(u<=l&&r<=v){
        // SỬA LỖI 1: Dùng hàm create_node_val
		st[id] = create_node_val(val, r - l + 1);
		lz[id]=val;
		return;
	}
	int m=(l+r)/2,ln=2*id,rn=2*id+1;
	pushdown(id,l,r);
	update(ln,l,m,u,v,val);
	update(rn,m+1,r,u,v,val);
	st[id]=merge(st[ln],st[rn]);
}

dl get(int id,int l,int r,int u,int v){
    // Giá trị trả về cho đoạn rỗng/không giao nhau
	if(r<u||v<l) return dl(0, 0, 0, 0); 
	if(u<=l&&r<=v) return st[id];
	int m=(l+r)/2;
	pushdown(id,l,r);
	return merge(get(2*id,l,m,u,v),get(2*id+1,m+1,r,u,v));
}

// --- CÁC HÀM HLD ---
void updatepath(int u,int v,int val){
	while(head[u]!=head[v]){
		if(h[head[u]]<h[head[v]]) swap(u,v); // Luôn xử lý path cao hơn trước
		update(1,1,n,num[head[u]],num[u],val);
		u=par[head[u]];
	}
	if(num[u]>num[v]) swap(u,v);
	update(1,1,n,num[u],num[v],val);
}
// SỬA LỖI 2: Hàm getpath viết lại hoàn toàn cho chính xác
dl getpath(int u,int v){
	dl res_u = dl(0,0,0,0), res_v = dl(0,0,0,0);
	while(head[u]!=head[v]){
		if(h[head[u]] > h[head[v]]){
			res_u = merge(get(1,1,n,num[head[u]],num[u]), res_u);
			u=par[head[u]];
		}
		else{
			res_v = merge(get(1,1,n,num[head[v]],num[v]), res_v);
			v=par[head[v]];
		}
	}
    dl middle_path;
	if(num[u]<num[v]){
		middle_path = get(1,1,n,num[u],num[v]);
	} else {
        middle_path = get(1,1,n,num[v],num[u]);
        middle_path = flip(middle_path); // Lật ngược nếu đi từ v->u
    }

	return merge(merge(flip(res_u), middle_path), res_v);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(NAME ".inp","r")){
		freopen(NAME ".inp","r",stdin);
		freopen(NAME ".out","w",stdout);
	}
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++) nx[num[i]]=x[i];
	build(1,1,n);
	cin>>q;
	while(q--){
		int t,a,b,c;
		cin>>t>>a>>b;
		if(t==1) {
            cout<<getpath(a,b).maxc<<'\n';
        }
		else{
			cin>>c;
			updatepath(a,b,c);
		}
	}
    return 0;
}