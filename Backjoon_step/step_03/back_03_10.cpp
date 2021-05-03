/**
* 2021. 05. 03
* Creater : Gunhee Choi
* Problem Number : 10872
* Title : 별 찍기 - 2
* Problem :
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.
* Input : 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
	5
	
* Output : 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
    *
   **
  ***
 ****
*****
**/

#include <iostream>
using namespace std;

int main() {
	int num;
	
    cin>> num;
    
	for(int i=1; i<=num; i++) {
		for(int j=0; j<num-i; j++) {
			cout<<" ";
		}
		for(int j=0; j<i; j++) {
			cout<<"*";
		}
		cout<<'\n';
	}
    
	return 0;
}