//============================================================================
// Name        : Project0.cpp
// Author      : Kunal Chandan
// Version     : 1.0
// Description : Project 0
//============================================================================

#include <cmath>
#include <iostream>

#define PI 3.1415936537

#ifndef MARMOSET_TESTING
int main();
#endif
double horizontal_velocity(double launch_velocity, double launch_angle);
double vertical_velocity(double launch_velocity, double launch_angle);
double gravity();
double computed_range(double launch_velocity, double launch_angle, double height);
double deg2rad(double launch_angle);

double deg2rad(double launch_angle){
	return PI*(launch_angle/180);
}
double horizontal_velocity(double launch_velocity, double launch_angle){
	if(launch_angle == 90){
		return 0;
	}
	return launch_velocity*cos(deg2rad(launch_angle));
}
double vertical_velocity(double launch_velocity, double launch_angle){
	return launch_velocity*sin(deg2rad(launch_angle));
}
double gravity(){
	return 9.80665;
}
double computed_range(double launch_velocity, double launch_angle, double height){
	double vx = horizontal_velocity(launch_velocity, launch_angle);
	double vy = vertical_velocity(launch_velocity, launch_angle);
	double g = gravity();
	double h = height;
	return ((vx/g)*(vy+sqrt(vy*vy+2*g*h)));
}

#ifndef MARMOSET_TESTING
int main() {
	double vi = 600.0;
	double height = 10;
	double angles[] = {10, 20, 25.5, 30, 40, 50, 55.5, 60, 70, 75.5, 80, 90};
	int len = sizeof(angles)/sizeof(angles[0]);
	double max_distance = 0;
	double angle_max = 0;
	for(int x = 0; x < len; x ++){
		std::cout << "The range the banana reaches for the launch angle of "
				  << angles[x]
				  << " degrees is "
				  << computed_range(vi, angles[x], height)
				  << std::endl;
		/*
		if(computed_range(vi, angles[x]*PI/180, 0) > max_distance){
			max_distance = computed_range(vi, angles[x], 0);
			angle_max = angles[x];
		}*/
	}
	//std::cout << max_distance << std::endl;
	return 0;
}
#endif
