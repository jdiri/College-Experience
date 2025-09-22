#include <stdio.h>

#define subm(a,b) a-b
#define squared_addm(a,b) (a+b)*(a+b)
#define smallerm(a,b) ((a) < (b) ? (a) : (b))
#define evenm(a) ((a) % 2 == 0 ? 1 : 0)
int subf(int a, int b) {

    return a - b;

}

int squared_addf(int a, int b) {

    return (a + b) * (a + b);

}

int smallerf(int a, int b) {

    if (a < b) {

        return a;

    }

    else {

        return b;

    }

}

int evenf(int a) {

    if (a % 2 == 0) {

         return 1;

    }

    else {

        return 0;

    }

}

int main()
{
    // test case 1
    printf("test case 1\n");

    int a = 3, b = 6;

    printf("subf(a, b) = %d, while a=%d, b=%d\n", subf(a, b), a, b);

    printf("subm(a, b) = %d, while a=%d, b=%d\n", subm(a, b), a, b);

    printf("subf(a++, b--) = %d, while a=%d, b=%d\n", subf(a++, b--), a, b);

    a = 3, b = 6;      // reset a, b values;
    printf("subm(a++, b--) = %d, while a=%d, b=%d\n", subm(a++, b--), a, b);



    //test case 2
    printf("\ntest case 2\n");

    a = 3, b = 6;

    printf("squared_addf(a, b) = %d, while a=%d, b=%d\n", squared_addf(a, b), a, b);

    printf("squared_addm(a, b) = %d, while a=%d, b=%d\n", squared_addm(a, b), a, b);

    printf("squared_addf(--a, b++) = %d, while a=%d, b=%d\n", squared_addf(--a, b++), a, b);

    a = 3; b = 6;

    printf("squared_addm(--a, b++) = %d, while a=%d, b=%d\n", squared_addm(--a, b++), a, b);

    

    //test case 3
    printf("\ntest case 3\n");

    a = 3; b = 6;

    printf("smallerf(a,b) = %d, while a=%d, b=%d\n", smallerf(a,b), a, b);
    
    printf("smallerm(a,b) = %d, while a=%d, b=%d\n", smallerm(a,b), a, b);

    printf("smallerf(--a,b) = %d, while a=%d, b=%d\n", smallerf(--a,b), a, b);

    a = 3; b = 6;

    printf("smallerm(--a,b) = %d, while a=%d, b=%d\n", smallerm(--a,b), a, b);

    //test case 4
    printf("\ntest case 4\n");

    a = 3; b = 6;

    printf("evenf(a) = %d, while a=%d\n", evenf(a), a);

    printf("evenm(a) = %d, while a=%d\n", evenm(a), a);

    printf("evenf(++a) = %d, while a=%d\n", evenf(++a), a);

    a = 3; b = 6;

    printf("evenm(++a) = %d, while a=%d\n", evenm(++a), a);

}
