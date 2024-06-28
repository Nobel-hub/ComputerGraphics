#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
int tx,ty,sx,sy;
int theta;
float p[3][3]={{0,100,50},{0,0,50},{1,1,1}};
float r[3][3];
void draw_triangle(float tri[3][3]){
glColor3d(1,1,1);
glBegin(GL_TRIANGLES);
glVertex2f(tri[0][0],tri[1][0]);
glVertex2f(tri[0][1],tri[1][1]);
glVertex2f(tri[0][2],tri[1][2]);
glEnd();
}

void multiplication(float mul[3][3]){
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
r[i][j]=0;
for(int l=0;l<3;l++){
r[i][j]=r[i][j]+mul[i][l]*p[l][j];
}
}
}
}

void translate(){
float t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
multiplication(t);

}

void scaling(){
float s[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
multiplication(s);
}

void rotation(){
float radiance=theta*3.14/180;
float rot[3][3]={{cos(radiance),-sin(radiance),0},{sin(radiance),cos(radiance),0},{0,0,1}};
multiplication(rot);
}

void displayme(){
int choice;
glClear(GL_COLOR_BUFFER_BIT);
printf("enter 1 for translate 2 for scaling and 3 for rotation");
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter tx and ty");
scanf("%d %d",&tx,&ty);
translate();
draw_triangle(p);
break;
case 2:
printf("enter sx and sy");
scanf("%d %d",&sx,&sy);
scaling();
draw_triangle(r);
break;
case 3:
printf("enter the value of theta");
scanf("%d",&theta);
rotation();
draw_triangle(r);
}
glFlush();
}

void myinit(){
 glClearColor(1.0,0.0,0.0,1.0);
 gluOrtho2D(-200,500,-200,500);
}

int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(200,200);
glutCreateWindow("Hello World");
myinit();
glutDisplayFunc(displayme);
glutMainLoop();
return 0;
} 