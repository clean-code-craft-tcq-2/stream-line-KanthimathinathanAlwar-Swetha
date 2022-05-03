#include "BMS_receiver.h"

void GetDataFromConsole(char BMS_DATA[50][50])
{
    char Data[50];
    char *parsedata;

    parsedata = gets(Data);

    for(i = 0; parsedata != NULL; i++)
    {
        strcpy(BMS_DATA[i], Data);
        parsedata = gets(Data);
    }
}

void PrintOnConsole()
{
    printf("Minimum Soc: %d\n", Calculate_Min(data, 50));
    printf("Maximum Soc: %d\n", Calculate_Max(data, 50));
    printf("Simple moving Average: %f\n", calculate_Average(data, 45, 50));

    printf("Minimum Temperature: %d\n", Calculate_Min(tempData, 50));
    printf("Maximum Temperature: %d\n", Calculate_Max(tempData, 50));
    printf("Simple moving Average: %f\n", calculate_Average(tempData, 45, 50));
}

void GetSocData(char BMS_DATA[50][50], int data[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *datastr = strtok(BMS_DATA[i], ",");
        char *DataValue = strtok(datastr, " ");
        int DataVal = atoi(strtok(NULL, " "));
        data[i] = DataVal;
    }
}

void GetTempData(char BMS_DATA[50][50], int tempData[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *tempDataStr = strtok(BMS_DATA[i], ",");
        char *tempDataValue = strtok(NULL, " ");
        int tempDataVal = atoi(strtok(NULL, " "));
        tempData[i] = tempDataVal;
    }
}

int Calculate_Min(int arr[50], int size)
{
    int minValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }
    return minValue;
}

int Calculate_Max(int arr[50], int size)
{
    int maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

float calculate_Average(int arr[50], int start, int end)
{
    float sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += (float)arr[i];
    }
    return (float)(sum / 5.0);
}

int Compute_Stat()
{
    char BMS_DATA[50][50];
    char data_array[50][50];

    GetDataFromConsole(BMS_DATA);

    int data[50];
    int size = sizeof(char) * 50 * 50;
    memcpy(data_array, BMS_DATA, size);
    GetSocData(data_array, data, 50);

    int tempData[50];
    memcpy(data_array, BMS_DATA, size);
    GetTempData(data_array, tempData, 50);

    PrintOnConsole();
}