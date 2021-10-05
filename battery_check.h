#ifndef BATTERY_CHECK_H
#define BATTERY_CHECk_H

typedef struct STRUCT_BATTERY_TEMPERATURE_LIMTS
{
	int min_oper_temperature;
	int max_oper_temperature;
	
}STRUCT_BATTERY_TEMPERATURE_LIMTS;

typedef struct STRUCT_BATTERY_STATE_OF_CHARGE_LIMTS
{
	float min_state_of_charge;
	float max_state_of_charge;
	
}STRUCT_BATTERY_STATE_OF_CHARGE_LIMTS;

typedef struct STRUCT_BATTERY_CHARGE_RATE_LIMTS
{
	float min_charge_rate;
	float max_charge_rate;
	
}STRUCT_BATTERY_CHARGE_RATE_LIMTS;

typedef struct STRUCT_BATTERY_VOLATGE_LIMITS
{
	float min_charge_voltage;
	float max_charge_voltage;
	
}STRUCT_BATTERY_VOLATGE_LIMITS;


typedef struct STRUCT_BATTERY_MANUFACTURER_LIMITS
{
	STRUCT_BATTERY_TEMPERATURE_LIMTS  batt_temp_limits;
	STRUCT_BATTERY_STATE_OF_CHARGE_LIMTS batt_state_of_charge_limits;
	STRUCT_BATTERY_CHARGE_RATE_LIMTS batt_charge_rate_limits;
	STRUCT_BATTERY_VOLATGE_LIMITS batt_voltage_limits;
	
}STRUCT_BATTERY_MANUFACTURER_LIMITS;


 
int battery_check_temperature_ok(int temperature);
int battery_check_state_of_charge_ok(float soc);
int battery_check_charge_rate_ok(float chargeRate);
int battery_check_over_charge(float batteryVoltage);
int battery_check_over_discharge(float batteryVoltage);
void battery_limits_init_manufacturer_one(void);



#endif