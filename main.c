#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "battery_check.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	
	//TODO : Delete below commented functions later
	//assert(batteryIsOk(25, 70, 0.7)));
	//assert(!batteryIsOk(50, 85, 0)));
	
	//Check condition 1
	assert(battery_check_temperature_ok(25));
	assert(battery_check_state_of_charge_ok(70));
	assert(battery_check_charge_rate_ok(0.7));
	
	//Check condition 2
	assert(!battery_check_temperature_ok(50));
	assert(!battery_check_state_of_charge_ok(85));
	assert(!battery_check_charge_rate_ok(0));
	
	
  	
	return 0;
}