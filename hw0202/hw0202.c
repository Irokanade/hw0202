//
//  hw0202.c
//  hw0202
//
//  Created by Michael Leong on 2021/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "longtobinary.h"


int main() {
    char floatingPointStr[65];
    char *pEnd = NULL;
    doubleFP floatingPointNum;
    char exponentStr[11] = {0};
    char mantissaStr[53] = {0};
    
    printf("Please enter a floating-point number (double precision): ");
    fgets(floatingPointStr, 65, stdin);
    floatingPointNum.doubleNum = strtod(floatingPointStr, &pEnd);
    if(pEnd != NULL) {
        printf("%lf\n", floatingPointNum.doubleNum);
    } else {
        printf("Conversion failed\n");
        return 1;
    }

    longToBin(floatingPointNum.ieeeDouble.exponent, exponentStr, 11);
    longToBin(floatingPointNum.ieeeDouble.mantissa, mantissaStr, 52);
    
    printf("sign: %d\n", floatingPointNum.ieeeDouble.sign);
    printf("exponent: %s\n", exponentStr);
    printf("mantissa: %s\n", mantissaStr);
    printDoubleConvert(floatingPointNum);
    
    return 0;
}
