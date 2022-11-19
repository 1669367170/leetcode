#pragma once

#include <iostream>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

// 递归序
void Recur(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    // 第1次来到head节点
    Recur(head->left);
    // 第2次来到head节点
    Recur(head->right);
    // 第3次来到head节点
}

// 先序遍历-递归版
void PreOrderRecur(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    std::cout << head->val << " ";
    PreOrderRecur(head->left);
    PreOrderRecur(head->right);
}

// 中序遍历-递归版
void InOrderRecur(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    InOrderRecur(head->left);
    std::cout << head->val << " ";
    InOrderRecur(head->right);
}

// 后序遍历-递归版
void PosOrderRecur(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    PosOrderRecur(head->left);
    PosOrderRecur(head->right);
    std::cout << head->val << " ";
}

// 先序遍历-非递归版
void PreOrderUnRecur(TreeNode *treeNode) {
    if (treeNode == nullptr) {
        return;
    }
    std::stack<TreeNode *> s;
    s.push(treeNode);
    while (!s.empty()) {
        TreeNode *cur = s.top();
        s.pop();
        std::cout << cur->val << " ";
        if (cur->right) {
            s.push(cur->right);
        }
        if (cur->left) {
            s.push(cur->left);
        }
    }
}

// 中序遍历-非递归版
void InOrderUnRecur(TreeNode *treeNode) {
    if (treeNode == nullptr) {
        return;
    }
    std::stack<TreeNode *> s;
//    s.push(treeNode);
    while (!s.empty() || treeNode != nullptr) {
        if (treeNode) { // 注意判断条件是node自身
            s.push(treeNode);
            treeNode = treeNode->left;
        } else {
            treeNode = s.top();
            s.pop();
            std::cout << treeNode->val << " ";
            treeNode = treeNode->right;
        }
    }
}

// 后序遍历-非递归版
void PosOrderUnRecur(TreeNode *treeNode) {
    if (treeNode == nullptr) {
        return;
    }
    std::stack<TreeNode *> s;
    std::stack<TreeNode *> sHelper;
    s.push(treeNode);
    while (!s.empty()) {
        TreeNode *cur = s.top();
        s.pop();
        sHelper.push(cur);
        if (cur->left) {
            s.push(cur->left);
        }
        if (cur->right) {
            s.push(cur->right);
        }
    }

    while (!sHelper.empty()) {
        std::cout << sHelper.top()->val << " ";
        sHelper.pop();
    }
}

// 宽度优先遍历(层序遍历)
void WFS(TreeNode *treeNode) {
    if (treeNode == nullptr) {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(treeNode);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        std::cout << cur->val << " ";
        q.pop();
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
    }
}
