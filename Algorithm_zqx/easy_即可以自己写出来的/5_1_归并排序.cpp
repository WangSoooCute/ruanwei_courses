#include<iostream>
using namespace std;

void merge(int* a,int l,int m,int r){
    int tmp[100000]={0};//写成tmp[r]的话会报错
    int idx=l;

    int i=l;
    int j=m+1;

    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            tmp[idx++]=a[i++];
        }
        else{
            tmp[idx++]=a[j++];
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
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout<<endl;
    return 0;
}

/*
Sample Input：
5
5 3 6 2 4
Sample Output：
2 3 4 5 6
*/

/*
//代码——合并两个有序数组：
vector<int> mergeSortedArrays(const vector<int>& array1, const vector<int>& array2) {
    vector<int> mergedArray;
    mergedArray.reserve(array1.size() + array2.size()); // 预先分配所需空间

    int i = 0; // 第一个数组的索引
    int j = 0; // 第二个数组的索引

    // 遍历两个数组，直到一个数组结束
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            mergedArray.push_back(array1[i++]);
        } else {
            mergedArray.push_back(array2[j++]);
        }
    }

    // 将剩余的元素添加到合并后的数组
    while (i < array1.size()) {
        mergedArray.push_back(array1[i++]);
    }
    while (j < array2.size()) {
        mergedArray.push_back(array2[j++]);
    }

    return mergedArray;
}
*/
