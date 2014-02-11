#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;
void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       //set white back ground color  
	glColor3f(0.0, 0.0, 0.0);         //set the drawing color
	glPointSize(2.0);                   //dot is 4 by 4 pixel
	setWindow(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	
	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	double i,A=10;
	glBegin(GL_LINES);
	for(i=0;i<10*M_PI;i+=0.005)
	glVertex2f(350+A*i*cos(i),350+A*i*sin(i));
	glEnd();
	SOIL_save_screenshot("output/archimedean.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("cardiod");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
