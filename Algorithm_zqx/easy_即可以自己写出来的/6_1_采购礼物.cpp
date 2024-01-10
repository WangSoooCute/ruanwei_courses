#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[100010];
    for (int i = 0; i < n; i++)
        cin >> a[i];
	
    sort(a,a+n);
    
    int cnt=0;
    
    //方法1：
    /*int value=0;
    for(int i=0;i<n;i++){
        if(value+a[i]<=m){
            value+=a[i];
            cnt++;
        }
        else{
            cout<<cnt<<endl;
            return 0;
        }
    }
    cout<<cnt<<endl;//cout<<n<<endl;也可以
    return 0;*/
    
    //方法2：
    for (int i = 0; i < n; i++) {
        if (m >= a[i]) {
            cnt++;
            m -= a[i];

        }
        else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
Description:
小明的生日即将到来，他的朋友小红决定为他挑选一些礼物。在礼物商店中，有n种不同的礼物，每种礼物都有一个确定的价格。但小红只带了m单位的钱，她想知道，最多可以为小明买到多少件礼物？
请你设计一个算法，帮助小红计算出她最多可以为小明买到多少件礼物。每种物品只买一件。

Input:
第一行包含两个整数n和m，分别表示礼物的种类数量和小红携带的钱数。（1 <= n <= 10^5, 1 <= m <= 10^9）
第二行包含n个整数，表示每种礼物的价格。每件礼物的价格为正整数并且不超过10^4。

Output:
输出一个整数，表示小红最多可以为小明买到的礼物数量。

Sample Input:
5 300
70 50 60 100 80
Sample Output:
4
*/
