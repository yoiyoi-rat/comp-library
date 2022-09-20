---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <vector>\n#include <utility>\
    \ \n#include <limits>\n#include <queue>\n#include <iostream>\n\ntemplate < typename\
    \ T >\nstruct Dijkstra {\n    struct edge {\n        int to;\n        T cost;\n\
    \        bool operator>(const edge &e) const { return cost > e.cost; }\n    };\n\
    \n    int n;\n    std::vector<std::vector<edge>> G;\n    std::vector<T> dist,\
    \ from;\n    Dijkstra (int n) : n(n), G(n), dist(n, std::numeric_limits<T>::max()),\
    \ from(n, -1) {}\n    \n    void add_edge(int u, int v, T c) {\n        edge e\
    \ = {v, c};\n        G[u].push_back(e);\n    }\n\n    T operator[] (int v) { return\
    \ dist[v]; }\n\n    void build(int s) {\n        dist[s] = 0;\n        std::priority_queue\
    \ < edge, std::vector<edge>, std::greater<edge>> pq;\n        pq.push({s, dist[s]});\n\
    \        while(!pq.empty()) {\n            edge p = pq.top(); pq.pop();\n    \
    \        int v = p.to;\n            if(p.cost > dist[v]) continue;\n         \
    \   for(edge e : G[v]) {\n                if(dist[e.to] > dist[v] + e.cost) {\n\
    \                    dist[e.to] = dist[v] + e.cost;\n                    from[e.to]\
    \ = v;\n                    pq.push({e.to, dist[e.to]});\n                }\n\
    \            }\n        }\n    }\n};\n"
  code: "#include <vector>\n#include <utility> \n#include <limits>\n#include <queue>\n\
    #include <iostream>\n\ntemplate < typename T >\nstruct Dijkstra {\n    struct\
    \ edge {\n        int to;\n        T cost;\n        bool operator>(const edge\
    \ &e) const { return cost > e.cost; }\n    };\n\n    int n;\n    std::vector<std::vector<edge>>\
    \ G;\n    std::vector<T> dist, from;\n    Dijkstra (int n) : n(n), G(n), dist(n,\
    \ std::numeric_limits<T>::max()), from(n, -1) {}\n    \n    void add_edge(int\
    \ u, int v, T c) {\n        edge e = {v, c};\n        G[u].push_back(e);\n   \
    \ }\n\n    T operator[] (int v) { return dist[v]; }\n\n    void build(int s) {\n\
    \        dist[s] = 0;\n        std::priority_queue < edge, std::vector<edge>,\
    \ std::greater<edge>> pq;\n        pq.push({s, dist[s]});\n        while(!pq.empty())\
    \ {\n            edge p = pq.top(); pq.pop();\n            int v = p.to;\n   \
    \         if(p.cost > dist[v]) continue;\n            for(edge e : G[v]) {\n \
    \               if(dist[e.to] > dist[v] + e.cost) {\n                    dist[e.to]\
    \ = dist[v] + e.cost;\n                    from[e.to] = v;\n                 \
    \   pq.push({e.to, dist[e.to]});\n                }\n            }\n        }\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-09-20 18:58:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
title: Dijkstra
---

## 使い方
考えるな、感じろ