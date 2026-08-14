#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int lim = 10;
int n;

struct Node
{
    Node *child[10];
    int cnt = 0,exist = 0;

    Node(void) {for(int i = 0;i <= 9;i++) child[i] = nullptr;}
};

Node *root;

void createNode(void) {root = new Node();}

void add_num(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - '0'] == nullptr) p -> child[c - '0'] = new Node();
        p = p -> child[c - '0'];
        p -> cnt++;
    }
    p -> exist++;
}


void query(int k)
{
    Node *p = root;
    string ans;
    while(1) {
        if(p -> exist >= k) break;
        p -= p -> exist;

        for(int i = 0;i <= 9;i++) {
            if(p -> child[i] == nullptr) continue;
            if(p -> child[i] -> cnt >= k) {
                ans += char(i + '0');
                p = p -> child[i];
                break;
            }
            k -= p -> child[i] -> cnt;
        }
    }

    reverse(ans.begin(),ans.end());
    while(ans[ans.size()-1] == '0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    while(n--) {
        int type,k;
        cin >> type >> k;
        if(type == 1) {
            string s = to_string(k);
            while(s.size() < lim) s = '0' + s;
            add_num(s);
        }
        else {
            query(k);
        }
    }
    return 0;
}