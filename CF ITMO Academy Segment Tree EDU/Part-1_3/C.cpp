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
        lazy.resize(4*sz, -1);
    }

    ll n;
    vector<ll> tree;
    vector<ll> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==-1) return;
        if(l!=r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        tree[i] = lazy[i];
        lazy[i] = -1;
    }

    ll combine(ll a, ll b){
        return a+b;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            //tree[i] = v[l];
            lazy[i] = 0;
            push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i<<1, i<<1|1);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            //tree[i] = val;
            lazy[i] = val;
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val);
        update(i*2+1, mid+1, r, b, e, val);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i<<1, i<<1|1);
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    ll query(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            return tree[i];
        }
        if(e<l or r<b) return 0;
        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e, val), query(i*2+1, mid+1, r, b, e, val));
    }
    ll Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n;

    n *= 2;
    vector<ll> v(n);

    for(auto &x : v) cin >> x;

    segtree st = segtree(n);

    st.Build(v);

    vector<ll> v1(n/2, 0), v2(n/2, -1);
    for(i=0;i<n;i++){
        if(v2[v[i]-1]==-1){
            v2[v[i]-1] = i;
        }
        else{
            ll ans = st.Query(v2[v[i]-1], i, 0);
            st.Update(v2[v[i]-1], v2[v[i]-1], 1);
            v1[v[i]-1] = ans;
        }
    }

    for(auto x : v1) cout << x << " ";

    /*
    while(q--){
        cin >> k >> a >> b;

        if(k==1) st.Update(a, a, b);
        else cout << st.Query(b, n-1, a) << endl;
    }*/

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
