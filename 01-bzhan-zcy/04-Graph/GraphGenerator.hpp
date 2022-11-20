#include "GraphType.hpp"

Graph CreateGraph(std::vector<std::vector<int>> matrix) {
    Graph graph;
    for (int i = 0; i < matrix.size(); ++i) {
        int from = matrix[i][0];
        int to = matrix[i][1];
        int weight = matrix[i][2];
        // 1.图的点集合
        if (graph.nodes.find(from) != graph.nodes.end()) {
            Graph::Node node = Graph::Node(from);
            graph.nodes.emplace(from, node);
        }
        if (graph.nodes.find(to) != graph.nodes.end()) {
            Graph::Node node = Graph::Node(to);
            graph.nodes.emplace(to, node);
        }
        Graph::Node fromNode = graph.nodes.at(from);
        Graph::Node toNode = graph.nodes.at(to);
        Graph::Edge newEdge = Graph::Edge(weight, fromNode, toNode);
        // 1.1 入节点相关数据项
        fromNode.nexts.emplace_back(toNode);
        fromNode.out++;
        fromNode.edges.emplace_back(newEdge);
        // 1.2 出节点相关数据项
        toNode.in++;
        // 2.图的边集合
        graph.edges.emplace(newEdge);
    }
    return graph;
}
