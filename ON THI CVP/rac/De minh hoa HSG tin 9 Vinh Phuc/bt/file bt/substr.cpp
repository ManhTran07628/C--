#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Substr.inp" , "r" , stdin);
    freopen("Substr.out" , "w" , stdout);
    string s,s1;
    cin>>s>>s1;
    string ss = s + s;
    for(int i = 0;i < s.size();i++) {
        string tmp;
        for(int j = i;j < i+s1.size();j++) {
            tmp += ss[j];
        }
        if(tmp == s1) {
            cout << i+1 << " ";
        }
    }


    return 0;
}
