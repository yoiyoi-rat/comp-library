---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_C
  bundledCode: "#line 1 \"test/dijkstra.test.cpp\"\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_C\"\
    \n\n#line 1 \"src/graph/dijkstra.hpp\"\n#include <vector>\n#include <utility>\
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
    \            }\n        }\n    }\n};\n#line 5 \"test/dijkstra.test.cpp\"\n\n#line\
    \ 7 \"test/dijkstra.test.cpp\"\n\nint main() {\n    using ll = long long;\n  \
    \  int n; std::cin >> n;\n    Dijkstra<ll> djk(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        int u, k; std::cin >> u >> k;\n        for (int j = 0; j < k;\
    \ j++) {\n            int v; ll c; std::cin >> v >> c;\n            djk.add_edge(u,\
    \ v, c);\n        }\n    }\n    djk.build(0);\n    for (int i = 0; i < n; i++)\
    \ {\n        std::cout << i << \" \" << djk.dist[i] << std::endl;\n    }\n   \
    \ return 0;\n}\n"
  code: "\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_C\"\
    \n\n#include \"src/graph/dijkstra.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    using ll = long long;\n    int n; std::cin >> n;\n    Dijkstra<ll> djk(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int u, k; std::cin >> u >> k;\n  \
    \      for (int j = 0; j < k; j++) {\n            int v; ll c; std::cin >> v >>\
    \ c;\n            djk.add_edge(u, v, c);\n        }\n    }\n    djk.build(0);\n\
    \    for (int i = 0; i < n; i++) {\n        std::cout << i << \" \" << djk.dist[i]\
    \ << std::endl;\n    }\n    return 0;\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-09-20 18:58:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/dijkstra.test.cpp
- /verify/test/dijkstra.test.cpp.html
title: test/dijkstra.test.cpp
---
