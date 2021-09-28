/**
* 2021. 09. 28
* Creater : Gunhee Choi
* Problem Number : 1806
* Title : 부분합

* Problem :
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

    10 15
    5 1 3 5 10 7 4 9 2 8

* Output :
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

    2

**/

#include <iostream>
using namespace std;

int INF=987654321;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, S;
    int arr[100000];
    
    int low=0, high=0;
    int sum, result;
    
    cin>>N>>S;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    
    sum=arr[0];
    result=INF;
    while(low<=high && high<N) {
        if(sum<S)
            sum+=arr[++high];
        else {
            result=min(result, (high-low+1));
            if(sum==S)
                sum+=arr[++high];
            else if(sum>S)
                sum -= arr[low++];
        }
    }//end of while
    
    if(result==INF)
        cout<<"0\n";
    else
        cout<<result<<"\n";
    
    return 0;
}