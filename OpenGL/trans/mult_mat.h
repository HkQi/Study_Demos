#ifndef __MULT_MAT_H__
#define __MULT_MAT_H__

#include <stdio.h>

#define MULT(x, y) (mat1[x]*mat2[y])


void mult_mat(float mat1[16], float mat2[16]);
void mult_v(float mat1[16], float mat2[4]);

#endif // __MULT_MAT_H__
