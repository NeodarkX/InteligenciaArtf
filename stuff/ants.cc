#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tablero[121][121];
#define BASEPOS 60

void init(){
    for(int i=0;i<121;i++){
        for(int j=0;j<121;j++){
            tablero[i][j]=-1;
        }
    }
}


int main() {
    // your code goes here
    int T,N,C;
    int f=BASEPOS,c=BASEPOS;
    char M; // movimiento
    cin >> T;
    for(int i=0;i<T;i++){
        //Para cada caso
        cin >> N;
        C=0; // contador
        init();
        tablero[BASEPOS][BASEPOS] = 0;
        f=BASEPOS;
        c=BASEPOS;
        for(int j=0;j<N;j++){
            cin >> M;
            if(M=='N')    f--;
            else if(M=='S') f++;
            else if(M=='W') c--;
            else if(M=='E') c++;
            if(tablero[f][c]==-1 ){
                tablero[f][c]=++C;
            }else if(tablero[f][c]<C){
                C=tablero[f][c];
            }
        }
        cout << C << endl;


    }


    return 0;
}