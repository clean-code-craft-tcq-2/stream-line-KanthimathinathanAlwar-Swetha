#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetDataFromConsole(char BMS_DATA[50][50]);

void GetSocData(char BMS_DATA[50][50], int data[50], int size);

void collectTempData(char BMS_DATA[50][50], int tempData[50], int size);

int getMinArrayValue(int arr[50], int size);

int getMaxArrayValue(int arr[50], int size);

float calculate_Average(int arr[50], int start, int end);

void PrintOnConsole();