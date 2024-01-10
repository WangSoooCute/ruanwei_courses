#include<iostream>
#include<string.h>
using namespace std;

void swap(int arr[], int x, int y){
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

//----------冒泡排序----------

void BubbleSort(int arr[], int n){
  //从小到大排序 相邻来两个数比较，将大的数字往后放
  for (int i = 0; i < n - 1; i++){      //n-1是因为数组下标最大为n-1 要进行10轮比较
    //n-1是因为数组下标最大为n-1 要进行10次比较，再减i是因为每最后的i个元素已经有序不需要继续排序
    for (int j = 0; j < n - 1 - i; j++){
      if (arr[j] > arr[j + 1]){      //两两比较，将小的数据放前面
        swap(arr, j + 1, j);        //交换arr数组arr[j+1]和arr[j]的值
      }
    }
    //cout<<i<<endl;
    //print(arr,9);
  }
}


//----------插入排序（直接插入）----------

void InsertSort(int arr[], int n){
  int tempVal;
  for (int i = 1, j; i < n; i++){
    tempVal = arr[i];  //保存要插入的值
    for (j = i - 1; tempVal < arr[j] && j >= 0; --j){  //数据往后移动，给要插入的值腾位
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = tempVal;  //插入数据
    //cout<<i<<endl;
    //print(arr,9);
  }
}


//----------2路归并排序----------

void _merge_in_arr(int arr[], int left, int mid, int right){
  int length = right - left + 1;          //定义一个辅助的空间的长度
  int *pData = (int*)malloc(sizeof(int)*length);//分配一个动态内存来调整元素的位置
  memset(pData, 0, sizeof(int)* length);

  //合并
  int low = left;    //左边区间的起始下标
  int hig = mid + 1;  //右边区间的起始下标
  int index = 0;    //辅助数组的下标

  while (hig <= right){//右区间没有合并完
    while (low <= mid && arr[low] <= arr[hig]){//证明左区间没有合并完，且左区间的值小于右区间的值
      pData[index] = arr[low];      //把左边的值放进辅助数组
      low++;                //左边往高位移，下一次需要判断左边的新下标
      index++;              //下一次放进辅助数组的新下标
    }
    if (low > mid)  //证明左区间已经放完
      break;

    while (hig <= right && arr[low] > arr[hig]){//证明右区间没有合并完，且左区间的值大于右区间的值
      pData[index] = arr[hig];      //把右边的值放进辅助数组
      hig++;                //右边往高位移，下一次需要判断右边的新下标
      index++;              //下一次放进辅助数组的新下标
    }
  }

  //到这一步，证明起码有一个区间已经合并完成
  if (hig <= right)  //证明右边没有完成
    memmove(&pData[index], &arr[hig], sizeof(int)* (right - hig + 1));
  if (low <= mid)    //证明左边没有完成
    memmove(&pData[index], &arr[low], sizeof(int)* (mid - low + 1));

  //把所有区间都合并到了辅助区间
  memmove(&arr[left], pData, sizeof(int)* length);
  free(pData);  //释放空间
}

void MergeSort(int arr[], int left, int right){
  if (left >= right)//递归的终止条件，left == right证明这个区间只有一个元素，不需要再拆了
    return;
  int mid = ((right - left) >> 1) + left;//求中点
  MergeSort(arr, left, mid);    //拆分左
  MergeSort(arr, mid + 1, right);  //拆分右
  //并操作
  _merge_in_arr(arr, left, mid, right);
}


//----------快速排序----------

void QuickSort(int arr[], int left, int right){
  if (left >= right) return;  //只有一个元素不排
  int i = left, j = right;
  while (i < j){
    while (i < j&&arr[j] >= arr[left])  //从右向左找第一个小于arr[left]的数
      --j;
    while (i < j&&arr[i] < arr[left])  //从左向右找第一个大于等于arr[left]的数
      ++i;
    if (i < j)
      swap(arr, i, j);
  }
  QuickSort(arr, left, i - 1);//排左边
  QuickSort(arr, i + 1, right);//排右边
}

int main(){
    int arr1[9]={1,2,3,100,20,1,19,23,50};
    int arr2[9]={1,2,3,100,20,1,19,23,50};
    int arr3[9]={1,2,3,100,20,1,19,23,50};
    int arr4[9]={1,2,3,100,20,1,19,23,50};

    BubbleSort(arr1,9);
    cout<<"使用冒泡排序："<<endl;
    print(arr1,9);

    InsertSort(arr2,9);
    cout<<"使用插入排序（直接插入）："<<endl;
    print(arr2,9);

    MergeSort(arr3,0,8);
    cout<<"使用2路归并排序："<<endl;
    print(arr3,9);

    QuickSort(arr4,0,8);
    cout<<"使用快速排序："<<endl;
    print(arr4,9);

    return 0;
}
