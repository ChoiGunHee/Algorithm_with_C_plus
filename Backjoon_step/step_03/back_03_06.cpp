/**
* 2021. 04. 30
* Creater : Gunhee Choi
* Problem Number : 2742
* Title : 기찍 N
* Problem :
자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
* Input : 첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.
	5
	
* Output : 첫째 줄부터 N번째 줄 까지 차례대로 출력한다.
	5
	4
	3
	2
	1
**/

#include <iostream>
using namespace std;

int main(void) {
	int num;
	
    cin >> num;
    
	for(int i=num; i>=1; i--) {
		cout << i << "\n";	
	}
	
	return 0;
}