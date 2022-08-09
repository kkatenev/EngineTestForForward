#include "engines.h"
#include "Test.h"

#include <iostream>

#define MAX_EPS 0.00001
#define MAX_TIME 2000

double test_overheat(double ambient_temperature)
{
	struct Engine engine;
	

	double eps = engine.T - ambient_temperature;
	int current = 0;
	double time = 0;
	double engine_temperature = ambient_temperature;
	engine.M = engine.vectorM[current];
	engine.V = engine.vectorV[current];

	double a = engine.M / engine.I;
	double delta_current_V = 0;
	double delta_next_V = 0;
	double delta_next_M = 0;

	while (eps > MAX_EPS && time < MAX_TIME)
	{
		time++;
		engine.V += a; //start engine

		if (engine_temperature < engine.T)
		{
			if (current < engine.vectorM.size()-2)
			{
				if (engine.V < engine.vectorV[current + 1])
				{
					current += 0;
				}
				else
					current += 1;
			}
			delta_current_V = (engine.V - engine.vectorV[current]);
			delta_next_V = (engine.vectorV[current + 1] - engine.vectorV[current]);
			delta_next_M = (engine.vectorM[current + 1] - engine.vectorM[current]);

			engine.M = delta_current_V / delta_next_V * delta_next_M + engine.vectorM[current];
			engine_temperature += engine.Vh() + engine.Vc(ambient_temperature, engine_temperature);
			eps = engine.T - engine_temperature;
			a = engine.M / engine.I;
		}
	}
	return time;
}