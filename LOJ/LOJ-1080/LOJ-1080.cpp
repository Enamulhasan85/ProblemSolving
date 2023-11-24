#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define mod 1e9+7

using namespace std;

struct node{
    ll info;
    node(){
        info = 0;
    }
};

vector<node*> seg;
vector<ll> v;
string s;

void init(ll pt, ll l, ll r){
    if(l==r){
        seg[pt] = new node();
        return;
    }
    ll mid = (l+r)/2;
    init(2*pt, l, mid);
    init(2*pt+1, mid+1, r);
    //seg[node].val = seg[2*node].val + seg[2*node+1].val;
    seg[pt] = new node();
}

ll query(ll pt, ll l, ll r, ll i, ll j, ll cur = 0){
    if(i<=l and r<=j){
        cur += seg[pt]->info;
        if(s[l]=='1'){
            if(cur%2) return 0;
            else return 1;
        }
        else{
            if(cur%2) return 1;
            else return 0;
        }
    }
    if(r<i or j<l) return 0;
    ll mid = (l+r)/2;
    ll left = query(2*pt, l, mid, i, j, cur+seg[pt]->info);
    ll right = query(2*pt+1, mid+1, r, i, j, cur+seg[pt]->info);
    return left+right;
}

void update(ll pt, ll l, ll r, ll i, ll j){
    if(i<=l and r<=j){
        seg[pt]->info = ((seg[pt]->info)+1)%2;
        return;
    }
    if(r<i or j<l) return;
    ll mid = (l+r)/2;
    update(2*pt, l, mid, i, j);
    update(2*pt+1, mid+1, r, i, j);

}

void solve(ll cs){
    ll n, m, i, z, q, h, w, e, k=1, j;

    cin >> s >> q;
    n = s.size();
    v = vector<ll>(n, 0);
    seg = vector<node*>(10*n);

    init(1, 0, n-1);
    cout << "Case " << cs << ": " << endl;
    while(q--){
        char ch;
        cin >> ch;
        if(ch=='I'){
            cin >> i >> j;
            update(1, 0, n-1, i-1, j-1);
        }
        else{
            cin >> i;
            ll ans = query(1, 0, n-1, i-1, i-1);
            cout << ans << endl;
        }
    }
    for(auto x : seg) delete x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    ll t=1, cs=1;
    cin >> t;
    string s;
    while(t--){
        //getline(cin, s);
        solve(cs++);
    }
}
