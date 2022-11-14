#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "bmsSender.h"

/**
 * @brief 
 * 
 */
void TEST_generateBatteryData(void)
{
    int result;
    batteryParameters *batteryParam;

    batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = generateBatteryData(batteryParam);
    assert(result == SUCCESS);
    free(batteryParam);

    printf("***************Generate battery data test passed***************\n");
}

/**
 * @brief 
 * 
 */
void TEST_writeToCsv(void)
{
    int result;
    batteryParameters *batteryParam;

    batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = writeToCsv(batteryParam);
    assert(result == SUCCESS);
    free(batteryParam);

    printf("***************write to csv test passed***************\n");
}

/**
 * @brief 
 * 
 */
void TEST_senderProcess(void)
{
    int result;
    result = senderProcess();
    assert(result == SUCCESS);

    printf("***************sender process test passed***************\n");
}

/**
 * @brief 
 * 
 */
void TEST_SENDER(void)
{
    TEST_generateBatteryData();
    TEST_writeToCsv();
    TEST_senderProcess();

    printf("***************All test cases passed***************\n");
}