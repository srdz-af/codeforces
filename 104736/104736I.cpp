#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll arr[26];

ll modmul(ll a, ll b, ll M) {
    ll ret = a * b - M * ll(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll n, inv = 0, inv2 = 0; 
    string s;
    cin >> s >> n;

    for(auto it: s){
        arr[it-'a']++;
        for(ll i = 25; i > (it - 'a'); i--){
            inv += arr[i];
        }
    }

    for(ll i = 0; i < 26; i++){
        for(ll j = i+1; j < 26; j++){
            inv2 = (inv2 + modmul(arr[i], arr[j], MOD))%MOD;
        }
    }

    if(n%2) cout << (modmul(n, inv, MOD) + modmul(inv2, (modmul(n, (n-1)/2, MOD)), MOD))%MOD << "\n";
    else cout << (modmul(n, inv, MOD) + modmul(inv2, (modmul(n/2, (n-1), MOD)), MOD))%MOD << "\n";
    return 0;
}