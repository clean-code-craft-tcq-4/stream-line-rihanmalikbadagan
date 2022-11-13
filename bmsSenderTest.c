#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "bmsSender.h"

void TEST_generateBatteryData(void)
{
    int result;
    batteryParameters *batteryParam;

    //batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = generateBatteryData(batteryParam);
    assert(result == SUCCESS);
    free(batteryParam);

    batteryParam = NULL;
    result = generateBatteryData(batteryParam);
    assert(result == FAILURE);
    printf("***************Generate battery data test passed***************");
}

void TEST_writeToCsv(void)
{
    int result;
    batteryParameters *batteryParam;

    //batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = writeToCsv(batteryParam);
    assert(result == SUCCESS);
    free(batteryParam);

    batteryParam = NULL;
    result = writeToCsv(batteryParam);
    assert(result == FAILURE);
    printf("***************write to csv test passed***************");
}

void TEST_senderProcess(void)
{
    int result;
    result = senderProcess();
    assert(result == SUCCESS);
    printf("***************sender process test passed***************");
}

void TEST_SENDER(void)
{
    TEST_generateBatteryData();
    TEST_writeToCsv();
    TEST_senderProcess();

    printf("***************All test cases passed***************");
}