#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

const ll mod = 998244353, N = 1e5 + 9;
ll t[N][18];

void build(vector<ll> v){
    ll n = v.size();
    for(ll i=0;i<n;i++) t[i][0] = v[i];
    for(ll k=1;k<18;k++){
        for(ll i=0;i+(1<<k)-1<n;i++){
            t[i][k] = min(t[i][k-1], t[i+(1<<(k-1))][k-1]);
        }
    }
}

ll query(ll l, ll r){
    ll sz = r - l + 1;
    ll k = 31 - __builtin_clz(sz);
    return min(t[l][k], t[r-(1<<k)+1][k]);
}

void solve(ll cs){
    ll n, m, a=0, x, y, k, b=0, j, i, c, q, mn = 1e12, mx;

    cin >> n >> k;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    if(k==1){
        mn = 1e18;
        for(auto x : v) mn = min(mn, x);

        cout << mn << endl;
    }
    else if(k>=3){
        mn = -1e18;
        for(auto x : v) mn = max(mn, x);

        cout << mn << endl;
    }
    else{
        mn = -1e18;
        build(v);

        for(i=0;i<n-1;i++){
            mn = max(mn, max(query(0, i), query(i+1, n-1)));
        }

        cout << mn << endl;
    }

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("watering_well_chapter_2_validation_input.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);


    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}
