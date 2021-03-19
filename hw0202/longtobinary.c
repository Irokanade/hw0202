//
//  longtobinary.c
//  hw0202
//
//  Created by Michael Leong on 2021/3/19.
//

#include "longtobinary.h"
#include <string.h>
#include <stdlib.h>

int longToBin(unsigned long longNum, char *binStr, size_t len) {
    
    if(binStr == NULL) {
        //error nothing to return
        return 1;
    }
    memset(binStr, 0, strlen(binStr));
    
    printf("longNum: %ld\n", longNum);
    
    for(long int i = len-1; i >= 0; i--) {
        //printf("i: %d\n", i);
        if(1 & (longNum >> i)) {
            //printf("1");
            strcat(binStr, "1");
        } else {
            //printf("0");
            strcat(binStr, "0");
        }
    }
    //printf("\n");
    
    return 0;
}

void printDoubleConvert(doubleFP floatingPointNum) {
    char binSumStr[1024] = {0};
    
    //binary sum of mantissa "fraction part"
    for(long int i = 51; i >= 0; i--) {
        if(1 & (floatingPointNum.ieeeDouble.mantissa >> i)) {
            char numTemp[3] = {0};
            if(binSumStr[0] == 0) {
                sprintf(numTemp, "%ld", 52-i);
                strncat(binSumStr, "2^-", 3);
                strncat(binSumStr, numTemp, 3);
            } else {
                sprintf(numTemp, "%ld", 52-i);
                strncat(binSumStr, " + 2^-", 6);
                strncat(binSumStr, numTemp, 3);
            }
        }
    }
    
    printf("%lf = (-1)^%d * %s * 2^(1023 - %d)\n", floatingPointNum.doubleNum, floatingPointNum.ieeeDouble.sign, binSumStr, floatingPointNum.ieeeDouble.exponent);
}
