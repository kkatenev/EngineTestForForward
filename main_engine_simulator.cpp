#include "engines.h"
#include "Test.h"

#include <iostream>
#include <vector>

using namespace std;

double Engine::Vh()
{
	return M * Hm + V * V * Hv;
}


double Engine::Vc(double ambient_temperature, double engine_temperature)
{
	return C * (ambient_temperature - engine_temperature);
}


int main()
{
	
	double ambient_temperature;
	struct Engine engine;
	cout << "Enter ambient temperature" << endl;
	cin >> ambient_temperature;
	cout << "Overheating time " << test_overheat(ambient_temperature) << " sec" << endl;
	return 0;
}