#define GLUT_DISABLE_ATEXIT_HACK

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include "Obj.h"
#include "loadTexture.h"
#include "thirdView.h"

using namespace std;

float doorRotate = 0;
bool doorRo = false;

int wHeight = 0;
int wWidth = 0;

bool light = true;
extern bool first;
extern GLfloat rad;

GLuint floorTex, wallTex, doorTex, frontTex,deskTex;

ObjModel chair;
ObjModel sofa;
ObjModel tv;
ObjModel tvStand;
ObjModel pillow;
ObjModel ipad;
ObjModel apple;
ObjModel table;
ObjModel flower;

void drawCube(){
	glutSolidCube(1.0);
	glBegin(GL_QUADS);
	// 前面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // 纹理和四边形的左上
	// 后面
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // 纹理和四边形的左下
	// 顶面
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // 纹理和四边形的右上
	// 底面
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f); // 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // 纹理和四边形的右下
	// 右面
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f); // 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // 纹理和四边形的左下
	// 左面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // 纹理和四边形的左上
	glEnd();
	glFlush();
}

//墙壁
void drawWall(){
	glEnable(GL_TEXTURE_2D);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(0, 0, -8);
	glScalef(10, 4, 0.2);
	drawCube(); 
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(10, 0, 0);
	glScalef(0.1, 4, 8);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(-10, 0, 0);
	glScalef(0.1, 4, 8);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(0, 4, 0);
	glScalef(10, 0.2, 8);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(0, 4, 0);
	glScalef(10, 0.2, 8);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(6, 0, 8);
	glScalef(4, 4, 0.2);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glTranslatef(-6, 0, 8);
	glScalef(4, 4, 0.2);
	drawCube();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, frontTex);
	glTranslatef(0, 3, 8);
	glScalef(2, 1, 0.2);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, doorTex);
	glTranslatef(0, -1, 8);
	glTranslatef(2, 0, 0);
	glRotatef(doorRotate, 0, -1, 0);
	glTranslatef(-2, 0, 0);
	glScalef(2, 3, 0.2);
	drawCube();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}
//地板
void drawFloor(){
	glEnable(GL_TEXTURE_2D);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 4);
	glBindTexture(GL_TEXTURE_2D, floorTex);

	glPushMatrix();
	glTranslatef(0, -4, 0);
	glScalef(10, 0, 8);	
//	glutSolidCube(1.0);
	glBegin(GL_QUADS);
	GLfloat divide = 10;
	GLfloat unit = 2 / divide;
	for (int i = 0; i < divide; i++)
	for (int j = 0; j < divide; j++){
		GLfloat x0 = unit * i - 1.0;
		GLfloat z0 = unit * j - 1.0;
		glTexCoord2i(0, 0);glVertex3f(x0, -1.0, z0);
		glTexCoord2i(1, 0);glVertex3f(x0 + unit, -1.0, z0);
		glTexCoord2i(1, 1);glVertex3f(x0 + unit, -1.0, z0 + unit);
		glTexCoord2i(0, 1);glVertex3f(x0, -1.0, z0 + unit);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

//桌子
void drawDesk(){
	glEnable(GL_TEXTURE_2D);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5);
	glPushMatrix();
	glTranslatef(4, -3, 0);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTranslatef(0, 0.3, 0);
	glScalef(2, 0.1, 1);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTranslatef(1.1, -0.65, -0.6);
	glScalef(0.1, 0.9, 0.1);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTranslatef(1.1, -0.65, 0.6);
	glScalef(0.1, 0.9, 0.1);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTranslatef(-1.1, -0.65, -0.6);
	glScalef(0.1, 0.9, 0.1);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTranslatef(-1.1, -0.65, 0.6);
	glScalef(0.1, 0.9, 0.1);
	drawCube();
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}

//void drawWindow(){
//	glEnable(GL_TEXTURE_2D);
//	glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, window);
//	glTranslatef(-10, 0, 0);
//	glScalef(0.2, 1, 1.5);
//	drawCube();
//	glPopMatrix();
//}


//绘制函数
void draw(){
	float color[4] = { 1, 1, 1, 1.0f };
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
	GLUquadric* quadric = gluNewQuadric();
	gluQuadricOrientation(quadric, GLU_OUTSIDE);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluDeleteQuadric(quadric);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	drawWall();
	drawFloor();
	drawDesk();
	//drawWindow();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glScalef(3, 3, 3);
	tv.draw();
	glPopMatrix();


	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glScalef(3, 2, 2);
	tvStand.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	ipad.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(15, -1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	pillow.draw();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	apple.draw();
	glPopMatrix();

	glPushMatrix();
	glScalef(3, 4, 3);
	sofa.draw();
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 1.5, 2);
	table.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(4, 0, -4);
	chair.draw();
	glPopMatrix();


	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(-4, 0, -4);
	chair.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, -0.4, -2);
	flower.draw(); 
	glPopMatrix();
}

//灯光位置以及颜色
float position[] = { -5, 4, 0, 1.0 };
float color_write[4] = { 1.0f, 1.0f, 1.0f, 1.0f };


void KeyFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a': RotateLeft(); break;
	case 'd': RotateRight(); break;
	case 'w': MoveForward(); break;
	case 's': MoveBackward(); break;
	case 'q': RotateUp(); break;
	case 'e': RotateDown(); break;
	case 'o': doorRo = !doorRo; break;

	case 'v': first = !first; initPos(); break;
	case 'l': light = !light; break;

	case 'h': position[0] -= 0.2; break;
	case 'k': position[0] += 0.2; break;
	case 'u': position[2] -= 0.2; break;
	case 'j': position[2] += 0.2; break;
	case 'n': position[1] += 0.2; break;
	case 'm': position[1] -= 0.2; break;

	case '1': color_write[0] = 0.5; color_write[1] = 0.5; color_write[2] = 0.4; break;
	case '2': color_write[0] = 1.0; color_write[1] = 0.5; color_write[2] = 0.3; break;
	case '3': color_write[0] = 0.3; color_write[1] = 0.7; color_write[2] = 1.0; break;
	case '4': color_write[0] = 1.0; color_write[1] = 1.0; color_write[2] = 1.0; break;

	}
	glutPostRedisplay();
}

//环境光
void Light0(){ 
	float position[] = { 0, 4, 0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, color_write);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color_write);
	glLightfv(GL_LIGHT0, GL_SPECULAR, color_write);
	glLightfv(GL_LIGHT0, GL_EMISSION, color_write);

/*	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.03f);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0f);*/

	glEnable(GL_LIGHT0);
}

//聚光灯
void Light1(){
	GLfloat lightDir[] = { 0, -1, 0 };
	GLfloat spotangle = 20;
	glLightfv(GL_LIGHT1, GL_AMBIENT, color_write);            
	glLightfv(GL_LIGHT1, GL_SPECULAR, color_write);                    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color_write);

	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotangle);             
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDir);          
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.);                   

	glEnable(GL_LIGHT1);
}


void updateView(int width, int height)
{
	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	float whRatio = (GLfloat)width / (GLfloat)height;

	gluPerspective(45.0f, whRatio, 0.1f, 300.0f);


	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
}

void reshape(int width, int height){
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	wHeight = height;
	wWidth = width;
	updateView(wHeight, wWidth);
}

void idle(){
	glutPostRedisplay();
}

void redraw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	LookAt();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	if (light){
		glDisable(GL_LIGHT1);
		Light0();
	}
	else {
		glDisable(GL_LIGHT0);
		Light1();
	}

	glShadeModel(GL_SMOOTH);

	draw();
	if (doorRo){
		doorRotate += 2.0;
		if (doorRotate > 90)
			doorRotate = 90;
	}
	if (!doorRo){
		doorRotate -= 2.0;
		if (doorRotate < 0)
			doorRotate = 0;
	}
	glutSwapBuffers();
}

void init(){ // 导入bmp以及obj文件
	glGenTextures(1, &floorTex);
	glGenTextures(1, &wallTex);
	glGenTextures(1, &doorTex);
	glGenTextures(1, &frontTex);
	glGenTextures(1, &deskTex);
	//glGenTextures(1, &window);

	texload(floorTex, "Floor.bmp");
	texload(wallTex, "Wall.bmp");
	texload(doorTex, "door.bmp");
	texload(frontTex, "front.bmp");
	texload(deskTex, "desk.bmp");
	//texload(window, "Window.bmp");

	//tv.loadOBJ("OBJ/tv", "contemp_living_room.obj");
	//tv.unitize();
	//tv.setPosition(1.5, -1- tv.getArea().y, -1.8);

	tv.loadOBJ("OBJ/tv", "tv.obj");
	tv.unitize();
	tv.setPosition(2, -0.92 - tv.getArea().y, -2.3);


	ipad.loadOBJ("OBJ/iPad", "iPad.obj");
	ipad.unitize();
	ipad.setPosition(13, - ipad.getArea().y, -8);

	pillow.loadOBJ("OBJ/throwPillow", "pillow.obj");
	pillow.unitize();
	pillow.setPosition(8, -3.5 - sofa.getArea().y, -5.5);

	apple.loadOBJ("OBJ/Apple", "Apple.obj");
	apple.unitize();
	apple.setPosition(7, -6 - apple.getArea().y, 0.3); 

	sofa.loadOBJ("OBJ/largeCouch", "sofa.obj");
	sofa.unitize();
	sofa.setPosition(-2, - 1 -sofa.getArea().y, -2);

	table.loadOBJ("OBJ/table", "table.obj");
	table.unitize();
	table.setPosition(-3,  -4/1.5 - table.getArea().y, -1);

	chair.loadOBJ("OBJ/chair", "chair.obj");
	chair.unitize();
	chair.setPosition(0, -4 - chair.getArea().y, 2);

	flower.loadOBJ("OBJ/flower", "flowers.obj");
	flower.unitize();
	flower.setPosition(0, -2 - flower.getArea().y, 0);

	tvStand.loadOBJ("OBJ/tvStand", "tvStand.obj");
	tvStand.unitize();
	tvStand.setPosition(2, -2 - tvStand.getArea().y, -3.2);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(640, 640);
	int windowHandle = glutCreateWindow("Indoor Environment");

	init();

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(KeyFunc);
	glutMotionFunc(MouseMotion);
	glutMouseFunc(MouseFunc);

	glutMainLoop();
	return 0;
}
