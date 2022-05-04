#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_receiver.h"

TEST_CASE("Test to check Data Receiver statistics") 
{ 
   float Current_loc, Temperature_loc;
   float Current[NO_OF_READINGS], Temperature[NO_OF_READINGS] = {0};
   float ExpectedCurrent[NO_OF_READINGS], ExpectedTemperature[NO_OF_READINGS] = {0};
   
   Compute_Stat(Current, Temperature);
    
   FILE * file = fopen("./DataFromConsole.txt","r");                                                                  
   for(int i = 0; i<NO_OF_READINGS; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0; fscanf(file, "%f,%f\n", &Current_loc,&Temperature_loc)!=EOF; i++)
        {
            ExpectedCurrent[i] = Current_loc;
            ExpectedTemperature[i] = Temperature_loc;
        }
     }
       
     REQUIRE((Current[i] - ExpectedCurrent[i]) <= 0.001);
     REQUIRE((Temperature[i] - ExpectedTemperature[i]) <= 0.001);
   }

   fclose(file);
 
   float MinCurrent     = Calc_MinParam_Value(Current);
   float MaxCurrent     = Calc_MaxParam_Value(Current);
   float SMACurrent     = Calculate_Avg(Current);
   float MinTemperature = Calc_MinParam_Value(Temperature);
   float MaxTemperature = Calc_MaxParam_Value(Temperature);
   float SMATemperature = Calculate_Avg(Temperature);
   
   REQUIRE(abs(MinCurrent - (-13.774300) ) <=0.001);
   REQUIRE(abs(MaxCurrent - 14.962000 ) <=0.001);
   REQUIRE(abs(SMACurrent - 1.511800 ) <=0.001);
   REQUIRE(abs(MinTemperature - 0.216200 ) <=0.001);
   REQUIRE(abs(MaxTemperature - 43.833599 ) <=0.001);
   REQUIRE(abs(SMATemperature - 23.042278 ) <=0.001);
}