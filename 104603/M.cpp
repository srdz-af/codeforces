#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define F first
#define S second
#define vll vector<ll>
#define rep(i,k,x) for(ll i=k;i<x;i++)
using namespace std;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    ll n = 0;
    double t, prate, nprate;
    double ans = 0;
    cin >> n >> t;

    prate = t*0.75;
    nprate = t*0.25;

    priority_queue<double> pfiles;
    priority_queue<double> npfiles;
    
    rep(i, 0, n){
        char tp; double x;
        cin >> tp >> x;

        if(tp == 'P') pfiles.push(-x);
        else npfiles.push(-x);
        
    }

    double pac = 0;
    double npac = 0;

    while(!pfiles.empty() && !npfiles.empty()){
        
       // cout << -pfiles.top() << " " << pac << " " << -npfiles.top() << " " << npac << " " << ans << " \n";

        if((-pfiles.top() - pac) / (prate/pfiles.size()) < (-npfiles.top() - npac) / (nprate/npfiles.size())){
            double aux = (-pfiles.top() - pac) / (prate/pfiles.size());
            ans += aux;
            pac += -pfiles.top() - pac;
            npac += aux * (nprate/npfiles.size());
            pfiles.pop();
        } else {
            double aux = (-npfiles.top() - npac) / (nprate/npfiles.size());
            ans += aux;
            npac += -npfiles.top() - npac;
            pac += aux * (prate/pfiles.size());
            npfiles.pop();

        }

    }

    //cout << -pfiles.top() << " " << pac << " " << -npfiles.top() << " " << npac << " " << ans << " \n";
    
    //cout << npfiles.size() << "size \n";
    if(!pfiles.empty()){
        
        prate = t;
        while(!pfiles.empty()){
            //cout << "pf " << -pfiles.top() << " " << pac << " \n";
            ans += (-pfiles.top() - pac) / (prate/pfiles.size());
            pac += -pfiles.top() - pac;
            pfiles.pop();
            //cout << ans << "\n";
        }
    }

    if(!npfiles.empty()){
        nprate = t;
        while(!npfiles.empty()){
            //cout << "npf " << -npfiles.top() << " " << npac << " \n";
            ans += (-npfiles.top() - npac) / (nprate/npfiles.size());
            npac += -npfiles.top()-npac;
            npfiles.pop();
            //cout << ans << "\n";
        }
    }

    cout << fixed << setprecision(8) << ans << "\n";
    return 0;
}