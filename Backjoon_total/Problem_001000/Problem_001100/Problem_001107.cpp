/**
* 2021. 09. 18
* Creater : Gunhee Choi
* Problem Number : 1107
* Title : 리모컨

* Problem :
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.

* Input :
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

    5457
    3
    6 7 8

* Output :
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

    6

**/

#include <iostream>
#include <cmath>

#define MAX_NUM 1000000
using namespace std;

int broken_num[10];

int num_check(int n) {
    int len=0;
    
    if(n==0) {
        if(broken_num[0])
            return 0;
        else
            return 1;
    }
    
    while(n>0) {
        if(broken_num[n%10])
            return 0;
        
        n/=10;
        len+=1;
    }
    
    return len;
}

int main() {
    int N, M;
    int tmp;
    int result;
    int press;
    
    cin>>N>>M;
    for(int i=0; i<M; i++) {
        cin>>tmp;
        broken_num[tmp]=1;
    }
    
    result=abs(N-100);
    for(int i=0; i<=MAX_NUM; i++) {
        tmp = num_check(i);
        if(tmp>0) {
            press = abs(i-N);
            if(result>press+tmp)
                result=press+tmp;
        }
    }
    
    cout<<result<<"\n";
    
	return 0;
}