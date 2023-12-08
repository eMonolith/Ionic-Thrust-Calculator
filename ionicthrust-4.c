// Coding by eMonolith
// https://github.com/eMonolith

#include<stdio.h>
#include<math.h>

int main(void)
{
 double current = 0;
 double voltage = 0;
 double mass = 0;
 double velocity = 0;
 double time = 0;
 double charge = 0;
 const double Ce = 1.60217656535E-19f;

printf("Enter the ionizing current     : ");
scanf("%lg", &current);
printf("Enter the accelerating voltage : ");
scanf("%lg", &voltage);

printf("Enter atomic mass of gas in Kg : ");
scanf("%lg", &mass);

velocity=sqrt((2*voltage*Ce)/mass);
printf("\nExhuast velocity is : %.6e m/sec\n", velocity);

printf("Power Output : %.6e W\n", voltage*current);

printf("Enter time :");
scanf("%lg", &time);
charge=current*time;

printf("Specific Impulse is : %.6e Isp\n", 1/9.8 * sqrt(2 * (charge/mass)) * voltage);
//printf("Specific Impulse is : %.6e Isp\n", 1/9.8 * sqrt(2 * (charge/mass)) * voltage);

printf("Electrostatic thrust is : %.6e N\n", current*sqrt((2*voltage*Ce)/mass));

printf("Conversions: newton to gram force : %.6e g\n", current*sqrt((2*voltage*Ce)/mass) * 101.97162);
printf("Conversions: newton to pound force : %.6e lbf\n", current*sqrt((2*voltage*Ce)/mass) * 0.22480894);
return 0;
}

