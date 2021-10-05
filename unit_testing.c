#include <assert.h>
#include "battery_check.h"

static void TEST_battery_check_temperature_ok(void)
{
	assert(battery_check_temperature_ok(25));
	assert(!battery_check_temperature_ok(50));
}


static void TEST_battery_check_state_of_charge_ok(void)
{
	assert(battery_check_state_of_charge_ok(70));
	assert(!battery_check_state_of_charge_ok(85));
}


static void TEST_battery_check_charge_rate_ok(void)
{
	//assert(battery_check_charge_rate_ok(0.7));
	assert(!battery_check_charge_rate_ok(0));
	assert(!battery_check_charge_rate_ok(1));
}

static void TEST_battery_check_over_charge(void)
{
	assert(!battery_check_over_charge(5));
}

static void TEST_battery_check_over_discharge(void)
{
	assert(!battery_check_over_discharge(2.0));	
}


void run_unit_tests(void)
{
	TEST_battery_check_temperature_ok();
	TEST_battery_check_state_of_charge_ok();
	TEST_battery_check_charge_rate_ok();
	TEST_battery_check_over_charge();
	TEST_battery_check_over_discharge();
}