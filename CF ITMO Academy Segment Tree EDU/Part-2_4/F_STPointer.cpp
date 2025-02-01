#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1e9+7;

struct node{
    ll l, r, mid, tree, pre, op;
    node *left, *right;
    node(ll s, ll e){
        l = s, r = e;
        mid = (l+r)/2;
        left = right = NULL;
        tree = pre = 0;
        op = 1e10;
    }

    void push(ll k){
        op = k;
        tree = op*(r-l+1);
        pre = max(0LL, tree);
    }

    void prop(){
        if(l==r) return;
        if(left==NULL) left = new node(l, mid);
        if(right==NULL) right = new node(mid+1, r);
        if(op==1e10) return;
        left->push(op);
        right->push(op);
        op = 1e10;
    }

    void combine(){
        tree = left->tree + right->tree;
        pre = max(left->pre, left->tree+right->pre);
    }

    void build(vector<ll> &v){
        prop();
        if(l==r) {
            push(v[l]);
            return;
        }
        left->build(v);
        right->build(v);
        combine();
    }

    void update(ll b, ll e, ll val){
        if(e<l or r<b) return;
        if(b<=l and r<=e) {
            push(val);
            return;
        }
        prop();
        left->update(b, e, val);
        right->update(b, e, val);
        combine();
    }

    ll query(ll b, ll e, ll val){
        //push(i, l, r);
        //if(b<=l and r<=e) {
        //    return tree;
        //}
        //if(e<l or r<b) return 0;
        //cout << l << " " << r << " " << tree << endl;
        if(l==r){
            //cout << pre << " " << val;
            return l-(pre>val);
        }
        prop();
        if(left->pre>val) return left->query(b, e, val);
        else return right->query(b, e, val-(left->tree));
        //ll lr = left->query(b, e, val);
        //ll rr = right->query(b, e, val);
        //return combine(lr, rr);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, g, mn = 0, sum, mx = 0;

    cin >> n ;
    node st = node(1, n);

    char ch;
    cin >> ch;
    while(ch!='E'){
        if(ch=='I'){
            cin >> a >> b >> d;
            st.update(a, b, d);
        }
        else{
            cin >> k;
            mn = st.query(1, n, k);
            cout << mn << endl;
        }
        cin >> ch;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t = 1, cs = 1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}

