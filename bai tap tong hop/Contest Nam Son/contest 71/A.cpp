#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        map<int,int> d;
        for(auto i:s) d[i]++;
        int chan = 0,le = 0;
        for(auto i:d) {
            if(i.se % 2 == 0) chan++;
            else le++;
        }
        int ok = 0;
        if(chan == 0 && le == 1) ok = 1;
        if(k == 0 && (le == 0 || le == 1)) ok = 1;
        if(le == 0 && k % 2 == 0) ok = 1;
        if(le == k || le == k+1) ok = 1;
        if(ok) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}