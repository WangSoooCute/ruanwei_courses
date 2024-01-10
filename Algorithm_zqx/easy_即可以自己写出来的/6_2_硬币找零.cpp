#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int m=100-n;

    int money[5]={
        50,20,10,5,1
    };
    
    int cnt=0;
    for(int i=0;i<5;i++){
        if(m==0){
            cout<<cnt<<endl;
            return 0;
        }
        cnt+=m/money[i];
        m%=money[i];
    }
    cout<<cnt<<endl;
    return 0;
}

/*
Description:
Alice在学校的小店里工作，她的任务是售卖各种小零食和饮料。每当有顾客购买商品并付款后，她需要给顾客找零。在小店中，找零硬币的面值有1、5、10、20和50。Alice想要通过使用最少的硬币数量来找零，这样既可以减少小店的零钱消耗，又可以方便顾客。
现在，假设一个顾客购买的商品总价是(100 - n)元，顾客递给Alice一张100元的纸币。请设计一个算法，计算Alice最少需要使用多少张硬币来找给顾客(100 - n)元的零钱。

Input:
输入一个整数n (1 <= n <= 99)，表示顾客购买商品的总价。

Output:
输出一个整数，表示最少需要使用的硬币数量。

Sample Input:
78
Sample Output3:
*/
