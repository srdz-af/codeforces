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


ll red[100005];
ll blue[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    ll  n,m;
    cin >> n >> m;

    ll arr[n];
    ll arr2[m];
    vector<ll> act;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    ll aux = arr2[0];
    act.push_back(aux);

    for(int i  = 1; i< m; i++){
        if(arr2[i] < aux){
            aux=arr2[i];
            act.push_back(aux);
        }
    }

    reverse(act.begin(), act.end());

    //for(auto it: act)cout << it << ' ';
    //cout << '\n';

    for(int i = 0; i < n; i++){
        ll aux = arr[i];
        while(true){
            if(lower_bound(act.begin(), act.end(), aux) == act.end()){
                aux %= act[act.size() - 1];
             //cout << "aqui " << aux << '\n';
            }else{
                ll pos = lower_bound(act.begin(), act.end(), aux) - act.begin();
                if(act[pos] > aux){
                    if(pos == 0)break;
                    else pos--;
                }
                aux %= act[pos];
                //cout << "aqui 2 " << aux << '\n';
            }
        }
        cout << aux << " ";
    }
    cout << '\n';

    return 0;
}