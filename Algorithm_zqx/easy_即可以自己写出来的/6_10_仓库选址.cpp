#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
	int a[n];
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a,a+n);

    //依据中位数的性质
    int location=a[n/2];

    int ans=0;
    for(int i = 0; i < n; i++) 
        ans+=abs(a[i]-location);
    cout << ans << endl;
    return 0;
}

/*
Description：
在一条数轴上有N家商店，每家商店都有一个确定的坐标，这些坐标分别为A_1, A_2, ..., A_N。你的任务是在这条数轴上选择一个点建立一个货仓。
每天早晨，需要从货仓运送货物到每家商店。为了提高运输效率，你需要选择一个货仓的位置，使得货仓到所有商店的总距离最小。

Input：
第一行是一个整数N(1 < N < 1e5) ，表示商店的数量。
第二行是N个整数，A_1, A_2, ..., A_N(0 < A_i < 1e4) ，表示每家商店在数轴上的坐标。

Output：
输出一个整数，表示货仓到所有商店的总距离的最小可能值。

Sample Input：
4
6 2 9 1
Sample Output：
12
*/
