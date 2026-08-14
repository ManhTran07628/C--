#include <bits/stdc++.h>
using namespace std;
vector<ll>
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
    int n,q;
    cin >> n >> q;
    vector<int> v(n + 1);
    vector<long long> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        a[i] = a[i - 1] + v[i];
    }	
    while(q--){
        int c;
        cin >> c;
        if(c == 1){
            int x;
            cin >> x;
            v.push_back(x);
            a.push_back(a.back() + x);
        }
        if(c == 2){
            if(v.size()){
                v.pop_back();
                a.pop_back();
            }
        }
        if(c == 3){
            int l,r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << "\n";
        }
    }
    return 0;
}