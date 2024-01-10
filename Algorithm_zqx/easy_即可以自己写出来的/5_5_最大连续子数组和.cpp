#include<iostream>
using namespace std;

int ans(int* a,int l,int r){
    if(l==r){
        return a[l];
    }

    int m=(l+r)/2;
    int x=ans(a,l,m);
    int y=ans(a,m+1,r);
    int max=x>y?x:y;

    int max1=-10000;
    int tmp1=0;
    for(int i=m;i>=l;i--){
        tmp1+=a[i];
        if(tmp1>max1)
            max1=tmp1;
    }
    int max2=-10000;
    int tmp2=0;
    for(int i=m+1;i<=r;i++){
        tmp2+=a[i];
        if(tmp2>max2)
            max2=tmp2;
    }
    
    if(max1+max2>max)
        max=max1+max2;
    return max;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    cout<<ans(a,0,n-1)<<endl;
    return 0;
}

/*
Sample Input：
8
-2 1 -3 4 -1 2 1 -5 4
Sample Output：
6
*/

/*
//暴力法：
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    int max=-10000;
    for(int i=0;i<n;i++){
        int tmp=0;
        for(int j=i;j<n;j++){
            tmp+=a[j];
            max=tmp>max?tmp:max;
        }
    }
    cout<<max<<endl;
    return 0;
}
*/
