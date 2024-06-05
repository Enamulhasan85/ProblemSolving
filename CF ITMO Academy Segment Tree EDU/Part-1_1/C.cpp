#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 998244353;

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
        cnt.resize(4*sz, 0);
    }

    ll n;
    vector<ll> tree;
    vector<ll> cnt;

    ll combine(ll a, ll b){
        return a+b;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            tree[i] = v[l];
            cnt[i] = 1;
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        if(tree[i*2]==tree[i*2+1]) {
            tree[i] = tree[i*2];
            cnt[i] = cnt[i*2] + cnt[i*2+1];
        }
        else if(tree[i*2]>tree[i*2+1]) {
            tree[i] = tree[i*2+1];
            cnt[i] = cnt[i*2+1];
        }
        else{
            tree[i] = tree[i*2];
            cnt[i] = cnt[i*2];
        }
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val){
        //push(i, l, r);
        if(b<=l and r<=e) {
            tree[i] = val;
            cnt[i] = 1;
            //push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val);
        update(i*2+1, mid+1, r, b, e, val);
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        if(tree[i*2]==tree[i*2+1]) {
            tree[i] = tree[i*2];
            cnt[i] = cnt[i*2] + cnt[i*2+1];
        }
        else if(tree[i*2]>tree[i*2+1]) {
            tree[i] = tree[i*2+1];
            cnt[i] = cnt[i*2+1];
        }
        else{
            tree[i] = tree[i*2];
            cnt[i] = cnt[i*2];
        }
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    pair<ll, ll> query(ll i, ll l, ll r, ll b, ll e){
        //push(i, l, r);
        if(b<=l and r<=e) {
            return {tree[i], cnt[i]};
        }
        if(e<l or r<b) return {1e10, 0};
        ll mid = (l+r)/2;
        //return combine(query(i*2, l, mid, b, e), query(i*2+1, mid+1, r, b, e));
        auto pi1 = query(i*2, l, mid, b, e);
        auto pi2 = query(i*2+1, mid+1, r, b, e);
        if(pi1.fi==pi2.fi) {
            return {pi1.fi, pi1.se+pi2.se};
        }
        else if(pi1.fi>pi2.fi) {
            return {pi2.fi, pi2.se};
        }
        else{
            return {pi1.fi, pi1.se};
        }
    }
    pair<ll, ll> Query(ll i, ll j){
        return query(1, 0, n-1, i, j);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n >> q;

    vector<ll> v(n);

    for(auto &x : v) cin >> x;

    segtree st = segtree(n+1);

    st.Build(v);

    while(q--){
        cin >> k;
        if(k==1){
            cin >> i >> mn;
            st.Update(i, i, mn);
        }
        else {
            cin >> a >> b;
            auto pi = st.Query(a, b-1);
            cout << pi.fi << " " << pi.se << endl;
        }
    }

    //cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("output3.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output6.txt", "w", stdout);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        //string str;
        //getline(cin, str);
        solve(cs++);
    }
}
