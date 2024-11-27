#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ticketPrices(n);
    vector<int> maxPrices(m);

    for (int i = 0; i < n; i++) {
        cin >> ticketPrices[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> maxPrices[i];
    }


    multiset<int> tickets(ticketPrices.begin(), ticketPrices.end());

    for (int i = 0; i < m; i++) {
        int maxPrice = maxPrices[i];

        auto it = tickets.upper_bound(maxPrice);
        if (it == tickets.begin()) {
            cout << -1 << endl; 
        } else {
            --it; 
            cout << *it << endl;
            tickets.erase(it); 
        }
    }
}

int main() {
    solve();
    return 0;
}