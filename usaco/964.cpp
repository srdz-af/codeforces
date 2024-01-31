#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    ll n, ans;
    string s;
    
    cin >> n >> s;

    for(int i = 1; i <= n; i++){
        bool f = true;
        set<string> st;
        string aux = "";

        for(int j = 0; j < i; j++){
            aux += s[j];
        }
        
        st.insert(aux);

        for(int j = 0; j < n-i; j++){
            aux.erase(aux.begin());
            aux += s[j+i];
            if(st.count(aux)){
                f = false;
                break;
            }
            st.insert(aux);
        }

        if(f){ 
            cout << i << "\n";
            break;
        }
    }

    return 0;
}