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
    vll frec(4,33);
    rep(i,0,n)
    {
        ll x; cin >> x;
        frec[(x%5)]++;
        
    }
    ll cont=frec[0];

    if(frec[2] && frec[3]){
        ll aux=min(frec[2],frec[3]);
        cont+=min(frec[2],frec[3]);
        frec[2]-=aux;
        frec[3]-=aux;
    }
    if(frec[1] && frec[4]){
        ll aux=min(frec[1], frec[4]);
        cont+=min(frec[1],frec[4]);
        frec[1]-=aux;
        frec[4]-=aux;
    }
    if(frec[1] && frec[2])
    {
        while(frec[1] && frec[2]>1)
        {
            cont++;
            frec[1]--;
            frec[2]-=2;
        }
        while(frec[1]>=3 && frec[2])
        {
            cont++;
            frec[1]-=3;
            frec[2]--;
        }
        
        
    }
    else if(frec[1] && frec[3])
    {
        while(frec[3] && frec[1]>1)
        {
            cont++;
            frec[3]--;
            frec[1]-=2;
        }
        while(frec[3]>=3 && frec[1])
        {
            cont++;
            frec[3]-=3;
            frec[1]--;
        }
        
        
    }
    else if( frec[2] && frec[4])
    {
        while(frec[2] && frec[4]>1)
        {
            cont++;
            frec[2]--;
            frec[4]-=2;
        }
        while(frec[2]>=3 && frec[4])
        {
            cont++;
            frec[2]-=3;
            frec[4]--;
        }
        
        
    }
    else if(frec[3] && frec[4])
    {
        while(frec[4] && frec[3]>1)
        {
            cont++;
            frec[4]--;
            frec[3]-=2;
        }
        while(frec[4]>=3 && frec[3])
        {
            cont++;
            frec[4]-=3;
            frec[3]--;
        }
        
        
    }
    cont+=frec[1]/5;
    cont+=frec[2]/5;
    cont+=frec[3]/5;
        cont+=frec[4]/5;
    cout << cont <<"\n";
    return 0;
}