    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main(){
        ios::sync_with_stdio(false);
    	cin.tie(0),cout.tie(0);
     
        ll t;
        cin >> t;
     
        while(t--){
            ll n, m;
            cin >> n >> m;
     
            if((n > m) || (!n%2 && m%2)){
                cout << "NO\n";
                continue;
            }

            if(n%2 == 1){
                cout << "YES\n";
                for(int i = 0; i < n-1; i++) cout << "1 ";
                cout << m-(n-1) << "\n";
            } else if(n%2 == 0 && m%2 == 0){
                cout << "YES\n";
                for(int i = 0; i < n-2; i++) cout << "1 ";
                cout << (m-(n-2))/2 << " " << (m-(n-2))/2 << "\n";
            } else {
                cout << "NO\n";
            }
        }
     
        return 0;
    }