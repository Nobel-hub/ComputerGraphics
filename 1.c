#include <GL/glut.h>
#include<math.h>
int x,y,dy,dx,k,p;

void myinit(){
glClearColor(1.0,0.0,0.0,1.0);
gluOrtho2D(0,500,0,500);
}

void plotpoints(int x, int y){
glColor3d(1,0,0);
glBegin(GL_POINTS);
glVertex2d(x,y);
glEnd();
}

void plotpoints_neg(int x, int y){
glColor3d(0,0,1);
glBegin(GL_POINTS);
glVertex2d(x,y);
glEnd();
}

void bresenhams(int x1, int y11, int x2, int y2){
x = x1;
y = y11;
plotpoints(x,y);
dx = x2-x1;
dy = y2-y11;
p = 2*dy-dx;
//m>1                                                            
if(dx>dy){
for(k=0;k<dx;k++){
if(p<0){
x = x+1;
y=y;
p = p + 2 * dy;
}
else{
x = x+1;
y = y+1;
p = p + 2*dy-2*dx;
}
plotpoints(x,y);
}
}
//m<1
else{
for(k=0;k<dy;k++){
if(p<0){
y = y+1;
x=x;
p = p + 2 * dx;
}
else{
y = y+1;
x = x+1;
p = p + 2*dx-2*dy;
}
plotpoints(x,y);
}
}
}

void bresenhams_neg(int x1, int y11, int x2, int y2){
int incx=1, incy=1;
if(x2<x1) incx = -1;
if(y2<y11) incy = -1;
x = x1;
y = y11;
plotpoints_neg(x,y);
dx = abs(x2-x1);
dy = abs(y2-y11);
p = 2*dy-dx;
//m>1
if(dx>dy){
for(k=0;k<dx;k++){
if(p<0){
x = x+incx;
y=y;
p = p + 2 * dy;
}
else{
x = x+incx;
y = y+incy;
p = p + 2*dy-2*dx;
}
plotpoints_neg(x,y);
}
}
//m<1
else{
for(k=0;k<dy;k++){
if(p<0){
y = y+incy;
x=x;
p = p + 2 * dx;
}
else{
y = y+incy;
x = x+incx;
p = p + 2*dx-2*dy;
}
plotpoints_neg(x,y);
}
}
}


void display()
{
glClearColor(0.0,0.1,0.1,0.5);
glClear(GL_COLOR_BUFFER_BIT);
//POSITIVE SLOPE
bresenhams(100,100,300,150);
bresenhams(100,100,150,300);
bresenhams(100,100,300,300);
//NEGATIVE SLOPE
bresenhams_neg(100,300,50,50);
bresenhams_neg(300,200,50,50);
bresenhams_neg(400,400,50,50);

glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("BRESENHAM'S ALGORITHM");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}