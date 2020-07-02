//
//  heapSort.cpp
//  c++题
//
//  Created by wu hao on 2020/6/8.
//  Copyright © 2020 wu hao. All rights reserved.
//


//大根堆
void maxHeapify(vector<int>& arr,int root,int length){
    int left = 2*root +1;
    int right = 2*root +2;
    int max = root;
    if(left<length&&arr[left]>arr[max]){
        max = left;
    }
    if(right<length&&arr[right]>arr[max]){
        max = right;
    }
    if(max!=root){
        swap(arr[max],arr[root]);
        heapify(arr,max,length);
    }
    return;
}
//小根堆
void minHeapify(vector<int>& arr,int root,int length){
    int left = 2*root +1;
    int right = 2*root +2;
    int min = root;
    if(left<length&&arr[left]<arr[min]){
        min = left;
    }
    if(right<length&&arr[right]<arr[min]){
        min = right;
    }
    if(max!=root){
        swap(arr[min],arr[root]);
        heapify(arr,min,length);
    }
    return;
}
void createHeap(vector<int>& arr){
    int length = arr.size();
    for(int i = length/2-1;i>=0;i--){
//        maxHeapify(arr,i,length);
//        minHeapify(arr,i,length);
    }
}
void HeapySort(vector<int>& arr){
    int length = arr.size();
    for(int i = length-1;i>=0;i--){
        swap(arr[0],arr[i]);
//        minHeapify(arr,0,i);
//        maxHeapify(arr,0,i);
    }
    }
