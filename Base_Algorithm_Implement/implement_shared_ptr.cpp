//
//  implement_shared_ptr.cpp
//  c++题
//
//  Created by wu hao on 2020/6/9.
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
using namespace std;
template <class T>
class shared_ptr1 {
public:
    shared_ptr1():_ptr((T*)0),_refCount(new int(0)){}
    shared_ptr1(T* p):_ptr(p),_refCount(new int(1)){}
    shared_ptr1(shared_ptr1 &others):_ptr(others._ptr),_refCount(&(++*others._refCount)){}
    virtual ~shared_ptr1(){
        if(_ptr==NULL&&*_refCount==0){
            delete _ptr;
            delete _refCount;
        }
    }
    shared_ptr1 &operator=(shared_ptr1 &others){
        if(this==&others) return others;
        if (--*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }
        ++*others._refCount;
        this->_ptr=others._ptr;
        return *this;
    }
    T& operator*() const{
        return *_ptr;
    }
    T* operator->() const{
        if(*_refCount==0){
            return (T*)0;
        }
        return _ptr;
    }
private:
    T* _ptr;
    int *_refCount;
};
int main(int argc, const char * argv[])
{
    shared_ptr1<string> pstr(new string("abc"));
    shared_ptr1<string> pstr2(pstr);
    shared_ptr1<string> pstr3(new string("hao"));
    pstr3 = pstr2;
    
    return 0;
}

