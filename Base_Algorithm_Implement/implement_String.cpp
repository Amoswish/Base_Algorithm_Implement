//
//  implement_String.cpp
//  c++题
//
//  Created by wu hao on 2020/6/26.
//  Copyright © 2020 wu hao. All rights reserved.
//

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
    String(const char* str);//默认构造
    String(const String& str);//拷贝构造
    String& operator=(const String& str);//赋值函数
    ~String();//析构
    char* m_data;
};

String::String(const char* str)
{
    if (str == NULL)
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
    else
    {
        m_data = new char[strlen(str)+1];
        strcpy(m_data, str);
    }
}

String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String & String::operator=(const String &str)
{
    //String A;
    //String B = A;
    if (this == &str)
    {
        return *this;
    }
    //删除原来地数据
    delete[]m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

String::~String()
{
    delete[]m_data;
    m_data = NULL;
}

int main()
{
    String A("THIS IS WORLD");
    String C(A);
    String B("少说两句废话，多敲几行代码");
    C = B;
    
    cout << "hello" << endl;
    cout << "A.m_data:" << A.m_data << endl;
    cout << "C.m_data:" << C.m_data << endl;
    cout << "B.m_data:" << B.m_data << endl;
    return 0;
}
