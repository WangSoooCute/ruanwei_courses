#include<iostream>
using namespace std;

int ans(int* a,int l,int r){
    if(l==r){//即n==1
        return a[r];
    }
    if(l+1==r){
        return a[r];
    }

    int m=(l+r)/2;
    if(a[l]>a[m]){
        return ans(a,l,m);
    }
    else if(a[m]<a[m+1]){
        return ans(a,m+1,r);
    }
    else{//即a[l]<a[m] && a[m]>a[m+1]
        return a[m+1];
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);//scanf效率高，用cin会Time Limit Excee
    }
    
    cout<<ans(a,0,n-1)<<endl;
    return 0;
}

/*
Description：
给定一个严格单调递增的序列，这个序列经过一次旋转后，可能在某个枢轴点上发生了旋转，导致原有序列被分为两部分，前面部分的所有元素都大于后面部分的所有元素，如下图所示：
原始序列：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
旋转后的序列：4 -> 5 -> 6 -> 7 -> 1 -> 2 -> 3
旋转后的序列依旧保持了分段的单调递增特性。请编写一个算法，找出并返回旋转后序列中的最小元素。
假设序列中不存在重复元素。

Input：
第一行 n, (0 < n < 10000000)
第二行，n个整数，一个整数数组，代表旋转后的序列。

Output：
序列中的最小元素。

Sample Input：
7
4 5 6 7 0 1 2
Sample Output：
0
*/

/*
//老师写法（没用递归）：
int ans(int* a,int l0,int r0){
    int l = l0, r = r0;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] > a[r])
            l = mid + 1;
        else
            r = mid; //mid可能是答案
    }
    return a[r];
}
*/
