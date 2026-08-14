#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if(n < 26) {
        cout << -1;
        return 0;
    }
    for(int i = 0;i < n;i++) {
        char a[256];
        int j = i+26;
        for(int k = i;k <= j;k++) {
            a[s[k]]++;
        }
        int crr = 0;
        for(int k = 'A';k <= 'Z';k++) 
            if(a[k] == 1) crr++;

        if(crr == 26) {
            for(int l = 0;l < n;l++) if(s[l] == '?') s[l] = 'A';
            cout << s;
            return 0;
        }
        else {
            vector<int> vt;
            vector<char> chu;
            for(int k = i;k < j;k++) {
                if(s[k] == '?') vt.push_back(k);
            }

            for(int k = 'A';k <= 'Z';k++) {
                if(a[k] == 1) chu.push_back(k); 
            }

            int p = 0;
            fill(a,a+256+1,0);
            for(int k = i;k <= j;k++) {
                if(s[k] == '?') {
                    s[k] = chu[p];
                    p++;                
                }
                a[s[k]]++;
            }
            bool kt = 1;
            for(int k = 'A';k <= 'Z';k++) {
                if(a[s[k]] != 1) {
                    kt = 0;
                    break;
                }
            }
            if(!kt) continue;
            else {
                for(int k = 0;k < n;k++) {
                    if(s[k] == '?') s[k] = 'A';
                }
                cout << s;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}