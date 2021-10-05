#include <stdio.h>
#include "battery_check.h"

#define MAX_BATTERY_VOLTAGE (4.3)
#define MIN_BATTERY_VOLTAGE (2.3)


// REFERENCE : https://www.electronics-notes.com/articles/electronic_components/battery-technology/li-ion-lithium-ion-charging.php#:~:text=Constant%20current%20charge:%20In%20the%20first%20stage%20of,rate%20of%20a%20maximum%20of%200.8C%20is%20recommended.


static STRUCT_BATTERY_MANUFACTURER_LIMITS manufacturer_one;
static STRUCT_BATTERY_MANUFACTURER_LIMITS manufacturer_two;

int battery_check_temperature_ok(int temperature)
{
	int ret_val = 1;
	
	if((temperature < manufacturer_one.batt_temp_limits.min_oper_temperature)  || 
	   (temperature > manufacturer_one.batt_temp_limits.max_oper_temperature)) 
	{
    	printf("Temperature out of range!\n");
    	ret_val =  0;
  	}
  	
  	return ret_val;	
}

int battery_check_state_of_charge_ok(float soc)
{
	int ret_val = 1;
	
	if((soc < manufacturer_one.batt_state_of_charge_limits.min_state_of_charge) || 
	   (soc > manufacturer_one.batt_state_of_charge_limits.max_state_of_charge)) 
	{
    	printf("State of Charge out of range!\n");
    	ret_val =  0;
	}
	
	return ret_val;	
	
}


int battery_check_charge_rate_ok(float chargeRate)
{
	int ret_val = 0;
	
	if((chargeRate > manufacturer_one.batt_charge_rate_limits.min_charge_rate) && 
	   (chargeRate < manufacturer_one.batt_charge_rate_limits.max_charge_rate))
	{    	
		//Valid charge rate 
    	ret_val = 1;
    }
    else
    {
    	printf("Charge Rate out of range!\n");
	}    
	
	return ret_val;		
}

int battery_check_over_charge(float batteryVoltage)
{
	int ret_val = 1; 
	
	if(batteryVoltage > manufacturer_one.batt_voltage_limits.max_charge_voltage)
	{
		printf("Battery over charged!\n");
		ret_val = 0;
	}
	
	return ret_val;	
}

int battery_check_over_discharge(float batteryVoltage)
{
	int ret_val = 1; 
	
	if(batteryVoltage < manufacturer_one.batt_voltage_limits.min_charge_voltage)
	{
		printf("Battery over discharged!\n");
		ret_val = 0;
	}
	
	return ret_val;	
}

void battery_limits_init_manufacturer_one(void)
{
	// Values are assigned based on battery manufacturer recomendation
	// TODO : Remove magic numbers
	manufacturer_one.batt_temp_limits.min_oper_temperature = 0;
	manufacturer_one.batt_temp_limits.max_oper_temperature = 45;
	
	manufacturer_one.batt_state_of_charge_limits.min_state_of_charge = 20;
	manufacturer_one.batt_state_of_charge_limits.max_state_of_charge = 80;	
	
	manufacturer_one.batt_charge_rate_limits.min_charge_rate = 0;
	manufacturer_one.batt_charge_rate_limits.max_charge_rate = 0.8;
	
	manufacturer_one.batt_voltage_limits.min_charge_voltage = 2.3;
	manufacturer_one.batt_voltage_limits.max_charge_voltage = 4.3;
}


