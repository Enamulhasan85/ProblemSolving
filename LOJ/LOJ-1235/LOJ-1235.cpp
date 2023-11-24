#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 100000007;

void allcom(vector<ll> &v, ll n, vector<ll> &set, ll kk){
    queue<ll> q;
    q.push(0);
    for(ll j=0;j<n;j++){
        ll m = q.size();
        for(ll k=0;k<m;k++){
            for(ll i=0;i<=2;i++){
                set.pb(q.front()+v[j]*i);
                q.push(q.front()+v[j]*i);
            }
            q.pop();
        }
    }
    
}

void solve(ll cs){
    ll j, i, n, m, k, p, q, a, b;

    ll l, r;
    cin >> n >> k;
    
    vector<ll> v(n), v1, v2;
    for(auto &x : v) cin >> x;
    
    for(i=0;i<n;i++){
        if(i<n/2) v1.pb(v[i]);
        else v2.pb(v[i]);
    }
    
    vector<ll> set1, set2;
    
    allcom(v1, v1.size(), set1, k);
    allcom(v2, v2.size(), set2, k);
        
    unordered_map<ll, ll> mp;
    
    for(auto x : set2){
        mp[x] = 1;
    }
    
    bool ans = false;
    for(auto x : set1){
        if(mp[k-x] or x==k){
            ans = true;
            break;
        }
    }
    
    cout << "Case " <<  cs << ": ";
    if(ans or mp[k]) cout << "Yes\n";
    else cout << "No\n";
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("output3.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output6.txt", "w", stdout);


    ll t=1, cs=1;
    cin >> t;
    while(t--){
        solve(cs++);
    }
}
