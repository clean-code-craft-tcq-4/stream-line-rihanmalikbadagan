#include <stdio.h>
#include <stdlib.h>
#include "bmsSender.h"
/**
 * @brief 
 * 
 * @param ptr_BatteryParam 
 * @return status_en 
 */
status_en generateBatteryData(batteryParameters *ptr_BatteryParam)
{
    if (ptr_BatteryParam != NULL)
    {
        int index =  ptr_BatteryParam->index;
        //generate data for Battery parameters
        ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
        ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
        return SUCCESS;
    }
    return FAILURE;
}
/**
 * @brief 
 * 
 * @param ptr_BatteryParam 
 * @return status_en 
 */
status_en writeToCsv(batteryParameters *ptr_BatteryParam)
{
    FILE *fd = fopen(CSV_FILE, "a");
    int index =  ptr_BatteryParam->index;

    if(fd == NULL) 
        return FAILURE;

    if (ptr_BatteryParam != NULL)
    {
        printf("%d - Temperature: %f, SOC: %f\n", index, ptr_BatteryParam->temperature[index], ptr_BatteryParam->soc[index]);
        fprintf(fd,"%d,%f,%f\n", index, ptr_BatteryParam->temperature[index], ptr_BatteryParam->soc[index]);
        fclose(fd);
        return SUCCESS;
    }
    return FAILURE;
}
/**
 * @brief Create a Csv File object
 * 
 * @return status_en 
 */
status_en createCsvFile(void)
{
    FILE *fd = fopen(CSV_FILE, "w");
    if(fd == NULL) 
        return FAILURE;

    fclose(fd);
    return SUCCESS;
}
/**
 * @brief 
 * 
 * @return int 
 */
int senderProcess(void)
{
    printf("Inside sender process\n");
	batteryParameters *batteryParam;
    batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    int result = SUCCESS;
    result &= createCsvFile();

    for (batteryParam->index = 1; batteryParam->index <= NUM_OF_READINGS; batteryParam->index++)
    {
        //Generate data for Battery parameters and print to console
        result &= generateBatteryData(batteryParam);
        result &= writeToCsv(batteryParam);
    }

    free(batteryParam);
	return result;
}
