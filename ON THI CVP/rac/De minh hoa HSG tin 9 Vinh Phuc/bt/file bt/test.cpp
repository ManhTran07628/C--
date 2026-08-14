#include <bits/stdc++.h>
using namespace std;
long long n, k, temp, maxx = 0, l = 0, countt = 0, lmax, rmax;
long long num[1000001];
vector<long long> v;
void solve(){
    for(long long i = 0; i!= n ;i++){
        if(!num[v[i]]) countt++;
        num[v[i]]++;
        while(countt > k){
            num[v[l]] -= 1;
            if(!num[v[l]]) countt--;
            l++;
            if(l == n) break;
        }
        if(maxx < i - l + 1){
            maxx = i - l + 1;
            lmax = l + 1; rmax = i + 1;
        }
    }
    cout << lmax << " " << rmax;
    return;
}
int main(){
    freopen("KGOOD.INP", "r", stdin);
    freopen("KGOOD.OUT", "w", stdout);
    cin >> n >> k;
    for(long long i = 0; i != n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    solve();
	return 0;
}
