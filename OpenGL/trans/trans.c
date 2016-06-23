/*
 * myTranslatef(). myScalef(). myRotatef().
 * */
#include <stdio.h>
#include <GL/glut.h>
#include "mult_mat.h"


GLfloat trans_mat[16] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0,
};

void init(void)
{
        glClearColor(1.0, 0.0, 1.0, 0.0);
}

void reshape(int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void display_gl(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(-2, 0, 0);
        glScalef(1.0, 2.0, 1.0);
        glRotatef(60, 0, 0, 1);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glPopMatrix();
        glEnd();

        glFlush();
}

myTranslatef(float x, float y, float z)
{
        GLfloat tmp[16] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 0,
        };
        tmp[3] = x;
        tmp[7] = y;
        tmp[11] = z;

        mult_mat(tmp, trans_mat);
}
myScalef(float x, float y, float z)
{
        GLfloat tmp[16] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1,
        };
        if (x != 0) {
                tmp[0] = x;
        }
        if (y != 0) {
                tmp[5] = y;
        }
        if (z != 0) {
                tmp[10] = z;
        }

        mult_mat(tmp, trans_mat);

}

myRotatef(float angle, float x, float y, float z)
{
        // http://www.tuicool.com/articles/ZJBvM3
        float length = sqrt( x * x + y * y + z * z );
        float tmp[16] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1};
        x /= length;
        y /= length;
        z /= length;

        float alpha = angle / 180 * 3.1415926;
        float s = sin( alpha );
        float c = cos( alpha );
        float t = 1.0f - c;
#if 1
#define MATRIX( row, col ) tmp[row * 4 + col]
        MATRIX( 0, 0 ) = t * x * x + c;
        MATRIX( 1, 0 ) = t * x * y + s * z;
        MATRIX( 2, 0 ) = t * x * z - s * y;
        MATRIX( 3, 0 ) = 0.0f;
        MATRIX( 0, 1 ) = t * x * y - s * z;
        MATRIX( 1, 1 ) = t * y * y + c;
        MATRIX( 2, 1 ) = t * y * z + s * x;
        MATRIX( 3, 1 ) = 0.0f;
        MATRIX( 0, 2 ) = t * x * z + s * y;
        MATRIX( 1, 2 ) = t * y * z - s * x;
        MATRIX( 2, 2 ) = t * z * z + c;
        MATRIX( 3, 2 ) = 0.0f;
        MATRIX( 0, 3 ) = 0.0f;
        MATRIX( 1, 3 ) = 0.0f;
        MATRIX( 2, 3 ) = 0.0f;
        MATRIX( 3, 3 ) = 1.0f;
#undef MATRIX
#else
#define MATRIX( row, col ) tmp[row * 4 + col]
        MATRIX( 0, 0 ) = t * x * x + c;
        MATRIX( 0, 1 ) = t * x * y + s * z;
        MATRIX( 0, 2 ) = t * x * z - s * y;
        MATRIX( 0, 3 ) = 0.0f;
        MATRIX( 1, 0 ) = t * x * y - s * z;
        MATRIX( 1, 1 ) = t * y * y + c;
        MATRIX( 1, 2 ) = t * y * z + s * x;
        MATRIX( 1, 3 ) = 0.0f;
        MATRIX( 2, 0 ) = t * x * z + s * y;
        MATRIX( 2, 1 ) = t * y * z - s * x;
        MATRIX( 2, 2 ) = t * z * z + c;
        MATRIX( 2, 3 ) = 0.0f;
        MATRIX( 3, 0 ) = 0.0f;
        MATRIX( 3, 1 ) = 0.0f;
        MATRIX( 3, 2 ) = 0.0f;
        MATRIX( 3, 3 ) = 1.0f;
#undef MATRIX
#endif
        mult_mat(tmp, trans_mat);
        myScalef(x, y, z);
#if 0
        GLfloat tmp[16] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1,
        };
        tmp[5] = cos(angle);
        tmp[6] = -sin(angle);
        tmp[9] = sin(angle);
        tmp[10] = cos(angle);
        mult_mat(tmp, trans_mat);
//      myScalef(x, y, z);
#endif
}

void display_mytrans()
{
        GLfloat tmp[4];
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glPushMatrix();
//        myTranslatef(-2, 0, 0);
//        myScalef(1.0, 2.0, 1.0);
        myRotatef(60, 0, 0, 1);
        printf("%f %f %f %f\n", trans_mat[0], trans_mat[1], trans_mat[2], trans_mat[3]);
        printf("%f %f %f %f\n", trans_mat[4], trans_mat[5], trans_mat[6], trans_mat[7]);
        printf("%f %f %f %f\n", trans_mat[8], trans_mat[9], trans_mat[10], trans_mat[11]);
        printf("%f %f %f %f\n", trans_mat[12], trans_mat[13], trans_mat[14], trans_mat[15]);
        glBegin(GL_TRIANGLES);
        tmp[0]=0.0; tmp[1]=0.0; tmp[2]=0.0; tmp[3]=1.0;
        mult_v(trans_mat, tmp);
        printf("### %f %f %f %f \n", tmp[0], tmp[1], tmp[2], tmp[3]);
        glVertex3f(tmp[0], tmp[1], tmp[2]);

        tmp[0]=0.0; tmp[1]=1.0; tmp[2]=0.0; tmp[3]=1.0;
        mult_v(trans_mat, tmp);
        printf("### %f %f %f %f \n", tmp[0], tmp[1], tmp[2], tmp[3]);
        glVertex3f(tmp[0], tmp[1], tmp[2]);

        tmp[0]=1.0; tmp[1]=1.0; tmp[2]=0.0; tmp[3]=1.0;
        mult_v(trans_mat, tmp);
        printf("### %f %f %f %f \n", tmp[0], tmp[1], tmp[2], tmp[3]);
        glVertex3f(tmp[0], tmp[1], tmp[2]);
        glEnd();
        glPopMatrix();
        glFlush();
}

void display(void)
{
#if 1
        display_gl();
#else
        display_mytrans();
#endif
}

int main(int argc, char *argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
        glutInitWindowSize(480, 320);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Test_GL_trans");
        init();
        glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        glutMainLoop();
}
