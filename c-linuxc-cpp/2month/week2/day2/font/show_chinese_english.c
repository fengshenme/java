#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libfont/font.h"



int main(int argc,const char **argv)
{
	// ��ʼ�������
	Init_Font();
	
	// �������
	Clean_Area(100, 100, 64*10, 64, 0xFFFFFF);
	
// int   Display_characterX(unsigned int x,          //x������ʼ��
                         // unsigned int y,          //y������ʼ��
						 // unsigned char *string,   //GB2312 �����ַ���
						 // unsigned int color ,     //������ɫֵ
						 // int size);               //����Ŵ��� 1~8
	
	unsigned char * str = malloc(30);
	//  str = "GZ2039��Һã�����~";
	// unsigned char * str1 = "GZ2039��Һã�����~";

	// ��ʾ��Ӣ�ģ�1�����壺16*16��
	Display_characterX(100, 100, "GZ2039��Һã�����~", 0xFF0000, 4);	// 64*64
	free(str);
	// �ر������
	UnInit_Font();
}



