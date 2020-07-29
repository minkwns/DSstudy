
/* Polynomial 
 * 문제 : 차례로 주어지는 두 숫자로 하나의 항을 만들고, 주어진 항을 모아 하나의 다항식을 만든다. 그렇게 만들어진 두 다항식의 합과 곱을 출력한다.
 * 구현 : 2차원 배열을 이용하여 구현한다.
 * 사용하게 될 함수 : toString(term 제작), swap, addTerm(배열에 담아 poly 만들기), sorting(bubble sort), 
    fix(배열 안 null 값 제거하고, 차수가 같은 것들은 합해서 정리), displayPoly(), addPoly(두 다항식의 합), multiPoly(두 다항식의 곱) 
 * 주의할 점 : 기존에 있는 문제가 아니라 생각한 대로 구현하였기 때문에 디버깅을 하면 오류가 많이 존재할 수 있다.              
 */

#include <stdio.h>

static int count = 0;
static int addCount = 0;
static int multiCount = 0;

void toString(int coef, int exp) {
    printf("%dx^%d", coef, exp);
}

void swap(int *a, int *b){ // swap function , 포인터를 사용하지 않으면 변경이 직접 이뤄지지 않음
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void addTerm(int a[][10], int coef, int exp){
    if(a[0][0] == 0) count = 0; // 다른 배열을 받는 것으로 인식
    a[0][count] = coef;
    a[1][count] = exp;
    count++;
}

void sorting(int a[][10]){ // bubble sorting

    for(int i = 0; i < sizeof(a[0])/sizeof(int); i++){
        for(int j = 0; j < sizeof(a[0])/sizeof(int)-1; j++){
            if(a[1][j] < a[1][j+1]){
                swap(&a[1][j], &a[1][j+1]); // exp 에 따라 내림차순으로 정렬
                swap(&a[0][j], &a[0][j+1]); // exp 에 맞는 coef 따라서 정렬
            }
        }
    }
}

void fix(int a[][10]){ // 배열 사이에 지수가 같은 수 다 더해줌
    for(int i = 0; i < sizeof(a[0])/sizeof(int); i++){
        for(int j = i+1; j < sizeof(a[0])/sizeof(int)-1; j++){
            if(a[1][i] == a[1][j] && a[1][i] != 0){
                a[0][i] = a[0][i] + a[0][j];
                a[0][j] = NULL;
                a[1][j] = NULL;
            }
        }
    }
    sorting(a);
}

void displayPoly(int a[][10]){
    int bin = 0;
    for(int i = 0; i < sizeof(a[0])/sizeof(int); i++){
        if(a[0][i] == 0 || a[1][i] == 0) continue;
        else if(bin == 0){
            toString(a[0][i], a[1][i]);
            bin = 1;
        }
        else {
            printf(" + ");
            toString(a[0][i], a[1][i]);
            bin = 1;
        }

    }
    printf("\n");
}

void addPoly(int a[][10], int b[][10]){  //

    int poly[][10] = {NULL, };

    for(int i = 0; i < sizeof(a[0])/sizeof(int); i++){
        if(a[0][i] != 0 && a[1][i] != 0){
            poly[0][addCount] = a[0][i];
            poly[1][addCount] = a[1][i];
            addCount++;
        }
    }
    for(int i = 0; i < sizeof(b[0])/sizeof(int); i++){
        if(a[0][i] != 0 && b[1][i] != 0){
            poly[0][addCount] = b[0][i];
            poly[1][addCount] = b[1][i];
            addCount++;
        }
    }

    fix(poly);
    displayPoly(poly);

    printf("\n");
    return;
}


void multiPoly(int a[][10], int b[][10]){

    int poly[][10] = {NULL, };
    for(int i = 0; i < sizeof(a[0])/sizeof(int); i++){
        for(int j = 0; j < sizeof(a[0])/sizeof(int); j++){
            if((a[0][i]==0) || (a[0][j]==0)|| (b[0][i] == 0)||(b[0][j] == 0)) break;

            poly[0][multiCount] = a[0][i] * b[0][j];
            poly[1][multiCount] = a[1][i] + b[1][j];
            multiCount++;
        }
        
    }
    fix(poly);
    displayPoly(poly);
}

int main(){
    /* Class를 사용하면 더 좋은 모습이겠지만 c로 구현하는 거라 다소 복잡하게 구현 */

    int term1[2][10] = {NULL, };
    int term2[2][10] = {NULL, };

    /* polynomial1 생성 */
    addTerm(term1, 2, 3);
//    addTerm(term1, 5, 5);
    addTerm(term1, 4, 4);

    /* polynomial2 생성 */
//    addTerm(term2, 5, 3);
    addTerm(term2, 5, 1);
    addTerm(term2, 7,4);

    /* poly1, poly2를 각각 계수에 맞게 더한 addPoly, 모든 항을 곱하고 정리한 multiPoly */

    printf("Term1 is ");
    displayPoly(term1);
    printf("Term2 is ");
    displayPoly(term2);

    printf("Result of Adding Poly is ");
    addPoly(term1, term2);
    printf("Result of Multifying Poly is ");
    multiPoly(term1, term2);
    return 0;
}

