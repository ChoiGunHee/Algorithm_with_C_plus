/**
* 2021. 09. 29
* Creater : Gunhee Choi
* Problem Number : 2702
* Title : 초6 수학

* Problem :
두 정수 a와 b 최소공배수는 두 수의 공통된 배수 중 가장 작은 수이고, 최대공약수는 두 수의 공통된 약수중 가장 큰 수이다.

a와 b가 주어졌을 때, 최소공배수와 최대공약수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 테스트 케이스의 개수 T(1<=T<=1,000)가 주어진다. 각 테스트 케이스는 두 정수 a와 b로 이루어져 있고, 공백으로 구분되어 있다. (1 <= a,b <= 1,000)

    3
    5 10
    7 23
    42 56

* Output :
각 테스트 케이스에 대해 최소공배수와 최대공약수를 차례대로 출력한다.

    10 5
    161 1
    168 14

**/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int mod = b % a;
    
	while (mod) {
		b = a;
		a = mod;
		mod = b % a;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << " " << gcd(a, b)<<"\n";
	}
    
	return 0;
}