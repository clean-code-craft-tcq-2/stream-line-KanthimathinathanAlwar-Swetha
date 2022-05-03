#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetDataFromConsole(char BMS_DATA[50][50]);

void GetSocData(char BMS_DATA[50][20], int data[50], int size);

void GetTempData(char BMS_DATA[50][20], int tempData[50], int size);

int Calculate_Min(int arr[50], int size);

int Calculate_Max(int arr[50], int size);

float Calculate_Average(int arr[50], int start, int end);

void PrintOnConsole(data_array,data,tempData);