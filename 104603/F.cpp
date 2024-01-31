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
double f(int x, int y, int x2, int y2)
{
    return sqrt(pow(x-x2,2)+pow(y-y2,2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n; cin >> n;
    ll w,l,x,y;
    cin >> w >> l >> x >> y;
    set<double> a,b;
    rep(i,0,n)
    {
        ll x2,y2;
        cin >> x2 >> y2;
        double aux=f(x,y,x2,y2);
        a.insert(aux);
    }
    rep(i,0,n)
    {
        ll x2,y2;
        cin >> x2 >> y2;
        double aux=f(x,y,x2,y2);
        b.insert(aux);
    }
    if(*a.begin()<*b.begin())
    {
        cout << "A ";
        ll cont=0;
        for(auto it : a)
        {
            if(it<*b.begin())
                cont++;
            else break;
        }
        cout << cont <<"\n";
    }
    else
    {
        cout << "R ";
        ll cont=0;
        for(auto it : b)
        {
            if(it<*a.begin())
                cont++;
            else break;
        }
        cout << cont <<"\n";
    }
    return 0;
}