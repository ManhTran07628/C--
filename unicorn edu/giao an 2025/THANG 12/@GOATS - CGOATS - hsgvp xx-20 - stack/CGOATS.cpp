#include<bits/stdc++.h>
using namespace std;
string s;
char c;
stack<char> st;
long long i;
int main(){
    cin>>s;
    for(i=0;i<s.size();i++){
        if(!st.empty()&&s[i]=='<'&&st.top()=='>')
            st.pop();
        else st.push(s[i]);
    }
    cout<<st.size();
return 0;
}