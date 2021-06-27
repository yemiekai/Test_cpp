/*
******************
*  各种排序算法
******************
*/
#include <iostream>
#include "Sorting.h"

using namespace std;

/**
 * 稳定排序：冒泡，插入，归并
*/


/*********************************************************************
**  打印数组
**********************************************************************/
void print_array(int* a, int leng) {
	for (int i = 0; i < leng; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

/*********************************************************************
** 插入排序(从小到大)
** https://blog.csdn.net/LLZK_/article/details/51628574

** int* a: 指向一个数组
** int leng: 数组的长度
**********************************************************************/
void insertSort(int* a, int leng) {
	if (leng < 2) {
		return;
	}

	int i;
	int j;
	int tmp;

	// 从第2个数字开始遍历
	for (i = 1; i < leng; i++) {
		tmp = a[i];  // 待排序的数字
		j = i - 1;  // 和前面的比较

		// 和前面所有的数比较, 比tmp大的都往后移一位
		while (j >= 0 && tmp < a[j]) {
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = tmp;  // 位置合适, 插入
	}
}

void test_insertSort() {
	int* a = new int[7]{ 5, 4, 1, 6, 3, 2, 7 };
	print_array(a, 7);
	insertSort(&a[0], 7);
	print_array(a, 7);
}

/*********************************************************************
** 选择排序(从小到大)
** https://blog.csdn.net/changhangshi/article/details/82740541
**********************************************************************/
void selectSort(int* a, int leng) {
	int min_index = 0;  // 最小值的索引
	int current = 0;  // 当前位置
	int i;
	
	while (current < (leng-1)) {
		i = current;
		min_index = current;  // current前面都是已经排好的

        // 遍历current后面, 找到最小的数
		while (i < leng) {
			min_index = a[i] < a[min_index] ? i : min_index;
			i++;
		}

		swap(a[current], a[min_index]);
		current++;
	}

}

void test_selectSort() {
	int* a = new int[7]{ 5, 4, 1, 6, 3, 2, 7 };
	print_array(a, 7);
	selectSort(&a[0], 7);
	print_array(a, 7);
}

/**********************************************************************
** 快速排序(从小到大排)
**********************************************************************/
void quickSort(int arr[], int low, int high) {
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];  // 基准值
	while (true)
	{
		/*从左向右找比key大的值, （小的跳过, 小的要保持在左边）*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*从右向左找比key小的值，（大的跳过）*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}

		if (i >= j) {
			break;
		}

		/*交换i,j对应的值*/
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	/*
	 * 基准值与j对应值交换  
	 * 经过一轮while循环, j左边都比基准值小, 右边都比基准值大, 所以基准值要放到j的地方
	**/
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;

	// 下一轮排序
	quickSort(arr, low, j - 1);
	quickSort(arr, j + 1, high);
}

void mer_sort(int* arr, int left, int right, int mid) {
	int* arr_tmp = new int[left - right + 1];
	int l = left;
	int r = mid +1;
	int i = 0;

	while (l <= mid && r <= right) {
		arr_tmp[i++] = arr[l] < arr[r] ? arr[l++] : arr[r++];
	}
	while (l <= mid) {
		arr_tmp[i++] = arr[l++];
	}
	while (r <= right) {
		arr_tmp[i++] = arr[r++];
	}

	for (int j = 0; j <= i; j++) {
		arr[left + j] = arr_tmp[j];
	}

	delete[] arr_tmp;
}


/**********************************************************************
** 归并排序(从小到大排)
**********************************************************************/
void mer(int* arr, int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	mer(arr, left, mid);  // 分割
	mer(arr, mid + 1, left);  // 分割
	mer_sort(arr, left, right, mid);  // 合并
}


void test_quickSort()
{
	int a[] = { 7, 6, 5, 2, 1, 0, 9, 8, 24 };

	quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/

	print_array(a, sizeof(a) / sizeof(a[0]));

}