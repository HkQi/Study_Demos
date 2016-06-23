// Just for Test

#include "mult_mat.h"

int main()
{

        float InitMatrix[16] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1};

        float TransMatrix[16]={  
                1., 0., 0., 0.,  
                0., 1., 0., 0.,  
                0., 0., 1., 0.,  
                0., 0., -5., 1.0  
        }; 
        float ScaleMatrix[16]={  
                1., 0., 0., 0.,  
                0., 2., 0., 0.,  
                0., 0., 1., 0.,  
                0., 0., 0., 1.0  
        };  
        float RotateMatrix[16]={  
                1., 0., 0., 0.,  
                0., cos(20.0), sin(20.0), 0.,  
                0., -sin(20.0), cos(20.0), 0.,  
                0., 0., 0., 1.0  
        };


        mult_mat(TransMatrix, InitMatrix);
        mult_mat(ScaleMatrix, InitMatrix);
        mult_mat(RotateMatrix, InitMatrix);
#if 0
        mult_mat(InitMatrix, TransMatrix);
        mult_mat(InitMatrix, ScaleMatrix);
        mult_mat(InitMatrix, RotateMatrix);
#endif

        printf("%f %f %f %f\n", InitMatrix[0], InitMatrix[1], InitMatrix[2], InitMatrix[3]);
        printf("%f %f %f %f\n", InitMatrix[4], InitMatrix[5], InitMatrix[6], InitMatrix[7]);
        printf("%f %f %f %f\n", InitMatrix[8], InitMatrix[9], InitMatrix[10], InitMatrix[11]);
        printf("%f %f %f %f\n", InitMatrix[12], InitMatrix[13], InitMatrix[14], InitMatrix[15]);
}
