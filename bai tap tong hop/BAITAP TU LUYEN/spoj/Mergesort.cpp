#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n = 1, a[MM];



void Merge(int a[],int l1,int r1,int l2,int r2)
{
    vector<int> v;
    int i = l2;
    for(int j = l1;j <= r1;j++) {
        while(i <= r2 && a[i] < a[j]) {
            v.push_back(a[i]);
            i++;
        }
        v.push_back(a[j]);
    }
    for(;i <= r2;i++) v.push_back(a[i]);
    // for(auto x:v) cout << x << ' '; cout << '\n';
    for(int i = 0;i < v.size();i++)
        a[l1 + i] = v[i]; 
}



void mergeSort(int a[],int l,int r)
{
    if(l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    Merge(a,l,mid,mid+1,r);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> a[n]) n++;
    n--;
    mergeSort(a,1,n);
    // Merge(a,1,3,4,n);
    for(int i = 1;i <= n;i++) cout << a[i] << ' ';

    return 0;
}