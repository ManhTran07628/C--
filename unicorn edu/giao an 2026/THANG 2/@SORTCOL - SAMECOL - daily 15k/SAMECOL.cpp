#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long x[N], y[N];
vector<int> a, b;
int n, q;
int vta(int key, int l, int r)
{
    while(l < r){
        int mid = (l+r)/2;
        if ( a[mid] == key) return mid;
        if ( a[mid] < key) l = mid + 1;
        else
            r = mid - 1;
    }
    if (a[l] > key ) return l-1;
    else return l;
}
int vtb(int key, int l, int r)
{
    while(l < r){
        int mid = (l+r)/2;
        if ( b[mid] == key) return mid;
        if ( b[mid] < key) l = mid + 1;
        else
            r = mid - 1;
    }
    if (b[l] > key ) return l-1;
    else return l;
}
int main()
{
     #define TASKNAME "samecol"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
        }
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        if (x[i] != x[i-1]) a.push_back(i);
        if (y[i] != y[i-1]) b.push_back(i);
    }
    int m = a.size() - 1, s = b.size() - 1;

    cin >> q;
    for (int i=1; i<=q; i++){
        long long l , r;
        cin >> l >> r;
        int posA = vta(l, 0, m); 
	int posB = vtb(l, 0, s); 
	bool okA = (posA + 1 <= m && r >= a[posA+1]); 
	bool okB = (posB + 1 <= s && r >= b[posB+1]); 
	if (okA || okB) cout << "YES\n"; 
	else cout << "NO\n";
    }
    return 0;
}