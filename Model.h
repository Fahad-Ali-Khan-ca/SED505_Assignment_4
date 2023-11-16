// Model.h created by Fahad Ali Khan
// defines the base model
#define _MODEL_H
#ifdef _MODEL_H
#ifdef TEST_BUILD
#define _USE_MATH_DEFINES
#include <cmath>
#endif
#include "BaseModel.h"
//#define TEST_BUILD
class Model : public BaseModel
{
public:
	int train();
	int ErrorAnalysis();
	double predict(double input);
	double factorial(int n);
private:
	vector<double> weights;
	const double freq = 50.0;
	const int steps = 360;
	const double PI = 3.141592653589793238;
};
#endif // _MODEL_H
