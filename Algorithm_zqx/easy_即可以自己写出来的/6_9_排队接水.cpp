#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int x,int y){
    return x>y;
}

int main() {
    int n;
    cin>>n;
	int t[n];
    for(int i = 0; i < n; i++) 
        cin >> t[i];
    sort(t,t+n,cmp);

    int ans=0;
    for(int i = 0; i < n; i++) 
        ans+=i*t[i];//依据Short Job First的原理
    cout << ans << endl;
    return 0;
}

/*
Description：
有n个人需要排队到一个水龙头处打水。每个人打水所需的时间不同。第i个人打水需要t_i时间单位。我们的目标是安排一个打水的顺序，使得所有人的总等待时间最小。
这里的“等待时间”指的是一个人在排队等待打水时所花费的时间。例如，如果一个人排在第一个，那么他的等待时间是 0，因为他不需要等待其他人。但是，排在他后面的人需要等待他打完水。

Input：
第一行是一个整数n(a <= n <= 1e5) ，表示排队的人数。
第二行包含n个整数，每个整数t_i(1 <= t_i <= 1e4) 表示第i个人打水所需的时间。

Output：
输出一个整数，这个整数是所有人等待时间的总和的最小值。

Sample Input：
7
3 6 1 4 2 5 7
Sample Output：
56
*/
