/**
* 2021. 10. 06
* Creater : Gunhee Choi
* Problem Number : 16580
* Title : 연세대학교

* Problem :
연세대학교의 영문명은 YONSEI, 슬로건은 Leading the Way to the Future이다.

이를 출력하는 프로그램을 작성해보도록 하자.

* Input :
첫째 줄에 N이 주어진다. (N = 0 또는 1)
    
    0

* Output :
N = 0일 경우: 연세대학교의 영문명을 출력한다.
N = 1일 경우: 연세대학교의 슬로건을 출력한다.

    YONSEI

**/

#include <iostream>
using namespace std;

int main() {
    int N;
    
    cin>>N;
    
    if(N) {
        cout<<"Leading the Way to the Future\n";
    } else {
        cout<<"YONSEI\n";
    }
    
	return 0;
}