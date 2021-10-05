#ifndef BATTERY_CHECK_H
#define BATTERY_CHECk_H

int battery_check_temperature_ok(int temperature);
int battery_check_state_of_charge_ok(float soc);
int battery_check_charge_rate_ok(float chargeRate);
int battery_check_over_charge(float batteryVoltage);



#endif