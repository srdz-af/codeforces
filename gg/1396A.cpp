#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll n;
    cin >> n;
    
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    if(n == 1){
        cout << 1 << " " << 1 << "\n" << -arr[0] << "\n";
        cout << 1 << " " << 1 << "\n" << 0 << "\n";
        cout << 1 << " " << 1 << "\n" << 0 << "\n";
        return 0;
    }

    cout << 1 << " " << n << "\n";
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << n*((n-1)-(arr[i]%(n-1)));
        arr[i] += n*((n-1)-(arr[i]%(n-1)));
    }
    cout << "\n";
    cout << 1 << " " << n-1 << "\n";
    for(int i = 0; i < n-1; i++){
        if(i) cout << " ";
        cout << -arr[i];
    }
    cout << "\n";
    cout << n << " " << n << "\n" << -arr[n-1] << "\n";

    return 0;
}