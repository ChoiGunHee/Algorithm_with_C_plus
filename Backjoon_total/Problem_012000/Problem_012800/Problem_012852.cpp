/**
* 2021. 10. 08
* Creater : Gunhee Choi
* Problem Number : 12852
* Title : 1로 만들기 2

* Problem :
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

    1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
    2. X가 2로 나누어 떨어지면, 2로 나눈다.
    3. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

* Input :
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

    10

* Output :
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다. 정답이 여러 가지인 경우에는 아무거나 출력한다.

    3
    10 9 3 1

**/

#include <iostream>
#define MAX_NUM 1000001
using namespace std;

int dp[MAX_NUM];

int main() {
    int n;
    
    cin>>n;
    for(int i=1; i<=n; i++)
        dp[i]=i;
    
    for(int i=2; i<=n; i++) {
        if(i%2==0)
            dp[i]=min(dp[i], dp[i/2]);
        if(i%3==0)
            dp[i]=min(dp[i], dp[i/3]);
        
        dp[i]=min(dp[i], dp[i-1])+1;
    }
    
    cout<<dp[n]-1<<"\n";
    while(n!=0) {
        cout<<n<<" ";
        if(dp[n]==dp[n-1]+1)
            n-=1;
        else if(n%2==0 && dp[n]==dp[n/2]+1)
            n/=2;
        else if(n%3==0 && dp[n]==dp[n/3]+1)
            n/=3;
    }
    cout<<"\n";
    
    return 0;
}