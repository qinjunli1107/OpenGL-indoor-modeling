#include "thirdView.h"

#define HEIGHT 0.2
#define SPEED 0.1
static GLfloat center[3] = { 0.0f, 0.0f, 0.0f }; /// center position
static GLfloat eye[3] = { 0, 0, 0 }; /// eye's position

/// when a mouse-key is pressed, record current mouse position 
static GLint mousex = 0, mousey = 0;

const GLfloat PI = 3.14;

/// record the state of mouse
GLboolean mouserdown = GL_FALSE;
GLboolean mouseldown = GL_FALSE;
GLboolean mousemdown = GL_FALSE;

GLfloat yrotate = PI / 4; /// angle between y-axis and look direction
GLfloat xrotate = PI / 4; /// angle between x-axis and look direction
GLfloat celength = 20.0f;/// lenght between center and eye

GLfloat mSpeed = 0.4f; /// center move speed
GLfloat rSpeed = 0.02f; /// rotate speed
GLfloat lSpeed = 0.4f; /// reserved

bool first = false;
GLfloat angle = 0;
GLfloat elev = 0;
GLfloat rad = 0;


void initPos(){
	eye[0] = eye[2] = 0;
	eye[1] = HEIGHT;
	if (first)
		CalEyePostion1();
	else
		CalEyePostion();
}

void CalEyePostion(){
	if (yrotate > PI / 2.2) yrotate = PI / 2.2;   /// 限制看得方向
	if (yrotate < 0.01)  yrotate = 0.01;
	if (xrotate > 2 * PI)   xrotate = 0.01;
	if (xrotate < 0)   xrotate = 2 * PI;
	if (celength > 60)  celength = 60;     ///  缩放距离限制
	if (celength < 3)   celength = 3;
	/// 下面利用球坐标系计算 eye 的位置，
	eye[0] = center[0] + celength * sin(yrotate) * cos(xrotate);
	eye[2] = center[2] + celength * sin(yrotate) * sin(xrotate);
	eye[1] = center[1] + celength * cos(yrotate);
}

/// center moves
void MoveBackward(){              /// center 点沿视线方向水平向后移动
	if (!first){
		center[0] += mSpeed * cos(xrotate);
		center[2] += mSpeed * sin(xrotate);
		CalEyePostion();
	}
	else{
		float z = eye[2] - sin(rad) * SPEED;
		float x = eye[0] - cos(rad) * SPEED;
		if (((x<10) && (x>-10) && (z > -7.5) && (z < 7.5))){
			eye[2] = z;
			eye[0] = x;
			CalEyePostion1();
		}
	}
}

void MoveForward(){
	if (!first){
		center[0] -= mSpeed * cos(xrotate);
		center[2] -= mSpeed * sin(xrotate);
		CalEyePostion();
	}
	else{
		float z = eye[2] + sin(rad) * SPEED;
		float x = eye[0] + cos(rad) * SPEED;
		if (((x<10) && (x>-10) && (z > -7.5) && (z < 7.5))){
			eye[2] = z;
			eye[0] = x;
			CalEyePostion1();
		}
	}
}

/// visual angle rotates
void RotateLeft(){
	if (!first){
		xrotate -= rSpeed;
		CalEyePostion();
	}
	else {
		float z = eye[2] - cos(rad) * SPEED;
		float x = eye[0] + sin(rad) * SPEED;
		if (((x<10) && (x>-10) && (z > -7.5) && (z < 7.5))){
			eye[2] = z;
			eye[0] = x;
			CalEyePostion1();
		}
	}
}

void RotateRight(){
	if (!first){
		xrotate += rSpeed;
		CalEyePostion();
	}
	else {
		float z = eye[2] + cos(rad) * SPEED;
		float x = eye[0] - sin(rad) * SPEED;
		if (((x<10) && (x>-10) && (z > -7.5) && (z < 7.5))){
			eye[2] = z;
			eye[0] = x;
			CalEyePostion1();
		}
	}
}

void RotateUp(){
	yrotate += rSpeed;
	CalEyePostion();
}

void RotateDown(){
	yrotate -= rSpeed;
	CalEyePostion();
}

void CalEyePostion1(){
	eye[1] = HEIGHT;
	center[0] = eye[0] + 1 * cos(rad);
	center[2] = eye[2] + 1 * sin(rad);
	center[1] = eye[1] + elev;
}

void LookAt(){            /// 调用 gluLookAt(), 主要嫌直接调用要每次都写好几个参数。。
	if (!first)
		CalEyePostion();
	else
		CalEyePostion1();
	gluLookAt(eye[0], eye[1], eye[2],
		center[0], center[1], center[2],
		0, 1, 0);
}

void MouseFunc(int button, int state, int x, int y){
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_RIGHT_BUTTON) mouserdown = GL_TRUE;
		if (button == GLUT_LEFT_BUTTON) mouseldown = GL_TRUE;
		if (button == GLUT_MIDDLE_BUTTON)mousemdown = GL_TRUE;
	}
	else
	{
		if (button == GLUT_RIGHT_BUTTON) mouserdown = GL_FALSE;
		if (button == GLUT_LEFT_BUTTON) mouseldown = GL_FALSE;
		if (button == GLUT_MIDDLE_BUTTON)mousemdown = GL_FALSE;
	}
	mousex = x, mousey = y;
}

/// CALLBACK func for mouse motions
void MouseMotion(int x, int y){
	if (!first){
		if (mouserdown == GL_TRUE)
		{       /// 所除以的数字是调整旋转速度的，随便设置，达到自己想要速度即可
			xrotate += (x - mousex) / 80.0f;
			yrotate -= (y - mousey) / 120.0f;
		}

		if (mouseldown == GL_TRUE)
		{
			celength += (y - mousey) / 25.0f;
		}
		mousex = x, mousey = y;
		CalEyePostion();
	}
	else{
		if (mouserdown == GL_TRUE){

			angle += (x - mousex) * 0.2f;
			elev += -(y - mousey) * 0.002f;

			if (elev > 360) elev = 360;
			if (elev < -360) elev = -360;

			rad = (GLfloat)(PI * angle / 180.0);
		}

		mousex = x;
		mousey = y;
	}
	glutPostRedisplay();
}

