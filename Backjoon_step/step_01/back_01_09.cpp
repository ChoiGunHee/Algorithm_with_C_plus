/**
* 2021. 03. 25
* Creater : Gunhee Choi
* Problem Number : 10869
* Title : 사칙연산
* Problem :
두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

* Input : 두 자연수 A와 B가 주어진다. (1 ≤ A, B ≤ 10,000)
	7 3
	
* Output : 첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.
	10
	4
	21
	2
	1
**/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	cout.precision(20);
	cout << a+b << endl;
	cout << a-b << endl;
	cout << a*b << endl;
	cout << a/b << endl;
	cout << a%b << endl;
	
	return 0;
}