#ifndef thirdView_h
#define thirdView_h
#include <cmath>
#include <iostream>
#include <GL/glut.h>

using namespace std;

//初始化eye
void initPos();
//计算center中心
void CalEyePostion();
void CalEyePostion1();

void MoveBackward();      //退后
void MoveForward();       //前进
void RotateLeft();        //左转
void RotateRight();       //右转
void RotateUp();          //向上
void RotateDown();        //向下
void LookAt();
void MouseMotion(int x, int y);
void MouseFunc(int button, int state, int x, int y);

#endif
