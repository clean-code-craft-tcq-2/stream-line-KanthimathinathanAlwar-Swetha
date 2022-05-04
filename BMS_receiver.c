#include "BMS_receiver.h"

void GetDataFromConsole(float* Current, float* Temperature)
{
    FILE* fp = fopen("./DataFromConsole.txt","r");
    float Curr_readings, Temp_readings;
  
    for(int i = 0; fscanf(fp, "%f,%f \n", &Curr_readings,&Temp_readings)!=EOF; i++)
    {
        *(Current + i)     = Curr_readings;
        *(Temperature + i) = Temp_readings;
    }

    fclose(fp);
}

float Calc_MaxParam_Value(float *BMSParameter)
{
    float MaxReadVal = BMSParameter[0];
  
    for(int i = 0; i < NO_OF_READINGS; i++)
    {
        if(BMSParameter[i] > MaxReadVal)
        {
            MaxReadVal = BMSParameter[i];
        }
    }

    return MaxReadVal;
}

float Calc_MinParam_Value(float *BMSParameter)
{
    float MinReadVal = BMSParameter[0];
  
    for(int i = 0; i < NO_OF_READINGS; i++)
    {
        if(BMSParameter[i] < MinReadVal)
        {
            MinReadVal = BMSParameter[i];
        }
    }
   
    return MinReadVal;
}

float Calculate_Avg(float *BMSParameter)
{
    float Average = 0.0;
    float Sum = 0.0;
    
    for(int i = (NO_OF_READINGS-5); i < NO_OF_READINGS; i++)
    {
        Sum += BMSParameter[i];
    }

    Average = Sum/5;
    return Average;
}

void PrintDataOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA)
{
    printf("Data received from sender\n");
  
    for(int i = 0; i < NO_OF_READINGS; i++)
    {
        printf("%f\n",BMSParameter[i]);
    }

    printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,Minvalue,SMA);
}

void Compute_Stat(float *Current, float *Temperature)
{
    GetDataFromConsole(Current,Temperature);

    PrintDataOnConsole(Current,Calc_MaxParam_Value(Current),Calc_MinParam_Value(Current),Calculate_Avg(Current));

    PrintDataOnConsole(Temperature,Calc_MaxParam_Value(Temperature),Calc_MinParam_Value(Temperature),Calculate_Avg(Temperature));
}