/**
* 2021. 10. 08
* Creater : Gunhee Choi
* Problem Number : 1644
* Title : 소수의 연속합

* Problem :
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

    3 : 3 (한 가지)
    41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
    53 : 5+7+11+13+17 = 53 (두 가지)

하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

    41

* Output :
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

    3

**/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX_NUM 4000000
using namespace std;

bool nisPN[MAX_NUM+1];
vector<int> pre_sum;
vector<int> prime_num;

int main() {
    int N, sum=0;
    int l=0, r=0;
    int result=0;
    
    cin>>N;
    pre_sum.push_back(0);
    
    for(int i=2; i<sqrt(MAX_NUM); i++)
        for(int j=i*2; j<=MAX_NUM; j+=i)
            nisPN[j]=true;
    
    for(int i=2; i<=MAX_NUM; i++) {
        if(!nisPN[i]) {
            sum+=i;
            pre_sum.push_back(sum);
        }
    }

    while(l<=r && r<pre_sum.size()) {
        if(pre_sum[r]-pre_sum[l]>N)
            l++;
        else if(pre_sum[r]-pre_sum[l]<N)
            r++;
        else {
            result++;
            r++;
        }
    }
    
    cout<<result<<"\n";
    
    return 0;
}