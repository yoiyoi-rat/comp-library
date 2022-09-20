
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_C"

#include "src/graph/dijkstra.hpp"

#include <iostream>

int main() {
    using ll = long long;
    int n; std::cin >> n;
    Dijkstra<ll> djk(n);
    for (int i = 0; i < n; i++) {
        int u, k; std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v; ll c; std::cin >> v >> c;
            djk.add_edge(u, v, c);
        }
    }
    djk.build(0);
    for (int i = 0; i < n; i++) {
        std::cout << i << " " << djk.dist[i] << std::endl;
    }
    return 0;
}