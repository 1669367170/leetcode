#pragma once

#include <vector>

// 选择排序 (一次遍历后，将最小的元素放到最前)
void SelectionSort(std::vector<int> &a) {
    if (a.size() < 2) {
        return;
    }
    for (int i = 0; i < a.size(); ++i) { // i ~ n-1
        int minIndex = i;
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
//        a[i] = a[i] ^ a[minIndex];
//        a[minIndex] = a[i] ^ a[minIndex];
//        a[i] = a[i] ^ a[minIndex];
        std::swap(a[i], a[minIndex]);
    }
}

// 冒泡排序 (遍历0~n-1的元素，两两比较，一次遍历后将最大的元素放到最后)
void BubbleSort(std::vector<int> &a) {
    if (a.size() < 2) {
        return;
    }
    for (int end = a.size() - 1; end > 0; --end) {
        for (int i = 0; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
            }
        }
    }
}

// 插入排序 (遍历0~i的元素，若i-1位置的元素>i位置元素，则交换，最小元素放到最前。一次遍历后保证0~i有序)
void InsertSort(std::vector<int> &a) {
    if (a.size() < 2) {
        return;
    }
    // 0~0有序
    // 0~i想有序
    for (int i = 1; i < a.size(); ++i) { // 0 ~ i做到有序
        for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; --j) { // 往前找
            std::swap(a[j], a[j + 1]);
        }
    }
}

void Merge(std::vector<int> &a, int l, int r) {
    std::vector<int> help(r - l + 1);
    int mid = l + ((r - l) >> 1);
    int i = 0, p1 = l, p2 = mid + 1; // p1从l开始，p2从mid+1开始拷贝
    while (p1 <= mid && p2 <= r) {
        help[i++] = a[p1] <= a[p2] ? a[p1++] : a[p2++];
    }
    while (p1 <= mid) {
        help[i++] = a[p1++];
    }
    while (p2 <= r) {
        help[i++] = a[p2++];
    }
    for (int i = 0; i < help.size(); ++i) {
        a[l + i] = help[i];
    }
}

// 归并排序 O(NlogN)
/* master公式：T(N) = a * T(N/b) + O(N ^ d)
 1）log(b, a) > d  -> 复杂度为O(N ^ log(b, a))   b为底
 2）log(b, a) == d -> 复杂度为O(N ^ d * log N)
 3）log(b, a) < d -> 复杂度为O(N ^ d)*/
void MergeSort(std::vector<int> &a, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    MergeSort(a, 0, mid);     // 排序左边
    MergeSort(a, mid + 1, r); // 排序右边
    Merge(a, l, r);             // 合并
}

void Partion(std::vector<int> &a, int left, int right) {
    if (left >= right) {
        return;
    }
    int l = left, r = right;
    int target = a[left];
    while (left < right) {
        // 从右往左找到第一个小于目标数的数
        while (left < right && a[right] >= target) {
            --right;
        }
        a[left] = a[right];
        // 从左往右找到第一个大于目标数的数
        while (left < right && a[left] <= target) {
            ++left;
        }
        a[right] = a[left];
    }
    a[left] = target; // 基准位置
    Partion(a, l, left);
    Partion(a, left + 1, r);
}

// 快排母函数
void QuickSort(std::vector<int> &a, int left, int right) {
    if (left >= right) {
        return;
    }
    Partion(a, left, right);
}
