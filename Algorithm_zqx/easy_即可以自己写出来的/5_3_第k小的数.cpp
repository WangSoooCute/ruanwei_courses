#include<iostream>
using namespace std;
int k;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int quickSort(int arr[], int low, int high) {
    if(low==high){
        return arr[low];
    }
    if (low < high) {
        int pi = partition(arr, low, high);

        //2种方法都可以：
        if(pi>k-1)
            return quickSort(arr, low, pi - 1);
        else if(pi<k-1)
            return quickSort(arr, pi + 1, high);
        else
            return arr[pi];
        /*int m=pi-low;//有m个小于pivot的数
        if(m>k-1)
            return quickSort(arr, low, pi - 1);
        else if(m<k-1){
            k-=(m+1);
            return quickSort(arr, pi + 1, high);
        }
        else
            return arr[pi];*/
    }
}

int main() {
    int n;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i < n; i++)
        cin>>arr[i];

    cout<<quickSort(arr, 0, n-1)<<endl;
    return 0;
}

/*
Sample Input：
7 4
10 7 8 9 1 5 2
Sample Output：
7
*/
