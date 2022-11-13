#include "TreeTraversal.hpp"
#include <gtest/gtest.h>

class TreeGTest {
public:
    TreeGTest() = default;

    ~TreeGTest() = default;

    TreeNode *head;
};

class TreeTravelSalTest : public ::testing::Test {
protected:
    void SetUp() override {
        const int TREENODE_NUM = 7;
        std::vector<TreeNode *> treeNodes;
        for (int i = 1; i <= TREENODE_NUM; ++i) {
            TreeNode *treeNode = new TreeNode;
            treeNode->val = i;
            treeNode->left = nullptr;
            treeNode->right = nullptr;
            treeNodes.emplace_back(treeNode);
        }
        for (int i = 0; i < TREENODE_NUM; ++i) {
            // 左孩子
            if (2 * i + 1 >= TREENODE_NUM) {
                treeNodes[i]->left = nullptr;
                continue;
            } else {
                treeNodes[i]->left = treeNodes[2 * i + 1];
            }
            // 右孩子
            if (2 * i + 2 >= TREENODE_NUM) {
                treeNodes[i]->right = nullptr;
                continue;
            } else {
                treeNodes[i]->right = treeNodes[2 * i + 2];
            }
        }
        // 或者通过treeNode->left->left..来构建
        treeGTest.head = treeNodes[0];
    }

    // void TearDown() override {}
    TreeGTest treeGTest;
};

TEST_F(TreeTravelSalTest, BASIC) {
    std::cout << "PreOrderRecur: ";
    PreOrderRecur(treeGTest.head);
    std::cout << "\nPreOrderUnRecur: ";
    PreOrderUnRecur(treeGTest.head);
    std::cout << std::endl;

    std::cout << "InOrderRecur: ";
    InOrderRecur(treeGTest.head);
    std::cout << "\nInOrderUnRecur: ";
    InOrderUnRecur(treeGTest.head);
    std::cout << std::endl;

    std::cout << "PosOrderRecur: ";
    PosOrderRecur(treeGTest.head);
    std::cout << "\nPosOrderUnRecur: ";
    PosOrderUnRecur(treeGTest.head);
    std::cout << std::endl;

    std::cout << "Width First Search: ";
    WFS(treeGTest.head);
    std::cout << std::endl;
}
