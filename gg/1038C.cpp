#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t, aux;
    ll scores[2] = {0, 0};
    bool player = 1;
    priority_queue<ll> lists[2];
    cin >> t;

    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < t; j++){
            cin >> aux;
            lists[i].push(aux);
        }
    }
    
    while(!lists[0].empty() || !lists[1].empty()){

        player = !player;

        if(lists[player].empty()){
            lists[!player].pop();
            continue;
        }

        if(lists[!player].empty()){
            scores[player] += lists[player].top();
            lists[player].pop();
            continue;
        }

        if(lists[player].top() >= lists[!player].top()){
            scores[player] += lists[player].top();
            lists[player].pop();
        } else {
            lists[!player].pop();
        }
    }

    cout << scores[0] - scores[1] << "\n";
    return 0;
}