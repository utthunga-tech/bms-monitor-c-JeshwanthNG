#include <stdio.h>

#define MAX_BATTERY_VOLTAGE (4.3)


// REFERENCE : https://www.electronics-notes.com/articles/electronic_components/battery-technology/li-ion-lithium-ion-charging.php#:~:text=Constant%20current%20charge:%20In%20the%20first%20stage%20of,rate%20of%20a%20maximum%20of%200.8C%20is%20recommended.

int battery_check_temperature_ok(int temperature)
{
	int ret_val = 1;
	
	if(temperature < 0 || temperature > 45) 
	{
    	printf("Temperature out of range!\n");
    	ret_val =  0;
  	}
  	
  	return ret_val;	
}

int battery_check_state_of_charge_ok(float soc)
{
	int ret_val = 1;
	
	if(soc < 20 || soc > 80) 
	{
    	printf("State of Charge out of range!\n");
    	ret_val =  0;
	}
	
	return ret_val;	
	
}


int battery_check_charge_rate_ok(float chargeRate)
{
	int ret_val = 0;
	
	if(chargeRate > 0 && chargeRate < 0.8) 
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
	
	if(batteryVoltage > MAX_BATTERY_VOLTAGE)
	{
		printf("Battery over charged, turn off!\n");
		ret_val = 0;
	}
	
}


