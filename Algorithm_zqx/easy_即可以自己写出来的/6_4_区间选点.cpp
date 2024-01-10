#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int a,b;
};
bool cmp(Node a, Node b) {
    return a.b < b.b;//return a.a < b.a;是错误的！
}
int main() {
    int n;
    cin >> n;
    Node a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].a >> a[i].b;
    sort(a,a+n,cmp);

    int cnt=1;
    int be=a[0].b;
    //每寻找到一个点，可以将其可以覆盖的线段去掉
    for(int i=1;i<n;i++){
        //这3种方法都可以：
        
        //方法1：
        /*while (i < n && a[i].a <= be)
            i++;
        if (i >= n){
            cout << cnt << endl;
    		return 0;
        }
        //找下一个点
        cnt++;
        be=a[i].b;*/
        
        //方法2：
        /*while(a[i].a<=be){
            if(i==n-1){
                cout<<cnt<<endl;
                return 0;
            }
            else{
                i++;
            }
        }
        //找下一个点
        cnt++;
        be=a[i].b;*/
        
        //方法3：
        if (!(a[i].a <= be)) {
            cnt++;
            be = a[i].b;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

/*
Description：
给定 ( N ) 个闭区间 ([a_i, b_i])，需要在数轴上选择尽可能少的点，以确保每个区间内至少包含一个选出的点。位于区间端点上的点也算作区间内。

Input：
第一行包含整数 ( N )，表示区间数量。
接下来的 ( N ) 行，每行包含两个整数 ( a_i, b_i )，表示一个区间的两个端点。
数据范围：
( 1 <= N <= 10^5 )
( -10^9 <= a_i <= b_i <= 10^9 )

Output：
输出一个整数，表示所需选择的点的最小数量。

Sample Input：
3
-1 1
2 4
3 5
Sample Output：
2
*/
