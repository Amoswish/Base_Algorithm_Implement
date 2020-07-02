//
//  D.cpp
//  c++题
//
//  Created by wu hao on 2020/6/18.
//  Copyright © 2020 wu hao. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
bool existRemainder(int source[], int n);
int main()
{
    int Calculate(const int numerator, const int denominator, char *decimaltostring);
    int n, m;
    char p[103];
    cin >> n >> m;
    cout << Calculate(n, m, p) << endl;
    cout << p << endl;
    
    return 0;
}

int Calculate(const int numerator, const int denominator, char *decimaltostring)
{
    if (denominator == 0)
        return -1;
    if (numerator % denominator == 0)
    {
        decimaltostring[0] = numerator / denominator + '0';
        return 0;
    }
    int remainder[110] = { 0 }; //保存余数
    int decimal[110] = { 0 };   //保存小数部分
    remainder[0] = numerator % denominator;
    decimaltostring[0] = numerator / denominator + '0';
    decimaltostring[1] = '.';
    int rlable = 0;
    int dlable = 0;
    int i, j;
    while (1)
    {
        if (dlable == 100)
        {
            remainder[rlable] = -1; //置为-1,未整除但小数超过100位，也不加括号，题目中没说清楚
            break;
        }
        decimal[dlable++] = remainder[rlable] * 10 / denominator;
        remainder[rlable + 1] = remainder[rlable] * 10 % denominator;
        rlable++;
        if (remainder[rlable - 1] * 10 % denominator == 0)// if(!remainder[rlable])即可
        {
            remainder[rlable] = -1; //置为-1标志整除
            break;
        }
        if (existRemainder(remainder, rlable))
            break;
    }
    if (remainder[rlable] == -1)
    {
        for (i = 0, j = 2; i < dlable; i++, j++)
        {
            decimaltostring[i] = numerator / denominator + '0';
        }
    }
    else
    {
        decimaltostring[2] = '(';
        for (i = 0, j = 3; i < dlable; i++, j++)
        {
            decimaltostring[j] = decimal[i] + '0';
        }
        decimaltostring[j] = ')';
    }
    return 0;
}
bool existRemainder(int source[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (source[n] == source[i])
            return true;
    }
    return false;
}
//实现的想法：保存每次的余数，然后用 余数*10 再除以除数，得到余数后，在所保存的余数数组中查找，如果没有，则继续，如果已经出现了该余数，说明接下来会出现循环了，则跳出循环。

