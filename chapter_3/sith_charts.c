#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include<time.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;

void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       
	glColor3f(0.0, 0.0, 0.0);         
	glPointSize(5.0);                   
	//setWindow(0.0,screenWidth,0.0,screenHeight);
	setWindow(-2*M_PI,2*M_PI,-2*M_PI,2*M_PI);
	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float a=100,b=-100,m=0,n=0;
	struct GLfloatPoint center;
	center.x=350.0;
	center.y=350.0;	
	//setViewport(0.0,screenWidth,0.0,screenHeight);
	drawDot(0.0,0.0);
	for(m=0,n=0;m<=M_PI;m+=0.1,n+=0.1)
	{
		glBegin(GL_LINE_STRIP);
		drawCircle((1-m),0.0,m);
		glBegin(GL_LINE_STRIP);
		drawCircle(1,n,n);
		glBegin(GL_LINE_STRIP);
		drawCircle(1,-n,n);
	}
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("orthogonal");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
