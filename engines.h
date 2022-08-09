#include <vector>
using namespace std;
struct Engine
{
	double I = 10, T = 110, Hm = 0.01, Hv = 0.0001, C = 0.1, M, V;
	vector<int> vectorM = { 20, 75, 100, 105, 75, 0 };
	vector<int> vectorV = { 0, 75, 150, 200, 250, 300 }; 

	double Vc(double ambient_temperature, double engine_temperature);
	double Vh();
};