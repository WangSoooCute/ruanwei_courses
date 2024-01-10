#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
	int a[n];
    int totalNum=0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        totalNum+=a[i];
    }

    const int averageNum=totalNum/n;

    int ans=0;
    for(int i = 0; i < n-1; i++){
        //2种方法都可以：
        if(a[i]<averageNum){
            ans++;
            a[i+1]-=(averageNum-a[i]);
        }
        else if(a[i]>averageNum){
            ans++;
            a[i+1]+=(a[i]-averageNum);
        }
        /*if(a[i]!=averageNum){
            ans++;
            a[i+1]+=(a[i]-averageNum);//移动纸牌 
        }*/
    }
    cout << ans << endl;
    return 0;
}

/*
Description：
在学校图书馆，管理员小明正在整理一些图书。这些图书被分成了n堆，编号分别为1, 2, ..., n。每堆上有若干本书，但图书的总数必为n的倍数。小明可以在任一堆上取若干本图书，然后移动它们。
移动图书的规则为：
在编号为1的堆上取的图书，只能移到编号为2的堆上；
在编号为n的堆上取的图书，只能移到编号为n-1的堆上；
在其他编号的堆上取的图书，可以移到相邻左边或右边的堆上。
现在要求你帮助小明找出一种移动方法，用最少的移动次数使每堆上图书的数量都一样多。

Input：
第一行输入一个整数n(1 <= n <= 100)，表示图书堆的数量。
第二行输入n个整数a_1, a_2, ... , a_n(1 <= a_i <= 1e5)，用空格隔开，表示每堆图书初始时的数量。保证图书总数是n的倍数。

Output：
输出一个整数，表示使所有堆均达到相等时的最少移动次数。

Sample Input：
4
9 8 17 6
Sample Output：
3
*/
