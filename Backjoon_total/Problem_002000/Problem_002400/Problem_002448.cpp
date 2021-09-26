/**
* 2021. 09. 26
* Creater : Gunhee Choi
* Problem Number : 2448
* Title : 별 찍기 - 11

* Problem :
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

* Input :
첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (0 ≤ k ≤ 10, k는 정수)

    24

* Output :
첫째 줄부터 N번째 줄까지 별을 출력한다.

                           *                        
                          * *                       
                         *****                      
                        *     *                     
                       * *   * *                    
                      ***** *****                   
                     *           *                  
                    * *         * *                 
                   *****       *****                
                  *     *     *     *               
                 * *   * *   * *   * *              
                ***** ***** ***** *****             
               *                       *            
              * *                     * *           
             *****                   *****          
            *     *                 *     *         
           * *   * *               * *   * *        
          ***** *****             ***** *****       
         *           *           *           *      
        * *         * *         * *         * *     
       *****       *****       *****       *****    
      *     *     *     *     *     *     *     *   
     * *   * *   * *   * *   * *   * *   * *   * *  
    ***** ***** ***** ***** ***** ***** ***** *****

**/

#include <iostream>
using namespace std;

char map[3072][6143];

void draw(int r, int c) {
    //첫줄
    map[r][c]='*';
    //둘째줄
    map[r+1][c-1]='*';
    map[r+1][c+1]='*';
    //셋째줄
    for(int i=0; i<5; i++)
        map[r+2][c-2+i]='*';
}

void dfs(int len, int r, int c) {
    if(len==3) {
        draw(r, c);
        return;
    }
    
    dfs(len/2, r, c);
    dfs(len/2, r+len/2, c-len/2);
    dfs(len/2, r+len/2, c+len/2);
}

int main() {
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<2*N-1; j++)
            map[i][j]=' ';
	
    dfs(N, 0, N-1);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<2*N-1; j++)
            cout<<map[i][j];
        cout<<'\n';
    }
    
	return 0;
}