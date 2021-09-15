/**
* 2021. 09. 15
* Creater : Gunhee Choi
* Problem Number : 2293
* Title : 동전 1

* Problem :
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

* Input :
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.

    3 10
    1
    2
    5

* Output :
첫째 줄에 경우의 수를 출력한다. 경우의 수는 231보다 작다.

    10

**/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int n,k;
    int coins[101];
    int dp[10001]={1, };
    
    cin>>n>>k;
    
    for(int i=1; i<=n; i++)
        cin>>coins[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (j >= coins[i])
                dp[j] += dp[j-coins[i]];
    
    cout<<dp[k]<<"\n";
    
	return 0;
}