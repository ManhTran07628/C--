#include <bits/stdc++.h>
using namespace std;
string cong_so_lon(string s1, string s2){
while (s1.size()<s2.size())
    s1='0'+s1;
while (s2.size()<s1.size())
    s2='0'+s2;
int i=s1.size()-1,sus=0;
string s="";
while (i>= 0){
    int k=(s1[i]-48)+(s2[i]-48)+sus;
    if (k<=9){
        sus=0;
        s=char(k+48)+s;
    }
    else{
        sus=1;
        k%=10;
        s=char(k+48)+s;
    }
    i--;

}
if (sus==1)
    s='1'+s;
    return s;
}
string x,y;
int main(){
cin>>x>>y;
cout<<cong_so_lon(x,y);
return 0;
}