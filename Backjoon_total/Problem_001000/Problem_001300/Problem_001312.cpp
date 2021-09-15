/**
* 2021. 09. 14
* Creater : Gunhee Choi
* Problem Number : 11728
* Title : 배열 합치기

* Problem :
피제수(분자) A와 제수(분모) B가 있다. 두 수를 나누었을 때, 소숫점 아래 N번째 자리수를 구하려고 한다. 예를 들어, A=3, B=4, N=1이라면, A÷B=0.75 이므로 출력 값은 7이 된다.

* Input :
첫 번째 줄에 A와 B(1≤A, B≤100,000), N(1≤N≤1,000,000)이 공백을 경계로 주어진다.

    25 7 5

* Output :
A÷B를 했을 때, 소숫점 아래 N번째 수를 출력한다.

    2

**/

#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int A,B,N;
    int result;
    
    cin>>A>>B>>N;
    
	while (N--) {
		A %= B;
		A *= 10;
		result = A/B;
	}
    
	cout<<result<<"\n";
	
    return 0;
}
