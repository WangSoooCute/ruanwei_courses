#include<iostream>
using namespace std;
long long cnt=0;//用int的话会Time Limit Exceeded

void merge(int* a,int l,int m,int r){
    int tmp[100001]={0};//写成tmp[r]的话会报错、写成tmp[100000]的话会Time Limit Exceeded
    int idx=l;

    int i=l;
    int j=m+1;

    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            tmp[idx++]=a[i++];
        }
        else{
            tmp[idx++]=a[j++];
            cnt+=m-i+1;
        }
    }

    while(i<=m){
        tmp[idx++]=a[i++];
    }
    while(j<=r){
        tmp[idx++]=a[j++];
    }

    for(int k=l;k<=r;k++){
        a[k]=tmp[k];
    }
}

void mergeSort(int* a,int l,int r){
    if(l==r){
        return ;
    }

    mergeSort(a,l,(l+r)/2);
    mergeSort(a,(l+r)/2+1,r);
    merge(a,l,(l+r)/2,r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    mergeSort(a,0,n-1);
    cout<<cnt<<endl;
    return 0;
}

/*
Description：
给定一个长度为n的整数数列，你的目标是计算出数列中逆序对的总数。
逆序对定义为数列中一对元素(a[i], a[j])，其中i < j且a[i] > a[j]。

Input：
第一行包含一个整数n，表示数列中的元素个数。
第二行包含n个整数，表示数列的元素，元素之间由一个空格分隔。

Output：
输出一个整数，表示数列中逆序对的总数。

Sample Input：
5
9 7 8 3 2
Sample Output：
9
*/

/*
//方法2：暴力破解，是自己写的方法，但会Time Limit Exceeded
void merge(int* a,int l,int m,int r){
    for(int i=l;i<=m;i++){
        for(int j=m+1;j<=r;j++){
            if(a[i]>a[j]){
                cnt++;
            }
        }
    }
}
*/
