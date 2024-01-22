#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
#define MAXN 505
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

ll n, m,op,a,b;
ll edad[MAXN];
ll minimo[MAXN];
ll apuntan[MAXN];
ll vis[MAXN];
vector<ll> ar[MAXN];
map<int,int> real_id;

void calcularMinimos(){
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        minimo[i] = -1;
    }
    queue<int> lista;
    for(int i = 0; i < n; i++){
        if(apuntan[i] == 0){
            lista.push(i);
            minimo[i] = edad[i];
        }
    }

    while(lista.size()){
        ll act = lista.front();
        lista.pop();
        //cout << "ESTOY EN EL " << act << '\n';
        for(auto it: ar[act]){
            vis[it]++;
            if(vis[it] == apuntan[it])lista.push(it);

            if(minimo[it] == -1)minimo[it] = min(minimo[act], edad[act]);
            else minimo[it] = min(minimo[act], min(minimo[it], edad[act]));
            //cout << "VISITO EL " <<it << "Y SU MINIMO ACTUAL ES " << minimo[it] << '\n';
        }
    }

    //cout << '\n' << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    

    

    cin >> n >> m >> op;
    for(int i =  0; i < n ; i++){
        cin >> edad[i];
        minimo[i] = -1;
    }
    

    for(int i  = 0; i < m; i++){
        cin >> a >> b;
        a--;b--;
        apuntan[b]++;
        ar[a].push_back(b);
    }
    calcularMinimos();

    

    char operacion;
    for(int i = 0; i < op; i++){
        cin >> operacion;
        if(operacion == 'P'){
            cin >> a;
            a--;
            if(apuntan[a]  == 0)cout << "*\n";
            else cout << minimo[a] << '\n';
        }else{
            cin >> a >> b;
            a--;b--;
            vector<int> aux;

            swap(apuntan[a],apuntan[b]);
            
            for(auto it: ar[a])aux.push_back(it);
            ar[a].clear();
            for(auto it: ar[b])ar[a].push_back(it);
            ar[b].clear();
            for(auto it: aux)ar[b].push_back(it);

            for(int i = 0; i < n; i++){
                ll tam = ar[i].size();
                for(int j = 0; j < tam; j++){
                    if(ar[i][j] == a)ar[i][j]= b;
                    else if(ar[i][j] == b)ar[i][j] = a;
                }
            }
            
            calcularMinimos(); 
        }
    }
    
    return 0;
}