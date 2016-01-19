#ifndef LoadTexture_h
#define LoadTexture_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Gl/glut.h>
#include <Windows.h>

#define BITMAP_ID 0x4D42


unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
//unsigned char *CreateMyBmp(BITMAPINFOHEADER *bitmapInfoHeader);
void texload(GLuint& texture, char *filename);

#endif 
