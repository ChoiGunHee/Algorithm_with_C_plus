/**
* 2021. 05. 09
* Creater : Gunhee Choi
* Problem Number : 10818
* Title : 최소, 최대
* Problem :
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
	5
	20 10 35 30 7
	
* Output : 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
	7 35
**/

#include <iostream>
using namespace std;

int main(void) {
    int N;
    int max = -2000000;
    int min = 2000000;
    int t;
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> t;
        
        if(t > max) max = t;
        if(t < min) min = t;
    }
    
    cout << min << " " << max << endl;
    
    return 0;
}