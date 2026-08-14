#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v;
    cin >> v;
    string s;
    cin >> s;
    int d = 0;
    if(v == 1) {
        cout << s.size();
        return 0;
    }
    else if(v == 2) {
        if(s.size() == 1 && s[0] == '0') {
            cout << 1;
            return 0;
        }
        if(s.size() == 1 && s[0] == '1') {
            cout << 2;
            return 0;
        }
        if(s[0] == '1' || s[0] == '9') d++;
        else d+=2;
        for(int i = 1;i < s.size();i++) {
            if(s[i] == '0' || s[i] == '9') d++;
            else d+=2;
        }
        cout << d;
        return 0;
    }
    else {
        if(s.size() == 1 && s[0] == '2') {
            cout << 3;
            return 0;
        }
        set<string> lt,ans;
        map<string,int> dd;
        if(s.size() == 1 && s[0] == '0') {
            cout << 2;
            return 0;
        }
        if(s[0] == '1') {
            string k = s;k[0] = '2';lt.insert(k);dd[k]=1;
        }
        else if(s[0] == '9') {
            string k = s;k[0] = '8';lt.insert(k);dd[k]=1;
        }
        else {
            string k = s,k1 = s;
            k[0]--;lt.insert(k);dd[k]=1;
            k1[0]++;lt.insert(k1);dd[k1]=1;
        }
        for(int i = 1;i < s.size();i++) {
            for(int id = max(0,s[i]-'0'-1);id <= min(9,s[i]-'0'+1);id++) {
                char c = id+'0';
                string k = s;k[i] = c;  lt.insert(k);
                dd[k]=1;
            }
        }
        for(auto p:lt) {
            if(p[0] == '1') {
                string k = s; k[0] = '2';
                if(dd[k] != 1) ans.insert(k);
            }
            else if(p[0] == '9') {
                string k = s; k[0] = '8';
                if(dd[k] != 1) ans.insert(k);
            }
            else {
                string k = p,k1 = p;k[0]--;
                if(dd[k] != 1) ans.insert(k);  k1[0]++;
                if(dd[k1] != 1) ans.insert(k1);
            }
            for(int i = 1;i < p.size();i++) {
                if(p[i] == '0') {
                    string k = p; k[i] = '1';  if(dd[k] != 1) ans.insert(k);
                }
                else if(p[i] == '9') {
                    string k = p;k[i] = '8'; if(dd[k] != 1) ans.insert(k);
                }
                else {
                    string k = p,k1 = p;k[i]--;k1[i]++;
                    if(dd[k] != 1) ans.insert(k);
                    if(dd[k1] != 1) ans.insert(k1);
                }
            }
        }
        ans.insert(s);
        d = ans.size();
        cout << d;
        return 0;
    }
    return 0;
}
