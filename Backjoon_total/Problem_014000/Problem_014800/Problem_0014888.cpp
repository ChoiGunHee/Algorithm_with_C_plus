/**
* 2021. 10. 08
* Creater : Gunhee Choi
* Problem Number : 14888
* Title : 연산자 끼워넣기

* Problem :
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.

    1+2+3-4×5÷6
    1÷2+3+4-5×6
    1+2÷3×4-5+6
    1÷2×3-4+5+6
    
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

    1+2+3-4×5÷6 = 1
    1÷2+3+4-5×6 = 12
    1+2÷3×4-5+6 = 5
    1÷2×3-4+5+6 = 7
    
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 

    3
    3 4 5
    1 0 1 0

* Output :
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.

    35
    17

**/

#include <iostream>
#include <algorithm>
#define MAX_NUM 1000000001
using namespace std;

int N;
int nums[12];
int op[4];
int max_result=-MAX_NUM;
int min_result=MAX_NUM;

void dfs(int plus, int minus, int multiply, int divide, int cnt, int sum) {
    if(cnt==N) {
        max_result=max(max_result, sum);
        min_result=min(min_result, sum);
    }
    
    if(plus>0)
        dfs(plus-1, minus, multiply, divide, cnt+1, sum+nums[cnt]);
    if(minus>0)
        dfs(plus, minus-1, multiply, divide, cnt+1, sum-nums[cnt]);
    if(multiply>0)
        dfs(plus, minus, multiply-1, divide, cnt+1, sum*nums[cnt]);
    if(divide>0)
        dfs(plus, minus, multiply, divide-1, cnt+1, sum/nums[cnt]);
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>nums[i];
    for(int i=0; i<4; i++)
        cin>>op[i];
    
    dfs(op[0], op[1], op[2], op[3], 1, nums[0]);
    
    cout<<max_result<<"\n"<<min_result<<"\n";
    
    return 0;
}