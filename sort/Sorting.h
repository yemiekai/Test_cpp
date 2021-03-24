#pragma once

#ifndef _SORTING_H_
#define _SORTING_H_

void print_array(int* a, int leng); // 输出一个数组
// 插入排序
void insertSort(int* a, int leng);  
void test_insertSort();

// 选择排序
void selectSort(int* a, int leng);  
void test_selectSort();

// 快速排序
void quickSort(int arr[], int low, int high);  
void test_quickSort();

#endif