#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include"function.h"
 
const screenWidth=700;
const screenHeight=700;

void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);	
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	setWindow(0.0,screenWidth,0.0,screenHeight);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	drawCircle(screenWidth/2,screenHeight/2,200);
	glColor3f(0.0f,0.0f,0.0f);
	drawCircle(screenWidth/2-100,screenHeight/2,100);
	glColor3f(1.0f,1.0f,1.0f);
	drawCircle(screenWidth/2+100,screenHeight/2,100);
	drawCircle(screenWidth/2-100,screenHeight/2,20);
	glColor3f(0.0f,0.0f,0.0f);
	drawCircle(screenWidth/2+100,screenHeight/2,20);
	
	glFlush();
}
void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("yin yang");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}

