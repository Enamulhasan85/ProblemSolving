#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 100000007;

void solve(ll cs){
    ll j, i, n, k, p, q;

    cin >> n >> k;
    
    vector<ll> val(n), cnt(n);
    
    for(auto &x : val) cin >> x;
    
    sort(val.begin(), val.end());
    vector<ll> dp(k+1, 0);
    
    dp[0] = 1;
    
    for(i=0;i<n;i++){
        for(p=0;p<k;p++){
            if(dp[p]>0 and p+val[i]<=k) dp[p+val[i]] += dp[p], dp[p+val[i]] %= mod;
        }
    }
    
    
    cout << "Case " << cs << ": " << dp[k]%mod << endl;
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
