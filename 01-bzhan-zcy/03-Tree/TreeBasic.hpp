#include <iostream>

int preVal = INT_MIN; // 全局变量

// 判断是否搜索二叉树
bool isBST(TreeNode *head) {
    if (head == nullptr) {
        return true;
    }
    bool isLeftBST = isBST(head->left);
    if (!isLeftBST) {
        return false;
    }
    if (head->val <= preVal) { // 搜索二叉树没有重复大小值的节点
        return false;
    } else {
        preVal = head->val;
    }
    return isBST(head->right);
}

// 是否完全二叉树
bool isCBT(TreeNode *head) {
    if (head == nullptr) {
        return true;
    }
    // 是否遇到过左右两个孩子不双全的节点
    bool isLeaf = false;
    std::queue<TreeNode *> q;
    q.push(head);
    while (!q.empty()) {
        head = q.front();
        q.pop();
        TreeNode *left = head->left;
        TreeNode *right = head->right;
        // 有右孩子没有左孩子
        if (left == nullptr && right != nullptr) {
            return false;
        }
        // 遇到了第一个左右孩子不全的节点，后续节点不是叶子节点。
        if (isLeaf && (left != nullptr || right != nullptr)) {
            return false;
        }
        if (left) {
            q.push(left);
        }
        if (right) {
            q.push(right);
        }
        // 第一个左右孩子不双全的节点
        if (left == nullptr || right == nullptr) {
            isLeaf = true;
        }
    }
    return true;
}

class Info {
public:
    Info(int h, int n) : height(h), nodes(n) {}

    int height{0};
    int nodes{0};
};

Info isFBTProcess(TreeNode *head) {
    if (head == nullptr) {
        return Info(0, 0);
    }
    Info leftData = isFBTProcess(head->left);
    Info rightData = isFBTProcess(head->right);
    int height = std::max(leftData.height, rightData.height) + 1;
    int nodes = leftData.nodes + rightData.nodes + 1;
    return Info(height, nodes);
}

// 是否满二叉树
bool isFBT(TreeNode *head) {
    Info info = isFBTProcess(head);
    return info.nodes == (1 << info.height) - 1;
}
