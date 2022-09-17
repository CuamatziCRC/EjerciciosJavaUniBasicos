#include<windows.h>
#include<C:\GLUT\include\GL\glut.h>
#include <Stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void iniciarPantalla(){
	glClearColor(0,0,0,0.0);//(rojo,verde,azul) fondo azul cielo
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,300.0,0.0,300.0);//proyeccion ortogonal en 2 dimensiones
}

void rectangulos(int x0,int y0,int x1,int y1,int x2, int y2,int x3, int y3, float R,float G,float B)
{
	glColor3f(R,G,B);
	glBegin(GL_QUADS);
	glVertex2f(x0, y0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glEnd();
}

void tallo(){

 rectangulos(120,150,110,150,110,20,120,20,0,1,0);
 //triangulos(60,0,80,80,100,0,R,G,B); //tercer cerro
}

void dibujarcentro(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255,255,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(120,180);
    glVertex2f(130,170);
    glVertex2f(130,160);
    glVertex2f(120,150);//4
    glVertex2f(110,150);
    glVertex2f(100,160);
    glVertex2f(100,170);
    glVertex2f(110,180);//8
    glEnd();


}


void Hojas(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255,0,127);
    glBegin(GL_POLYGON);
    //Hoja 1
    glVertex2f(120,180);
    glVertex2f(130,200);
    glVertex2f(170,210);
    glVertex2f(150,180);
    glVertex2f(130,170);
    //Hoja2
    glVertex2f(130,170);//1
    glVertex2f(150,180);//2
    glVertex2f(170,170);//3
    glVertex2f(150,150);//4
    glVertex2f(130,160);//5
    //Hoja3
    glVertex2f(130,160);//1
    glVertex2f(150,150);//2
    glVertex2f(170,120);//3
    glVertex2f(130,130);//4
    glVertex2f(120,150);//5
    //Hoja4
    glVertex2f(120,150);//1
    glVertex2f(130,130);//2
    glVertex2f(120,100);//3
    glVertex2f(100,130);//4
    glVertex2f(110,150);//5
    //Hoja5
    glVertex2f(110,150);//1
    glVertex2f(100,130);//2
    glVertex2f(60,120);//3
    glVertex2f(80,150);//4
    glVertex2f(100,160);//5
    //Hoja6
    glVertex2f(100,170);//1
    glVertex2f(80,150);//2
    glVertex2f(60,170);//3
    glVertex2f(80,180);//4
    glVertex2f(100,170);//5
    //Hoja7
    glVertex2f(100,170);//1
    glVertex2f(80,180);//2
    glVertex2f(60,210);//3
    glVertex2f(100,210);//4
    glVertex2f(110,180);//5
    //Hoja8
    glVertex2f(110,180);//1
    glVertex2f(100,210);//2
    glVertex2f(110,230);//3
    glVertex2f(130,200);//4
    glVertex2f(120,180);//5

    glEnd();

}

void FondoDeEscritorio(){
	glClear(GL_COLOR_BUFFER_BIT);//ya pone el color de fondo en la pantalla
	glColor3f(1.0,0.0,0.0);//(rojo,verde,azul)
	//funciones

	dibujarcentro();
	tallo();

	/*
	dibujarcentro();
	Hojas();
    */
	glFlush();

}

int main(int argc, char *argv[])
{

	glutInit(&argc,argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Cristian Reyes Cuamatzi");
	iniciarPantalla();
	glutDisplayFunc(FondoDeEscritorio);
	glutMainLoop();
}

