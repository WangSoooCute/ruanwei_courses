#include<iostream>
using namespace std;

int ans(int a,int b,int p){
    a%=p;
    long long s=1;
    //利用a^(2b)=(a^2)^b
    while(b>0){
        if(b%2){
            s*=a;
            s%=p;
            b--;
        }
        while(b%2==0 && b>0){
            a*=a;
            a%=p;
            b/=2;
        }
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a,b,p;
        cin>>a>>b>>p;
        cout<<ans(a,b,p)<<endl;
    }
    return 0;
}

/*
Description：
给定n组整数ai, bi, pi，你需要编写一个程序来计算每组(ai^bi) mod pi的结果。

Input：
第一行包含一个整数n，表示数据组数。
接下来的n行，每行包含三个整数ai, bi, pi。

Output：
对于每组输入数据，输出一个整数，即计算得到的(ai^bi) mod pi的值。每个结果输出在单独的一行。

Sample Input：
3
5 8 100
2 10 1024
7 3 33
Sample Output：
25
0
13
*/

/*
//会超时：
int ans(int a,int b,int p){
    a%=p;
    long long s=a;
    while(b>1){
        s*=a;
        s%=p;
        b--;
    }
    return s;
}
*/

/*
//自己写的方法：
int ans(int a,int b,int p){
    a%=p;
    long long s=1;
    //利用a^(2b)=(a^2)^b
    while(b>1){
        if(b%2){
            s*=a;
            s%=p;
            b--;
        }
        while(b%2==0 && b>1){
            a*=a;
            a%=p;
            b/=2;
        }
    }
    return (a*s)%p;
}
*/
