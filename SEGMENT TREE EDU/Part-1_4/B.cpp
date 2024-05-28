#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define pll pair<ll, ll>


using namespace std;
using ll = long long;

ll mod = 998244353;

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, {{0, 0}, {0, 0}});
        lazy.resize(4*sz, {{0, 0}, {0, 0}});
    }

    ll n;
    vector<pair<pll, pll>> tree;
    vector<pair<pll, pll>> lazy;

    void push(ll i, ll l, ll r){
        pair<pll, pll> vc = {{0, 0}, {0, 0}};
        if(lazy[i]==vc) return;
        if(l!=r){
            //lazy[i*2] += lazy[i];
            //lazy[i*2+1] += lazy[i];
        }
        tree[i] = lazy[i];
        lazy[i] = {{0, 0}, {0, 0}};
    }

    pair<pll, pll> combine(pair<pll, pll> a, pair<pll, pll> b){
        pair<pll, pll> res;
        res.fi.fi = (a.fi.fi*b.fi.fi + a.fi.se*b.se.fi)%mod;
        res.fi.se = (a.fi.fi*b.fi.se + a.fi.se*b.se.se)%mod;
        res.se.fi = (a.se.fi*b.fi.fi + a.se.se*b.se.fi)%mod;
        res.se.se = (a.se.fi*b.fi.se + a.se.se*b.se.se)%mod;
        return res;
    }

    void build(ll i, ll l, ll r, vector<pair<pll, pll>> &v){
        if(l==r) {
            //tree[i] = v[l];
            lazy[i] = v[l];
            push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, l, mid+1, i<<1, i<<1|1);
    }
    void Build(vector<pair<pll, pll>> &v){
        build(1, 0, n-1, v);
    }

    pair<pll, pll> query(ll i, ll l, ll r, ll b, ll e, ll val){
        //push(i, l, r);
        if(b<=l and r<=e) {
            return tree[i];
        }
        if(e<l or r<b) return {{1, 0}, {0, 1}};
        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e, val), query(i*2+1, mid+1, r, b, e, val));
    }
    pair<pll, pll> Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }

};

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> mod >> n >> q;

    vector<pair<pll, pll>> v(n);

    for(auto &x : v) {
        cin >> x.fi.fi;
        cin >> x.fi.se;
        cin >> x.se.fi;
        cin >> x.se.se;
    }


    segtree st = segtree(n);

    st.Build(v);

    //cin >> q;
    while(q--){
        cin >> a >> b;
        a--;
        b--;
        auto it = st.Query(a, b, 0);

        cout << it.fi.fi << " " << it.fi.se << endl;
        cout << it.se.fi << " " << it.se.se << endl;
        cout << endl;
    }


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

