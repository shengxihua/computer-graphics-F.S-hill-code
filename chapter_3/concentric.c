#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"
const int  N=3;
const screenWidth =  700;
const screenHeight = 700;
struct GLfloatPoint conc[6];
int count;
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
	int i,j;
	for(count=0;count<N;count++)
	{
		conc[count].x=point[count].x=radius*cos(phi * count+33);
		conc[count].y=point[count].y=radius*sin(phi * count+33);
	}
	radius=radius*0.2;
	for(;count<2*N;count++)
	{
		conc[count].x=point[count].x=radius*cos(phi * count+34.03);
		conc[count].y=point[count].y=radius*sin(phi * count+34.03);
	}
	
	for(i=0;i<2*N;i++)
	{
		for(j=0;j<N;j=j+1)
		{
			if(i*j%2==0)
			glColor3f(1.0f,1.0f,0.0f);
			if((i+j)%2==0)
			glColor3f(1.0f,0.0f,1.0f);
			moveTo(conc[i].x,conc[i].y);
			lineTo(conc[j].x,conc[j].y);
		}
	}
	return radius;
}

void render()
{
	float radius;
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0.0,0.0,screenWidth,screenHeight);
	radius=rosette(N,0.75);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	setWindow(0.0,screenWidth,0.0,screenHeight);
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("rosette");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}
