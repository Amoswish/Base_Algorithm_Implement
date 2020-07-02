//
//  quickSort.cpp
//  c++题
//
//  Created by wu hao on 2020/6/8.
//  Copyright © 2020 wu hao. All rights reserved.
//
#include <iostream>
#include <algorithm>

using namespace std;
void Qsort(int arr[], int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high ;
    int key = arr[low];
    while (1)
    {
        /*从左向右找比key大的值*/
        while (arr[i] <= key&&i<high) i++;
        /*从右向左找比key小的值*/
        while (arr[j] >= key&&j>low) j--;
        if (i >= j) break;
        /*交换i,j对应的值*/
        swap(arr[i],arr[j]);
    }
    /*中枢值与j对应值交换*/
    swap(arr[low],arr[j]);
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main()
{
    int a[] = {0,1,1,2,4,4,1,3,3,2};
    
    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/
    
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
