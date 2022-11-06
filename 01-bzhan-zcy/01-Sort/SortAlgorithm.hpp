#pragma once

#include <vector>
#include <limits.h>

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

void HeapInsert(std::vector<int> &arr, int index) {
    // 比父节点值大或到了0索引节点
    // (0 - 1) / 2 = 0
    while (arr[index] > arr[(index - 1) / 2]) {
        std::swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void HeapIfy(std::vector<int> &arr, int index, int heapSize) {
    int left = 2 * index + 1;
    while (left < heapSize) {
        // 两个孩子中，谁的值大，把下标给largest
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        // 父和孩子之间，谁的值大，把下标给largest
        largest = arr[largest] > arr[index] ? largest : index;
        // 父节点是最大值
        if (largest == index) {
            break;
        }
        std::swap(arr[largest], arr[index]);
        index = largest;
        left = 2 * index + 1;
    }
}

// 堆排序（一次HeapIfy找到当前最大值，放到最后）
void HeapSort(std::vector<int> &arr) {
    if (arr.size() < 2) {
        return;
    }
    // 先HeapInsert构建大根堆
    for (int i = 0; i < arr.size(); ++i) { // O(N)
        HeapInsert(arr, i); // O(logN)
    }

    // 用HeapIfy构建大根堆，从最后一个元素开始，时间复杂度更小O(N)
//    for (int i = arr.size() - 1; i >= 0; ++i) {
//        HeapIfy(arr, i, arr.size());
//    }

    int heapSize = arr.size();
    std::swap(arr[0], arr[--heapSize]);
    while (heapSize > 0) { // O(N)
        HeapIfy(arr, 0, heapSize); // O(logN)
        // 将最大值放到最后
        std::swap(arr[0], arr[heapSize - 1]); // O(1)
        --heapSize;
    }
}

// 获取最大的位数
int GetMaxBits(const std::vector<int> &arr) {
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        max = std::max(max, arr[i]);
    }
    int maxBit = 0;
    while (max) {
        max = max / 10;
        ++maxBit;
    }
    return maxBit;
}

// 获取第d位十进制的数
int GetDigit(int x, int d) {
    int res = 0;
    while (x > 0 && d > 0) {
        res = x % 10;
        x = x / 10;
        --d;
    }
    return res;
}

// 基数排序
void RadixSort(std::vector<int> &arr) {
    if (arr.size() < 2) {
        return;
    }
    int radix = 10;
    int L = 0, R = arr.size() - 1;
    // 有多少个数准备多少个辅助空间
    std::vector<int> bucket(R - L + 1);
    int digit = GetMaxBits(arr);
    // 有多少位就进出桶多少次
    for (int d = 1; d <= digit; ++d) {
        // 10个空间，count[i]代表当前位(d位)是[0-i]的数有多少个
        std::vector<int> count(10);
        // 1. 生成count数组
        for (int i = L; i <= R; ++i) {
            int num = GetDigit(arr[i], d);
            count[num]++;
        }
        // 2. 将count处理成前缀和（重要！）count[i]代表<=i的数的频次
        for (int i = 1; i < radix; ++i) {
            count[i] += count[i - 1];
        }
        // 3. 从右往左遍历arr，基于count前缀和数组进桶，刷新count
        for (int i = R; i >= L; --i) {
            int num = GetDigit(arr[i], d);
            bucket[count[num] - 1] = arr[i];
            --count[num];
        }
        // 4. 出桶
        for (int i = L, j = 0; i <= R; ++i, ++j) {
            arr[i] = bucket[j];
        }
    }
}
