#pragma once

#include <vector>
#include <map>
#include <set>

class Graph {
public:
    class Edge;

    class Node {
    public:
        Node(int value) : value(value) {}

        int value;
        int in{0};                  // 入度
        int out{0};                 // 出度
        std::vector<Node> nexts;    // 发散出去的直接邻居
        std::vector<Edge> edges;    // 所拥有的边
    };

    // 定义的有向边，无向边可以理解是两条有向边拼的
    class Edge {
    public:
        Edge(int weight, Node from, Node to) :
                weight(weight), from(from), to(to) {}

        int weight;
        Node from;
        Node to;
    };

    std::map<int, Node> nodes; // 某些情况下，可以用数组替换哈希表map，查找会更快。
    std::set<Edge> edges;
};
