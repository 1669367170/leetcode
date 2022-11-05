#include "SortAlgorithm.hpp"
#include <gtest/gtest.h>

class TestArray {
public:
    TestArray() = default;
    ~TestArray() = default;

    std::vector<int> truth;
    std::vector<int> input;
};

class SortTest : public ::testing::Test {
protected:
    void SetUp() override {
        testArray.truth = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        testArray.input = {2, 3, 1, 4, 6, 8, 9, 7, 5};
    }

    // void TearDown() override {}
    TestArray testArray;
};


TEST_F(SortTest, Selection) {
    SelectionSort(testArray.input);
    EXPECT_EQ(testArray.input, testArray.truth);
}

TEST_F(SortTest, Bubble) {
    BubbleSort(testArray.input);
    EXPECT_EQ(testArray.input, testArray.truth);
}

TEST_F(SortTest, Insert) {
    InsertSort(testArray.input);
    EXPECT_EQ(testArray.input, testArray.truth);
}

TEST_F(SortTest, Merge) {
    MergeSort(testArray.input, 0, testArray.input.size() - 1);
    EXPECT_EQ(testArray.input, testArray.truth);
}

TEST_F(SortTest, Quick) {
    QuickSort(testArray.input, 0, testArray.input.size() - 1);
    EXPECT_EQ(testArray.input, testArray.truth);
}
