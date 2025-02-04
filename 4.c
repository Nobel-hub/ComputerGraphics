#include <stdio.h>
#include <GL/glut.h>

int op;
typedef float point[3];
point a = {0.0, 0.0, 1.0};
point b = {0.0, 1.0, 0.0};
point c = {-1.0, -1.0, 0.0};
point d = {1.0, -1.0, 0.0};


void myInit()
{
glClearColor(1, 1, 1, 0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void triangle(point a, point b, point c)
{
glBegin(GL_TRIANGLES);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}

void divtri(point x, point y, point z, int m)
{
if (m == 0)
{
triangle(x, y, z);
return;
}
else if (m > 0)
{
point v1, v2, v3;
for (int i = 0; i < 3; i++)
{
v1[i] = (x[i] + y[i]) / 2;
}
for (int i = 0; i < 3; i++)
{
v2[i] = (x[i] + z[i]) / 2;
}
for (int i = 0; i < 3; i++)
{
v3[i] = (z[i] + y[i]) / 2;
}

divtri(x, v1, v2, m - 1);
divtri(v1, y, v3, m - 1);
divtri(v3, v2, z, m - 1);
}
}
void tetra(int g)
{
glColor3f(1, 0, 0);
divtri(a, b, c, g);
glColor3f(0, 1, 0);
divtri(a, b, d, g);
glColor3f(0, 0, 1);
divtri(a, c, d, g);
glColor3f(0, 0, 0);
divtri(b, d, c, g);
}
void display()
{
tetra(2);
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(400, 400);
glutCreateWindow("1CR21CS014");
myInit();
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}