/**
* 2021. 07. 01
* Creater : Gunhee Choi
* Problem Number : 11720
* Title : 숫자의 합
* Problem :
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
* Input : 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
	5
	54321
* Output : 입력으로 주어진 숫자 N개의 합을 출력한다.
	15
관련 사이트 : https://vvshinevv.tistory.com/6
(char a[] 와 char * a 차이)
**/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;
    int size;
    int sum = 0;
    
    cin >> size;
    cin >> arr;
    
    for(int i=0; i<size; i++) {
        sum += ((int)arr.at(i)) - '0';
    }
    
    cout << sum << endl;
    
	return 0;
}