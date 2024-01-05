#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t;
    cin >> t;

    while(t--){
        ll n, k, lp = LLONG_MAX, llp;
        cin >> n;
        llp = n;
        priority_queue<pair<ll, ll>> ord;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ord.push({arr[i], i});
        }

        while(!ord.empty()){

            if(ord.top().second >= lp){
                ord.pop();
                continue;
            }

            lp = ord.top().second;
            ord.pop();

            for(int i = lp; i < llp; i++){
                cout << arr[i] << " ";
            }

            llp = lp;
        }

        cout << "\n";
    }

    return 0;
}