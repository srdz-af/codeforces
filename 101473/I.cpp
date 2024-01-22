#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define rep(i,a,n) for(int (i)=(a);(i) < (n);i++)
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
typedef long long ll;
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

vll mem;
vll a;
ll n, c, a1,a2;
ll dp(ll i)
{
    if(i==n-1) return min(a1,a2);
    if(i>n) return 0;

    if(mem[i]==-1)
    {
        auto aux1=upper_bound(all(a),a[i]+a1);
        auto aux2=upper_bound(all(a),a[i]+a2);
        ll pos1=ll(aux1-a.begin());
        ll pos2=ll(aux2-a.begin());
        //cout << "estoy en " << i <<" "<< pos1 <<" " <<pos2<<"\n";
        
        mem[i]=min(a1+dp(pos1),a2+dp(pos2));
    }
    return mem[i];
        
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> n >> c >> a1 >> a2;
    a.resize(n);
    vll aux(n);
    rep(i,0,n) cin >> aux[i];
    ll mini=1e9;
    //cout << a.end()-a.begin()<<" ";
    rep(i,0,n)
    {
               rep(k,0,n)
        {
            mem.clear();
            mem.resize(n,-1);
            if(k+i<n)
                a[k]=aux[k+i];
            else{
                a[k]=c+aux[(k+i)%n];
                //if(i == 1)a[k]=a[n-1] + c-a[n-1]+aux[i-1];
                //else a[k]=a[n-1] + c-a[n-1]+aux[i] - aux[i-1];
            } 
        }
        //rep(k,0,n) cout << a[k] <<" ";
        //cout <<"\n";
            mini=min(dp(0),mini);
        
        //cout << "Minimo primer punto: "<<mini <<"\n";
        
        
   }
    cout << mini<<"\n";
    
    return 0;
}