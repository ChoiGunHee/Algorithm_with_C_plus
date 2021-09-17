/**
* 2021. 09. 17
* Creater : Gunhee Choi
* Problem Number : 2145
* Title : 숫자 놀이

* Problem :
초등학생인 도겸이는 숫자를 좋아한다. 어느 날 도겸이는 숫자 책을 보다가 간단한 놀이를 하나 생각해냈다. 숫자 놀이의 규칙은 다음과 같다.

    1.  주어진 숫자의 각 자릿수를 더한다.
    2. 결과가 한 자릿수가 될 때 까지 규칙1을 반복한다.
    
예를들어, 숫자 673에 규칙을 적용해보면 결과는 7이 된다 ; 6 + 7 + 3 = 16, 1 + 6 = 7 

도겸이는 당신과 함께 숫자놀이를 하고싶어한다. 도겸이가 주는 숫자들을 풀어보자.

* Input :
각 줄에 숫자 N이 주어진다. N은 100,000보다 작은 양의 정수이다. 마지막 입력은 0이며, 0에 대한 결과는 출력하지 않는다.

    673
    51
    1000
    99
    0

* Output :
한 줄에 하나씩 한 자릿수 결과를 출력한다.

    7
    6
    1
    9

**/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int N;
    int result=0;
    int tmp=0;
    
    while(1) {
        cin>>N;
        if(N==0)
            break;
        
        while(N>=10) {
            tmp=N;
            result=0;
            
            while(tmp>0) {
                result+=tmp%10;
                tmp/=10;
            }
            
            N=result;
        }
        
        cout<<N<<"\n";
    }
    
	return 0;
}