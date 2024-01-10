#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
	int prices[n];
    for(int i = 0; i < n; i++) 
        cin >> prices[i];

    int ans=0;
    int hasShare=0;
    int cost=0;
    for(int i=0;i<n-1;i++){
        if(hasShare==0 && prices[i]<prices[i+1]){
            cost=prices[i];
            ans-=cost;
            hasShare=1;
        }
        else if(hasShare==1 && prices[i]>prices[i+1]){
            ans+=prices[i];
            hasShare=0;
        }
    }

    //i==n-1
    if(hasShare){
        ans+=prices[n-1];
    }
    
    cout << ans << endl;
    return 0;
}

/*
//方法2：
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100010];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1])
            ans += a[i+1] - a[i]; 
    }

    cout << ans;
    return 0;
}
*/

/*
Description：
你是一位股票交易员，你现在有一支股票的价格列表，其中第i天的股票价格是prices[i]。设计一个算法来找到获取最大利润的交易策略。交易规则如下：
你可以进行多次交易，但是必须在再次购买前卖出股票。
请返回你能获得的最大利润。

Input：
第一行一个整数n
n个正整数（小于1000），代表一个数组prices，其中prices[i]代表股票在第i天的价格。

Output：
返回你能获取的最大利润。

Sample Input：
6
7 1 5 3 4 6
Sample Output：
7
Sample Input：
4
7 5 3 2
Sample Output：
0
*/
