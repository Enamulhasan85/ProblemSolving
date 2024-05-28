#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1e9+7;
map<ll, ll> mp;
vector<ll> rmp;

/*
1000000000
I 100 200 0
Q 0
Q 1
I 100 300 1
Q 1
I 200 298 -1
Q 1
Q 2
Q 3
Q 99
Q 100
Q 101
Q 102
Q 103
Q 200
Q 100000
E
*/

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
        pre.resize(4*sz, 0);
        prev_val.resize(4*sz, 0);
        lazy.resize(4*sz, 1e10);
        lazyst.resize(4*sz, 1e10);
    }

    ll n;
    vector<ll> tree;
    vector<ll> pre;
    vector<ll> prev_val;
    vector<ll> lazy;
    vector<ll> lazyst;
    //vector<vector<pair<ll, ll>>> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==1e10) return;
        if(l!=r){
            lazy[i*2] = lazy[i];
            lazyst[i*2] = lazyst[i];
            //lazy[i*2] %= mod;
            lazy[i*2+1] = lazy[i];
            lazyst[i*2+1] = lazyst[i];
            //lazy[i*2+1] %= mod;
        }

        tree[i] = (rmp[r]-rmp[l]+1)*lazy[i];
        if(l!=lazyst[i]) prev_val[i] = lazy[i];
        if(tree[i]>0) pre[i] = tree[i];
        else pre[i] = 0;
        //tree[i] %= mod;
        lazy[i] = lazyst[i] = 1e10;
    }

    ll combine(ll a, ll b){
        return a+b;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            //lazy[i] = v[l];
            //push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);

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
            lazyst[i] = b;
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val);
        update(i*2+1, mid+1, r, b, e, val);

        tree[i] = combine(tree[i*2], tree[i*2+1]);
        tree[i] += (rmp[mid+1]-rmp[mid]-1)*prev_val[i*2+1];
        pre[i] = max(pre[i*2], tree[i*2]+(rmp[mid+1]-rmp[mid]-1)*prev_val[i*2+1]+ pre[i*2+1]);
        prev_val[i] = prev_val[i*2];
        //combineind(i, i*2, i*2+1);
    }
    void Update(ll i, ll j, ll val){
        update(1, 0, n-1, i, j, val);
    }

    ll query(ll i, ll l, ll r, ll b, ll e, ll val, ll carry){
        push(i, l, r);
        //if(b<=l and r<=e) {
        //    return tree[i];
        //}
        //if(e<l or r<b) return 0;
        if(l==r){
            ll dif = tree[i]+carry-val;
            ll ind = rmp[l];
            //cout << l << " " << ind << " " << dif << " " << prev_val[i] << endl;
            if(dif<=0) return ind;
            if(l==0 and dif>0) return 0;
            dif -= tree[i];
            ind--;
            if(dif>0){
                if(prev_val[i]!=0){
                    ind -= dif / prev_val[i];
                    if(dif%prev_val[i]) ind--;
                }
                else ind--;
            }
            return ind;
        }

        ll mid = (l+r)/2;
        push(i*2, l, mid);
        push(i*2+1, mid+1, r);
        //cout << pre[i*2] << " ";
        if(carry+pre[i*2]>val) return query(i*2, l, mid, b, e, val, carry);
        else{
            val = val-tree[i*2]-carry;
            carry = (rmp[mid+1]-rmp[mid]-1)*prev_val[i*2+1];
            return query(i*2+1, mid+1, r, b, e, val, carry);
        }
    }
    ll Query(ll i, ll j, ll val, ll carry){
        return query(1, 0, n-1, i, j, val, carry);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n;

    //vector<ll> v(n);
    //for(auto &x : v) cin >> x;

    vector<array<ll, 4>> vq;
    set<ll> vst;

    cin >> s;
    while(s != "E"){
        if(s=="I"){
            cin >> a >> b >> p;
            vst.insert(a);
            vst.insert(min(n, a+1));
            vst.insert(max(1LL, a-1));
            vst.insert(b);
            vst.insert(min(n, b+1));
            vst.insert(max(1LL, b-1));
            vq.pb({1, a, b, p});
        }
        else {
            cin >> p;
            vq.pb({2, p, 0, 0});
        }
        cin >> s;
    }

    vst.insert(1LL);
    vst.insert(n);

    ll cnt = 0;
    for(auto x : vst){
        mp[x] = cnt;
        rmp.pb(x);
        cnt++;
    }

    m = cnt;
    segtree st = segtree(m);

    for(auto x : vq){
        if(x[0] == 1){
            st.Update(mp[x[1]], mp[x[2]], x[3]);
        }
        else {
            cout << st.Query(0, m-1, x[1], 0) << endl;
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

    ll t = 1, cs = 1;
    //cin >> t;
    while(t--){
        //string str;
        //getline(cin, str);
        solve(cs++);
    }
}

