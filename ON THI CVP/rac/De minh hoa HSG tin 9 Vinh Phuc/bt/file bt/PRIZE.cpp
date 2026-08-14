#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N],b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("PRIZE.inp","r",stdin);
    freopen("PRIZE.out","w",stdout);
    string s;
    ll n;
    cin >> s >> n;
    for(int i = 0;i < s.size();i++) {
        a[s[i]]++;
    }
    ll dem = 0;
    while(n--) {
        string k;
        cin >> k;
        bool kt = true;
        for(int i = 0;i < k.size();i++) a[k[i]]--;
        for(int i = 0;i < s.size();i++)
            if(a[s[i]] > 0) {
                kt = false;
                break;
            }

        if(kt == true) dem++;
        for(int i = 0;i < s.size();i++) a[s[i]] = 0;
        for(int i = 0;i < s.size();i++) a[s[i]]++;
    }
    cout << dem;
    return 0;
}

