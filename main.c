#include <stdio.h>
#include <stdlib.h>
#include "unit_testing.h"
#include "battery_check.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	battery_limits_init_manufacturer_one();
	run_unit_tests();
		
	
  	
	return 0;
}