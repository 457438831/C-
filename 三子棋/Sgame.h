		
#pragma once //�����ظ�����
#define ROW 3
#define COL 3
#define _CRT_SECURE_NO_WARNINGS 1

//  ����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>


//  ���庯��
void chushihua(char arr[ROW][COL], int row, int col);
void xianshi(char arr[ROW][COL],int row,int col);
void move(char arr[ROW][COL]);
void computermove(char arr[ROW][COL],int row,int col);
int panduan(char arr[ROW][COL],int row ,int col);