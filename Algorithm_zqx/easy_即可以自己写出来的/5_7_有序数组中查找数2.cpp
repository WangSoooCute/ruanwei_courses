#include<iostream>
using namespace std;

int find(int* a,int l,int r,int k){
    if(l==r){
        if(a[r]!=k){
            return -1;
        }
        return r;
    }

    int m=(l+r)/2;
    if(a[m]>=k){
        return find(a,l,m,k);
    }
    else if(a[m]<k){
        return find(a,m+1,r,k);
    }
}

void process(int* a,int n,int k){
    int l=find(a,0,n,k);
    if(l==-1){
        cout<<"-1 -1"<<endl;
        return ;
    }

    int r=l+1;
    while(r<n && a[r]==k){
        r++;
    }
    r--;

    cout<<l<<' '<<r<<endl;
}

int main(){
    int n,q;
    cin>>n>>q;

    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        process(a,n,k);
    }

    return 0;
}

/*
Description：
实现一个算法，在一个升序排列的整数数组中找到一个给定整数k的起始位置和终止位置。如果这个整数在数组中出现多次，起始位置指的是k首次出现的索引(索引从0开始计算)，终止位置是k最后一次出现的索引。如果k在数组中没有出现，则需要返回一对-1。

Input：
第一行包含两个整数n和q，其中n是数组的长度，q是查询的次数。
第二行包含n个升序排列的整数，表示数组的内容。
接下来的q行，每行包含一个整数k，表示需要查询的数字。

Output：
对于每个查询，输出一行，包含两个整数，即数字k的起始位置和终止位置。
如果数组中不存在该元素，则输出-1 -1。

Sample Input：
6 3
1 2 3 3 3 4
3
4
5
Sample Output：
2 4
5 5
-1 -1
*/

/*
//老师写法（没用递归）：
#include <iostream>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int a[100010];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    while(q--){
        int k;
        cin >> k;
        
        int l = 0, r = n-1; //确定区间
        while(l < r){
            int mid = l + r >> 1;
            if(a[mid] >= k)//判断条件，用mid进行比较 
                r = mid;//，分界点在mid的左边，mid也可能是答案 
            else
                l = mid + 1;
        }

        //自己写的方法2：
        /*if(a[l] == k){
            cout << l << " "; 

            l = l+1; 
            r = n;
            while(l < r){
                int mid = l + r >> 1;
                if(a[mid] <= k)
                    l = mid+1;
                else
                    r = mid;
            }
            l--;
            cout << l << endl; 
        }*
        if(a[l] == k){
            cout << l << " "; 

            l = l; //可以不写 
            r = n-1;
            while(l < r){
                int mid = l + r +1 >> 1;
                if(a[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl; 
        }
        else
            cout << "-1 -1" << endl;
    }
    return 0;
}
*/
