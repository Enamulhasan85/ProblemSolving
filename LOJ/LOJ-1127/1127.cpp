#includebitsstdc++.h
#define fi first
#define se second
#define pb push_back
#define endl 'n'

using ll = long long;
using namespace std;

ll mod = 100000007;

void allcom(vectorll &v, ll n, vectorll &set, ll k){
    
    for(ll i=1;i(1n);i++){
        ll tmp = i, j = 0, sum = 0;
        while(tmp!=0){
            if(tmp&1) sum += v[j];
            j++;
            tmp=1;
        }
        if(sum=k) set.pb(sum);
    }
    
}

void solve(ll cs){
    ll j, i, n, m, k, p, q, a, b;

    ll l, r;
    cin  n  k;
    
    vectorll v(n), v1, v2;
    for(auto &x  v) cin  x;
    
    for(i=0;in;i++){
        if(in2) v1.pb(v[i]);
        else v2.pb(v[i]);
    }
    
    vectorll set1, set2;
    
    allcom(v1, v1.size(), set1, k);
    allcom(v2, v2.size(), set2, k);
        
    ll ans = set1.size() + set2.size() + 1;
   
    sort(set2.begin(), set2.end());
    for(auto x  set1){
        ll idx = upper_bound(set2.begin(), set2.end(), k-x) - set2.begin();
        cout  idx   ;
        ans += idx;
        
    }
    
    cout  Case    cs     ans  endl;
}

int main(){
    ios_basesync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    seive(1e6+2);
    For getting input from input.txt file
    freopen(output3.txt, r, stdin);

    Printing the Output to output.txt file
    freopen(output6.txt, w, stdout);


    ll t=1, cs=1;
    cin  t;
    while(t--){
        solve(cs++);
    }
}
