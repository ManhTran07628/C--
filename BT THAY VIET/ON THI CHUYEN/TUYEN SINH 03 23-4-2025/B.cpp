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
        string w;
        cin >> w;
        if(next_permutation(w.begin(),w.end())) {
            cout << w << '\n';
        }
        else cout << "no answer" << '\n';
    }
    return 0;
}