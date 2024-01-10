#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    float m, v;
};

bool cmp(Node a, Node b) {
    return a.v/a.m > b.v/b.m;
}

int main() {
    int n, t;
    cin >> n >> t;
    Node a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i].m >> a[i].v;
    }

    sort(a,a+n,cmp);

    float r=t;
    float totalValue=0;
    for(int i=0;i<n;i++){
        if(r==0){
            printf("%.2f", totalValue);
            return 0;
        }
        else if(a[i].m<=r){
            r-=a[i].m;
            totalValue+=a[i].v;
        }
        else{//0<r<a[i].m
            totalValue+=a[i].v/a[i].m*r;
            printf("%.2f", totalValue);
            return 0;
        }
    }
    
    printf("%.2f", totalValue);
    return 0;
}

/*
Input:
第一行包含两个整数n和T，分别表示金币堆的数量和小袋子的最大承重。
接下来的n行，每行包含两个浮点数，分别是第i堆金币的总重量m和总价值v。

Output:
输出一个小数，表示矿工们可以携带走的金币的最大价值，结果保留两位小数。

Sample Input:
5 50
10 60
20 100
30 120
40 160
50 200
Sample Output:
240.00
*/
