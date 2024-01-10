#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n;
    cin>>n;
	priority_queue<int,vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        heap.push(tmp);
    }

    
    int ans=0;
    while(heap.size()>1){
        int x=heap.top();
        heap.pop();
        x+=heap.top();
        heap.pop();

        ans+=x;
        heap.push(x);
    }

    cout << ans << endl;
    return 0;
}

/*
Description：
有 n 种果子，每种果子的数量分别为 a1, a2, ..., an。
你可以合并任意两堆果子，每次合并的体力消耗是这两堆果子的总数。
需要通过 n-1 次合并，使得最终合并的总体力消耗最小。
计算出达达合并所有果子所需的最小体力消耗值。

Input：
输入包括两行，第一行是一个整数 n ( 1 <= n <= 1e4)，表示果子的种类数。
第二行包含 n 个整数，分别是每种果子的数量。( 1 <= a_i <= 1e4)

Output：
输出是一个整数，表示最小的体力消耗值。

Sample Input：
3
1 2 10
Sample Output：
16
*/
