// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (value == arr[i] + arr[j]) {
                sum++;
            }
        }
    }
    return sum;
}

int countPairs2(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len-1; j > i; --j) {
            if (value == arr[i] + arr[j]) {
                sum++;
            }
        }
    }
    return sum;
}

int countPairs3(int* arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (left < right - 1) {
        int middle;
        middle = (right + left) / 2;
        if (arr[i] + arr[middle] == value) {
            result++;
            int j;
            j = middle + 1;
            while ((arr[i] + arr[j] == value) && (j < right)) {
                result++;
                j++;
            }
            j = middle - 1;
            while ((arr[i] + arr[j] == value) && (j > left)) {
                result++;
                j--;
            }
            break;
            } else if (arr[i] + arr[middle] > value) {
                right = middle;
            } else {
                left = middle;
            }
        }
    }
    return result;
}
