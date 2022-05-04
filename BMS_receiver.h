#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NO_OF_READINGS 50

void GetDataFromConsole(float *Current, float *Temperature);

float Calc_MaxParam_Value(float *BMSParameter);

float Calc_MinParam_Value(float *BMSParameter);

float Calculate_Avg(float *BMSParameter);

void PrintDataOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA);

void Compute_Stat(float *Current, float *Temperature);