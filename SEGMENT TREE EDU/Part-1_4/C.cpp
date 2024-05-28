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
        tree.resize(4*sz, vector<ll> (41, 0));
        cnt.resize(4*sz, 0);
        lazy.resize(4*sz, 0);
    }

    ll n;
    vector<vector<ll>> tree;
    vector<ll> cnt;
    vector<ll> lazy;

    ll combine(ll a, ll b){
        return a+b;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            tree[i][v[l]]++;
            //lazy[i] = v[l];
            //push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);

        for(ll j=1;j<=40;j++) tree[i][j] = tree[i*2][j] + tree[i*2+1][j];
        ll inv_cnt = 0;
        cnt[i] = cnt[i*2] + cnt[i*2+1];
        for(ll j=1;j<=40;j++) {
            cnt[i] += tree[i*2][j]*inv_cnt;
            inv_cnt += tree[i*2+1][j];
        }
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, l, mid+1, i<<1, i<<1|1);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val, ll val2){
        //push(i, l, r);
        if(b<=l and r<=e) {
            tree[i][val]++;
            tree[i][val2]--;
            //lazy[i] = val;
            //push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val, val2);
        update(i*2+1, mid+1, r, b, e, val, val2);
        for(ll j=1;j<=40;j++) tree[i][j] = tree[i*2][j] + tree[i*2+1][j];
        ll inv_cnt = 0;
        cnt[i] = cnt[i*2] + cnt[i*2+1];
        for(ll j=1;j<=40;j++) {
            cnt[i] += tree[i*2][j]*inv_cnt;
            inv_cnt += tree[i*2+1][j];
        }
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i<<1, i<<1|1);
    }
    void Update(ll i, ll j, ll val, ll val2){
        update(1, 0, n-1, i, j, val, val2);
    }

    pair<ll, vector<ll>> query(ll i, ll l, ll r, ll b, ll e, ll val){
        //push(i, l, r);
        if(b<=l and r<=e) {
            return {cnt[i], tree[i]};
        }
        if(e<l or r<b) return {0, vector<ll> (41, 0)};

        ll mid = (l+r)/2;

        pair<ll, vector<ll>> pi1 = query(i*2, l, mid, b, e, val);
        pair<ll, vector<ll>> pi2 = query(i*2+1, mid+1, r, b, e, val);

        pair<ll, vector<ll>> pi = {0, vector<ll>(41)};
        for(ll j=1;j<=40;j++) pi.se[j] = pi1.se[j] + pi2.se[j];
        ll inv_cnt = 0;
        pi.fi = pi1.fi + pi2.fi;
        for(ll j=1;j<=40;j++) {
            pi.fi += pi1.se[j]*inv_cnt;
            inv_cnt += pi2.se[j];
        }
        return pi;
        //return combine(query(i*2, l, mid, b, e, val), query(i*2+1, mid+1, r, b, e, val));
    }
    pair<ll, vector<ll>> Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n >> q;

    vector<ll> v(n);

    for(auto &x : v) cin >> x;

    segtree st = segtree(n);

    st.Build(v);

    //cin >> q;
    while(q--){
        cin >> k;

        if(k==2) {
            cin >> a >> b;
            a--;
            st.Update(a, a, b, v[a]);
            v[a] = b;
        }
        else{
            cin >> a >> b;
            a--, b--;
            auto it = st.Query(a, b, 0);
            cout << it.fi << endl;
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

