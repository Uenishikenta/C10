#pragma once

#include <windows.h>
#include <thread>
#include <mutex>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#define BUFFSIZE 1024

//構造体宣言(A,B,Cさん)
typedef struct Player {
	int idou_time;	//片道時間
};

//グローバル変数宣言

int A_Number;
int B_Number;
int C_Number;

int A_rank = 1;
int B_rank = 1;
int C_rank = 1;

int A_result = 0;
int B_result = 0;
int C_result = 0;

int A_idou_time = 0;
int A_have = 0;

int B_idou_time = 0;
int B_have = 0;

int C_idou_time = 0;
int C_have = 0;

int A_sum = 0;
int B_sum = 0;
int C_sum = 0;