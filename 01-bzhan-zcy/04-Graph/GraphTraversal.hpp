#include "GraphType.hpp"

#include <queue>
#include <stack>
#include <iostream>

// 图的宽度优先遍历 从node出发
void BFS(Graph::Node node) {
    if (node.in == 0 && node.out == 0) {
        return;
    }
    std::queue<Graph::Node> q;
    std::set<Graph::Node> s; // 保证不要重复进队列，注册机制
    q.push(node);
    s.insert(node);
    while (!q.empty()) {
        Graph::Node curNode = q.front();
        q.pop();
        // 可以加处理代码，此处只打印
        std::cout << "cur node value: " << curNode.value << std::endl;
        for (const auto &next : curNode.nexts) {
            if (s.find(next) == s.end()) {
                s.insert(next);
                q.push(next);
            }
        }
    }
}

// 图的深度优先遍历，从node出发
void DFS(Graph::Node node) {
    if (node.in == 0 && node.out == 0) {
        return;
    }
    std::stack<Graph::Node> stack_;
    std::set<Graph::Node> set_;
    stack_.push(node);
    set_.insert(node);
    // DFS加节点的时候进行处理
    std::cout << "cur node value: " << stack_.top().value << std::endl;
    while (!stack_.empty()) {
        Graph::Node curNode = stack_.top();
        stack_.pop();
        for (const auto &next : curNode.nexts) {
            if (set_.find(next) == set_.end()) {
                stack_.push(curNode); // curNode重新压入栈
                stack_.push(next);
                set_.insert(next);
                std::cout << "cur node value: " << stack_.top().value << std::endl;
                break;
            }
        }
    }
}
