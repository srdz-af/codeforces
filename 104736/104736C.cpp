#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 400005;
ll P = 0x9e3779b9;
ll freq[MAXN];
ll P_pow[MAXN];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 

    ll n, k, zc, hash = 0;
    cin >> n >> k;
    zc = k;

    unordered_map<ll, vector<ll>> hashf;
    hashf[0] = {-1, -1};

    P_pow[0] = 1;
    for(ll i = 1; i < k; i++){
        P_pow[i] = P_pow[i-1]*P;
    }

    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a; a--;
        if(freq[a] == 0) zc--;
        freq[a]++; 
        hash = hash + P_pow[a];

        if(!zc){
            hash = 0;
            for(ll j = 0; j < k; j++){
                freq[j]--;
                hash += freq[j]*P_pow[j];
                if(freq[j] == 0) zc++;
            }
        }

        hashf[hash].push_back(i);
    }

    ll dmax = 0;

    for(auto it: hashf){
        dmax = max(dmax, it.second[it.second.size()-1]-it.second[0]);
    }

    cout << dmax << "\n";

    return 0;
}

