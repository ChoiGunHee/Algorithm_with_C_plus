/**
* 2021. 10. 13
* Creater : Gunhee Choi
* Problem Number : 2744
* Title : 대소문자 바꾸기

* Problem :
영어 소문자와 대문자로 이루어진 단어를 입력받은 뒤, 대문자는 소문자로, 소문자는 대문자로 바꾸어 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.

    WrongAnswer

* Output :
첫째 줄에 입력으로 주어진 단어에서 대문자는 소문자로, 소문자는 대문자로 바꾼 단어를 출력한다.

    wRONGaNSWER

**/

#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    cin>>str;
    
    for(int i=0; i<str.length(); i++) {
        if('A'<=str[i] && str[i]<='Z')
            str[i] += 32;
        else
            str[i] -=32;
    }

    cout<<str<<"\n";

    return 0;
}