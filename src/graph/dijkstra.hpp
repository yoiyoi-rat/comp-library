#include <vector>
#include <utility> 
#include <limits>
#include <queue>
#include <iostream>

template < typename T >
struct Dijkstra {
    struct edge {
        int to;
        T cost;
        bool operator>(const edge &e) const { return cost > e.cost; }
    };

    int n;
    std::vector<std::vector<edge>> G;
    std::vector<T> dist, from;
    Dijkstra (int n) : n(n), G(n), dist(n, std::numeric_limits<T>::max()), from(n, -1) {}
    
    void add_edge(int u, int v, T c) {
        edge e = {v, c};
        G[u].push_back(e);
    }

    T operator[] (int v) { return dist[v]; }

    void build(int s) {
        dist[s] = 0;
        std::priority_queue < edge, std::vector<edge>, std::greater<edge>> pq;
        pq.push({s, dist[s]});
        while(!pq.empty()) {
            edge p = pq.top(); pq.pop();
            int v = p.to;
            if(p.cost > dist[v]) continue;
            for(edge e : G[v]) {
                if(dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    from[e.to] = v;
                    pq.push({e.to, dist[e.to]});
                }
            }
        }
    }
};
