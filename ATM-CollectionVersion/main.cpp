#include <iostream>
#include "Ui.h"

int main() {
    Ui ui;
    ui.consola();

    return 0;
}

//void backtracking(int v[], int occ[], int sum, int ans, int tmp[], int start) {
//    if(sum == 0){
//
//    }
//
//int v[4] = {120, 20, 30, 60};
//int occ[4] = {100, 50, 20, 10};
//
//int sum = 360;
//int copy = 0;
//
//int index_left=0, index_right=0, index = 0;
//int arr[4] ={};
//
//while(index_left <= index_right){
//while(copy < sum) {
//
//dc o bancnota e deja mai mare ca suma
//if(v[index] > sum)
//break;
//int occ_a = v[index] / occ[index];
//if (occ_a > occ[index]) //daca nu exista atatea bancnote
//occ_a = occ[index];
//if (sum - copy < occ_a) //daca se adauga mai multe decat trebuie
//continue;
//copy = v[index] * occ_a;
//}
//}

//}
