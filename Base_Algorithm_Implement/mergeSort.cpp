//
//  mergeSort.cpp
//  c++题
//
//  Created by wu hao on 2020/6/14.
//  Copyright © 2020 wu hao. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include <map>
#include<unordered_map>
#include<stack>
#include<thread>
#include<mutex>
#include<cstring>
#include<cstdlib>
using namespace std;
/**将a开头的长为length的数组和b开头长为right的数组合并n为数组长度，用于最后一组*/
void Merge(int* data,int leftbegin,int rightbegin,int leftlength,int n){
    int rightlength;
    if(rightbegin+leftlength >= n) rightlength = n-rightbegin;
    else rightlength = leftlength;
    int* lefttemp = new int[leftlength];
    memcpy(lefttemp,data+leftbegin,leftlength * sizeof(int));
    int* righttemp = new int[rightlength];
    memcpy(righttemp,data+rightbegin,rightlength * sizeof(int));
    int l=0, r=0;
    while(l<leftlength && r<rightlength){
        if(lefttemp[l]<righttemp[r]){
            data[leftbegin] = lefttemp[l];
            l++;
        }
        else{
            data[leftbegin] = righttemp[r];
            r++;
        }
        leftbegin++;
    }
    if(r == rightlength){//a中还有元素，且全都比b中的大,a[i]还未使用
        memcpy(data + leftbegin, lefttemp+l, (leftlength - l) * sizeof(int));
    }
    else if(l == leftlength){
        memcpy(data + leftbegin, righttemp+r, (rightlength - r)*sizeof(int));
    }
    delete[] lefttemp;
    delete[] righttemp;
}
void MergeSort(int* data, int n){
    for(int step = 1;step < n;step*=2){
        for(int i=0; i<n-step; i+=2*step)
            //i+step < n
            Merge(data, i, i+step, step, n);
        //将i和i+step这两个有序序列进行合并
        //序列长度为step
        //当i以后的长度小于或者等于step时，退出
        //在按某一步长归并序列之后，步长加倍
    }
}
int main(void){
    int arr[] = {5,1,1,2,0,0};
    MergeSort(arr,sizeof(arr)/sizeof(int));
    for(int i = 0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<' ';
    }
}
