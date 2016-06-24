#include <stdio.h>
#include <math.h>
#include "mult_mat.h"

void mult_mat(float mat1[16], float mat2[16])
{
        unsigned int i;
        float tmp[16];

        tmp[0]  = MULT(0,  0) + MULT(1,  4) + MULT(2,  8)  + MULT(3,  12);
        tmp[1]  = MULT(0,  1) + MULT(1,  5) + MULT(2,  9)  + MULT(3,  13);
        tmp[2]  = MULT(0,  2) + MULT(1,  6) + MULT(2,  10) + MULT(3,  14);
        tmp[3]  = MULT(0,  3) + MULT(1,  7) + MULT(2,  11) + MULT(3,  15);
        tmp[4]  = MULT(4,  0) + MULT(5,  4) + MULT(6,  8)  + MULT(7,  12);
        tmp[5]  = MULT(4,  1) + MULT(5,  5) + MULT(6,  9)  + MULT(7,  13);
        tmp[6]  = MULT(4,  2) + MULT(5,  6) + MULT(6,  10) + MULT(7,  14);
        tmp[7]  = MULT(4,  3) + MULT(5,  7) + MULT(6,  11) + MULT(7,  15);
        tmp[8]  = MULT(8,  0) + MULT(9,  4) + MULT(10, 8)  + MULT(11, 12);
        tmp[9]  = MULT(8,  1) + MULT(9,  5) + MULT(10, 9)  + MULT(11, 13);
        tmp[10] = MULT(8,  2) + MULT(9,  6) + MULT(10, 10) + MULT(11, 14);
        tmp[11] = MULT(8,  3) + MULT(9,  7) + MULT(10, 11) + MULT(11, 15);
        tmp[12] = MULT(12, 0) + MULT(13, 4) + MULT(14, 8)  + MULT(15, 12);
        tmp[13] = MULT(12, 1) + MULT(13, 5) + MULT(14, 9)  + MULT(15, 13);
        tmp[14] = MULT(12, 2) + MULT(13, 6) + MULT(14, 10) + MULT(15, 14);
        tmp[15] = MULT(12, 3) + MULT(13, 7) + MULT(14, 11) + MULT(15, 15);

        for (i=0; i<16; i++) {
                mat1[i] = tmp[i];
        }       
}

void mult_v(float mat1[16], float mat2[4])
{
        unsigned int i;
        float tmp[4];

        tmp[0] = MULT(0, 0) + MULT(1, 1) + MULT(2, 2) + MULT(3, 3);
        tmp[1] = MULT(4, 0) + MULT(5, 1) + MULT(6, 2) + MULT(7, 3);
        tmp[2] = MULT(8, 0) + MULT(9, 1) + MULT(10, 2) + MULT(11, 3);
        tmp[2] = MULT(12, 0) + MULT(13, 1) + MULT(14, 2) + MULT(15, 3);

        for (i=0; i<4; i++) {
                mat2[i] = tmp[i];
        }
}
