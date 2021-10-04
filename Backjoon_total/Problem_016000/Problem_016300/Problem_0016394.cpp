/**
* 2021. 10. 04
* Creater : Gunhee Choi
* Problem Number : 16394
* Title : 홍익대학교

* Problem :
홍익대학교는 1946년에 개교하였다.

특정 년도가 주어졌을 때, 그 해가 개교 몇 주년인지 출력하라.

단, 홍익대학교는 없어지지 않는다고 가정한다.

문제는 C, C++, JAVA 또는 Python3을 이용하여 해결한다.

* Input :
입력으로 첫 줄에 특정 년도를 알리는 정수 N이 주어진다. 정수 N은 1,946 부터 1,000,000 사이의 값이다. (1,946 ≤  N ≤  1,000,000)

    2018

* Output :
출력으로 홍익대학교의 개교 주년을 나타내는 정수를 출력한다.

    72

**/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n - 1946 << endl;

	return 0;
}