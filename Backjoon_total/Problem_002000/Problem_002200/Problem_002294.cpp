/**
* 2021. 09. 15
* Creater : Gunhee Choi
* Problem Number : 2294
* Title : 동전 2

* Problem :
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

* Input :
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

    3 15
    1
    5
    12

* Output :
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

    3

**/

#include <iostream>
#define MAX_NUM 200000

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int n,k;
    int coins[101];
    int dp[10001]={0, };
    
    cin>>n>>k;
    
    for(int i=1; i<=n; i++)
        cin>>coins[i];
    
    for(int i=1; i<=k; i++)
        dp[i]=MAX_NUM;
    
    for (int i=1; i<=n; i++) {
        for (int j=coins[i]; j<=k; j++)
            dp[j]=min(dp[j], dp[j-coins[i]]+1);
    }
    
    if(dp[k]==MAX_NUM)
            cout<<-1<<"\n";
    else
        cout<<dp[k]<<"\n";
    
	return 0;
}