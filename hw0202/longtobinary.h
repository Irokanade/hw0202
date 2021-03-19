//
//  longtobinary.h
//  hw0202
//
//  Created by Michael Leong on 2021/3/19.
//

#ifndef longtobinary_h
#define longtobinary_h

#include <stdio.h>

typedef struct _IEEE_double {
    unsigned long mantissa:52;
    unsigned long exponent:11;
    unsigned long sign:1;
} IEEE_double;

typedef union _doubleFP {
    IEEE_double ieeeDouble;
    double doubleNum;
} doubleFP;


int longToBin(unsigned long longNum, char *binStr, size_t len);
void printDoubleConvert(doubleFP floatingPointNum);

#endif /* longtobinary_h */
