#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        bool xd = false;
        ll n, k, lpos, r;
        cin >> n >> k;
        k = min(k, n);
        lpos = n-1;
        r = k;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        while(r--){
            cout << lpos << " ";
            if(arr[lpos] == n) break;
            if((n+arr[lpos])%n != arr[lpos] || arr[lpos] > n){
                cout << "No\n";
                xd = true;
                break;
            } else {
                lpos = (n+(lpos-arr[lpos]))%n;
            }
        }
        if(!xd) cout << "Yes\n";

    }

    return 0;
}