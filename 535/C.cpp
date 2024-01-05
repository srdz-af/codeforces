#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    string pt[] = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    ll n, diff = INT_MAX, sel = INT_MAX;
    string s;
    cin >> n >> s;

    for(int i = 0; i < 6; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(s[j] != pt[i][j%3]) cnt++;
        }
        if(cnt < diff){
            diff = cnt;
            sel = i;
        }
    }

    cout << diff << "\n";

    for(int i = 0; i < n; i++){
        cout << pt[sel][i%3];
    }

    cout << "\n";

    return 0;
}