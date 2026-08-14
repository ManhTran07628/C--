#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

string rev(string s){
    string k = "";
    for(int i = s.size()-1; i >= 0; i--){
      k += s[i];
    }
    return k;
}

string bigplus(string a,string b)
{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) a = '0' + a;
        if(b.size() < a.size()) b = '0' + b;
    }
    int nho = 0;
    string ans;
    for(int i = a.size()-1;i >= 0;i--) {
        int tmp = (a[i]-'0') + (b[i]-'0') + nho;
        char c = (tmp % 10) + '0';
        ans = c + ans;
        nho = tmp / 10;
    }
    if(nho > 0) ans = '1' + ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a,b;
        cin >> a >> b;
        string ans = rev(bigplus(rev(a), rev(b)));
        while(ans[0] == '0'){
             ans.erase(0,1);
             if(ans[0] != '0') break;
         }
        cout << ans << "\n";
    }
    return 0;
}