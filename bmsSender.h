#define NUM_OF_READINGS		50
#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80
#define CSV_FILE "BMSData.csv"

typedef struct{
   int index;
   float temperature[NUM_OF_READINGS];
   float soc[NUM_OF_READINGS];
}batteryParameters;

typedef enum{
	FAILURE,
   SUCCESS
}status_en;

status_en generateBatteryData(batteryParameters *ptr_BatteryParam);
status_en writeToCsv(batteryParameters *ptr_BatteryParam);
status_en createCsvFile(void);
int senderProcess(void);

void TEST_SENDER(void);
void TEST_senderProcess(void);
void TEST_writeToCsv(void);
void TEST_generateBatteryData(void);
