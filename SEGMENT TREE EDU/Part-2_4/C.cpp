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
        lazy.resize(4*sz, -1);
    }

    ll n;
    vector<ll> tree;
    vector<ll> pre;
    vector<ll> suf;
    vector<ll> cnt;
    vector<ll> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==-1) return;
        if(l!=r){
            lazy[i*2] = lazy[i];
            //lazy[i*2] %= mod;
            lazy[i*2+1] = lazy[i];
            //lazy[i*2+1] %= mod;
        }

        if(lazy[i]==0){
            tree[i] = pre[i] = suf[i] = cnt[i] = 0;
        }
        else{
            tree[i] = r-l+1;
            pre[i] = 1;
            suf[i] = 1;
            cnt[i] = 1;
        }
        //tree[i] %= mod;
        lazy[i] = -1;
    }

    tuple<ll, ll, ll, ll> combine(tuple<ll, ll, ll, ll> a, tuple<ll, ll, ll, ll> b){
        if(get<0>(a)==-1) return b;
        if(get<0>(b)==-1) return a;

        tuple<ll, ll, ll, ll> t;
        get<0>(t) =  get<0>(a) + get<0>(b);
        get<1>(t) =  get<1>(a);
        get<2>(t) =  get<2>(b);
        get<3>(t) =  get<3>(a) + get<3>(b);
        if(get<2>(a)==1 and get<1>(b)==1) get<3>(t)--;
        return t;
    }

    void combineind(ll i, ll l, ll r){
        tree[i] = tree[l]+tree[r];
        cnt[i] = cnt[l]+cnt[r];
        pre[i] = pre[l];
        suf[i] = suf[r];
        if(suf[l]==1 and pre[r]==1) cnt[i]--;
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

        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, l, mid+1, i<<1, i<<1|1);
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
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        combineind(i, i*2, i*2+1);
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    tuple<ll, ll, ll, ll> query(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            return {tree[i], pre[i], suf[i], cnt[i]};
        }
        if(e<l or r<b) return {-1, 0, 0, 0};

        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e, val), query(i*2+1, mid+1, r, b, e, val));
    }
    tuple<ll, ll, ll, ll> Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> q;

    //vector<ll> v(n);
    //for(auto &x : v) cin >> x;

    n = 1e6;
    segtree st = segtree(n);

    //st.Build(v);
    //cin >> q;

    while(q--){
        //cin >> k;
        char ch;
        cin >> ch >> i >> a;
        i += 5e5;
        j = i+a-1;
        if(ch=='W'){
            st.Update(i, j, 0);
        }
        else{
            st.Update(i, j, 1);
        }

        auto pi = st.Query(0, n-1, 0);
        cout << get<3>(pi) << " " << get<0>(pi) << endl;
        /*
        if(k==1) {
            cin >> a >> b >> p >> d;
            a--, b--;

            st.Update(a, b, p, d);
        }
        else{
            cin >> a;
            a--;
            cout << st.Query(a, a, 0) << endl;
        }*/
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

