#include "TreeTraversal.hpp"
#include "TreeBasic.hpp"
#include <gtest/gtest.h>

class TreeTestData {
public:
    TreeTestData() = default;

    ~TreeTestData() = default;

    TreeNode *head;
};

class TreeGTesT : public ::testing::Test {
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
        treeTestData.head = treeNodes[0];
    }

    // void TearDown() override {}
    TreeTestData treeTestData;
};

TEST_F(TreeGTesT, TravelSal) {
    std::cout << "PreOrderRecur: ";
    PreOrderRecur(treeTestData.head);
    std::cout << "\nPreOrderUnRecur: ";
    PreOrderUnRecur(treeTestData.head);
    std::cout << std::endl;

    std::cout << "InOrderRecur: ";
    InOrderRecur(treeTestData.head);
    std::cout << "\nInOrderUnRecur: ";
    InOrderUnRecur(treeTestData.head);
    std::cout << std::endl;

    std::cout << "PosOrderRecur: ";
    PosOrderRecur(treeTestData.head);
    std::cout << "\nPosOrderUnRecur: ";
    PosOrderUnRecur(treeTestData.head);
    std::cout << std::endl;

    std::cout << "Width First Search: ";
    WFS(treeTestData.head);
    std::cout << std::endl;
}

TEST_F(TreeGTesT, Basic) {
    EXPECT_FALSE(isBST(treeTestData.head));
    EXPECT_TRUE(isCBT(treeTestData.head));
    EXPECT_TRUE(isFBT(treeTestData.head));

    std::string serailByPreStr = SerialByPre(treeTestData.head);
    std::cout << "SerialByPre: " << serailByPreStr << std::endl;
    EXPECT_EQ(DeSerialByPre(serailByPreStr)->val, treeTestData.head->val);
}
