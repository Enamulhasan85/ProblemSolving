#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1e9+7;

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
        pre.resize(4*sz, 0);
        suf.resize(4*sz, 0);
        cnt.resize(4*sz, 0);
        lazy.resize(4*sz, 0);
    }

    ll n;
    vector<ll> tree;
    vector<ll> pre;
    vector<ll> suf;
    vector<ll> cnt;
    vector<ll> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==0) return;
        if(l!=r){
            lazy[i*2] += lazy[i];
            //lazy[i*2] %= mod;
            lazy[i*2+1] += lazy[i];
            //lazy[i*2+1] %= mod;
        }

        ll len = r-l+1;
        tree[i] += ((len*(len+1))/2)*lazy[i];
        cnt[i] += len*lazy[i];
        //tree[i] %= mod;
        lazy[i] = 0;
    }

    pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b){
        return b;
    }

    void combineind(ll i, ll l, ll r){
        return ;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            lazy[i] = v[l];
            push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);

        tree[i] = tree[i*2]+tree[i*2+1]+(mid-l+1)*cnt[i*2+1];
        cnt[i] = cnt[i*2]+cnt[i*2+1];

        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i<<1, (i<<1)|1, l, r);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            lazy[i] = val;
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val);
        update(i*2+1, mid+1, r, b, e, val);

        tree[i] = tree[i*2]+tree[i*2+1]+(mid-l+1)*cnt[i*2+1];
        cnt[i] = cnt[i*2]+cnt[i*2+1];
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i*2, i*2+1);
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    pair<ll, ll> query(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            return {tree[i], cnt[i]};
        }
        if(e<l or r<b) return {0, 1e18};

        ll mid = (l+r)/2;
        auto pi1 = query(i*2, l, mid, b, e, val);
        auto pi2 = query(i*2+1, mid+1, r, b, e, val);
        if(pi1.se==1e18) return pi2;
        if(pi2.se==1e18) return pi1;

        ll len = mid-max(l, b)+1;
        pi1.fi += pi2.fi + pi2.se*len;
        pi1.se += pi2.se;
        return pi1;
    }
    pair<ll, ll> Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n >> q;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    segtree st = segtree(n);

    st.Build(v);
    //cin >> q;

    while(q--){
        cin >> k;
        if(k==1) {
            cin >> a >> b >> p;
            a--, b--;

            st.Update(a, b, p);
        }
        else{
            cin >> a >> b;
            a--, b--;
            //cout << st.Query(a, b, 0) << endl;
            auto pi = st.Query(a, b, 0);
            cout << pi.fi << endl;
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

