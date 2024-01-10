#include<iostream>
using namespace std;
int main(){
    double n;
    cin>>n;

    double l = -10000, r = 10000;
    while(r-l>=0.00000001){
        double m=(l+r)/2;
        if(m*m*m==n){
            printf("%.6f\n",m);
            return 0;
        }
        else if(m*m*m<n){
            l=m;
        }
        else{
            r=m;
        }
    }
    printf("%.6f\n",l);
    return 0;
}

/*
Description：
编写一个程序来找出一个给定的浮点数 ( n ) 的三次方根。

Input：
输入只有一行，这一行包含一个浮点数 ( n )。
数据范围：-10000 <= n <= 10000

Output：
输出也是一行，包含一个浮点数，即 ( n ) 的三次方根。输出结果需保留六位小数。

Sample Input：
1000.00
Sample Output：
10.000000
*/

/*
printf("%lf\n",l);//也对
cout<<l<<endl;//是错的
*/
