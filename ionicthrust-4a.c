// Coding by eMonolith
// https://github.com/eMonolith
// Parametric solution of Thrust, ISP, Exhuast Velocity, and Power Output of Gridded Ion Thrusters.

//TODO: input validation and error handling

#include<stdio.h>
#include<math.h>

int main(void)
{
 double current = 0.0;
 double voltage = 0.0;
 double mass = 0.0;
 double velocity = 0.0;
 double momentum = 0.0;
 double time = 0.0;
 double charge = 0.0;
 const double Ce = 1.60217656535E-19;
 const double q = 4.806E-19f;  // assumed one mole of nitrogen atmosphere 
 double exhaust_mass = 0.0;

printf("Enter the ionizing current     : ");
scanf("%lf", &current);
printf("Enter the accelerating voltage : ");
scanf("%lf", &voltage);
printf("\n Hydrogen : 1.673823e-27Kg\n Helium : 6.646476e-27Kg\n Nitrogen : 23.259170e-27Kg\n Oxygen : 26.566964e-27Kg\n Argon : 66.335214e-27Kg\n Krypton : 139.448749e-27Kg\n Xenon : 218.017155e-27Kg\n\n");
printf("Enter atomic mass of gas in Kg : ");
scanf("%lf", &mass);

velocity=sqrt((2*voltage*Ce)/mass);
printf("\nExhuast velocity is : %.6e m/sec\n", velocity);

printf("Power Output : %.6e W\n", voltage*current);

printf("Enter time :");
scanf("%lf", &time);
charge=current*time;

printf("Electrostatic thrust is : %.6e N\n", current*sqrt((2.0*voltage*mass)/Ce));

printf("Specific Impulse is : %.6e Isp sec\n", (1.0/9.8) * sqrt(2.0 * (q/mass) * voltage));  //The Starflight Handbook, Mallove & Matloff (1.0/9.8) * sqrt(2 * (charge/mass) * voltage)
//printf("Specific Impulse is : %.6e Isp\n", (2 * q * voltage) / mass * sqrt(2 * q * voltage / (mass * velocity)));  // ISP=(2 * q * voltage) / mass * sqrt(2 * q * voltage / (mass * velocity))

printf("Specific Impulse is : %.6e m/sec\n", velocity/9.8);  //nasa https://www.grc.nasa.gov/WWW/k-12/airplane/specimp.html

//double mass_flow_rate = current * (Ce / (mass * charge)); // mass flow rate in kg/s
//printf("Specific Impulse is : %.6e sec\n", current*sqrt((2*voltage*Ce)/mass) / (mass_flow_rate * 9.81));


printf("Conversions: newton to gram force : %.6e g\n", current*sqrt((2*voltage*mass)/Ce) * 101.97162);
printf("Conversions: newton to pound force : %.6e lbf\n", current*sqrt((2*voltage*mass)/Ce) * 0.22480894);
printf("Conversions: m/sec to Mach : %.6e Mach\n", velocity/343.00022295);

return 0;
}

/*Isp = sqrt(2 * q * V / m * g)

where:

    Isp is the specific impulse in seconds
    q is the charge of the ion in Coulombs
    V is the voltage of the thruster in volts
    m is the mass of the ion in kilograms
    g is the acceleration due to gravity (9.81 m/s^2)
*/
