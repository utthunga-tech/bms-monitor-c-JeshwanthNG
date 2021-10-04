#include <stdio.h>

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
    	return 0;
	}
	
	return ret_val;	
	
}


int battery_check_charge_rate_ok(float chargeRate)
{
	int ret_val = 1;
	
	if(chargeRate > 0.8) 
	{
    	printf("Charge Rate out of range!\n");
    	return 0;
    }
	
	return ret_val;		
}


