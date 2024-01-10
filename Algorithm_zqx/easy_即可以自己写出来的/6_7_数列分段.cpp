#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[100001];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int c=0,cnt=1;
    for(int i=0;i<n;i++){
        if(c+a[i]<=m)
            c+=a[i];
        else{
            cnt++;
            c=a[i];
        }
    }
    cout<<cnt<<endl;
}

/*
//自己写的，应该是对的
#include <iostream>
using namespace std;
int main() {
    int N,M;
    cin>>N>>M;
	int a[N];
    for(int i = 0; i < N; i++) 
        cin >> a[i];

    int cnt = 0;
    int m=M;
    int i=0;
    while(1){
        int m=M;
        while(a[i]<=m){
            m-=a[i];
            i++;
            if(i==N){
                cout<<++cnt<<endl;
                return 0;
            }
        }
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}
*/

/*
Description
给定一个长度为 ( N ) 的正整数数列 ( A_i )，需要将其分割成若干连续的子段，使得每个子段的元素和不超过 ( M )（可以等于 ( M )）。目标是找出最少能将数列分成多少段，以满足上述条件。

Input：
第一行包含两个正整数 ( N, M )，分别表示数列 ( A_i ) 的长度和每段的最大和。
第二行包含 ( N ) 个由空格隔开的非负整数 ( A_i )。
数据范围：
( 1 <= N <= 10^5 )
( 1 <= M <= 10^9 )
( 1 <= A_i <= M )

Output：
输出一个正整数，表示最少划分的段数。

Sample Input：
5 6
4 2 4 5 1
Sample Output：
3
*/
