#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<ll, ll, custom_hash> safemap;
typedef gp_hash_table<ll, ll, custom_hash> safehash;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordset; 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiset; 
//----------------------------------------------

pair<ll,ll> extremos[n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    ll n,m;
    cin >> n >> m;
    ll mat[n][m];

    bool sepuede =true;
    set<ll> dif;
    
    for(int i = 0; i < n; i++){
        extremos[i] = {1e9,0};
        for(int j = 0; j <m; j++){
            cin >> mat[i][j];
            dif.insert(mat[i][j]);
            extremos[i].first = min(extremos[i].first, mat[i][j]);
              extremos[i].second = max(extremos[i].second, mat[i][j]);
        }
        if(extremos[i].second - extremos[i].first != m-1 || (extremos[i].first-1)%m)sepuede = false;
    }


    if(!sepuede || dif.size()!= n*m){
        cout << "*\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        
        for(int j = 0; j <m; j++){
            mat[i][j] %= m;
        }
      
    }

    for(int i = 0; i < m; i++ ){
        for(int j = 0; j <n; j++){
            if(mat[j][i] != mat[0][i]) sepuede= false;
        }
    }
    if(!sepuede){
        cout << "*\n";
        return 0;
    }

    ll a[m];
    ll pos[m+1] = {};
    for(int i = 0; i < m; i++){
        pos[mat[0][i] - 1] = i;
    }
    for(int i  =0; i < m; i++){
        if(pos[i] != i)swap
    }


    


    
    return 0;
}