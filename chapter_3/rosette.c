#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"

const screenWidth =  700;
const screenHeight = 700;

void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	
}

float rosette(int N,float radius)
{ 
	struct GLfloatPoint point[N];
	float phi=(2* M_PI)/N;
	int count,i,j;
	for(count=0;count<N;count++)
	{
		point[count].x=radius*cos(phi * count+34.03);
		point[count].y=radius*sin(phi * count+34.03);
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i*j%2==0)
			glColor3f(1.0f,1.0f,0.0f);
			if((i+j)%2==0)
			glColor3f(1.0f,0.0f,1.0f);
			moveTo(point[i].x,point[i].y);
			lineTo(point[j].x,point[j].y);
		}
	}
	float pi=(1+sqrt(5))/2;
	radius=radius/(1+pi*pi);
	return radius;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,screenWidth,screenHeight);
	rosette(5,0.75);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("rosette");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}
