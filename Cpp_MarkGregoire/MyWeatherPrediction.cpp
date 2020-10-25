#include "MyWeatherPrediction.h"
using namespace std;
void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
	setCurrentTempFahrenheit(convertCelsiusToFahrenheit(temp));
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	return convertFahrenheitToCelsius(getTomorrowTempFahrenheit());

}

void MyWeatherPrediction::showResult() const
{
	cout << "~~~~" << endl;
}
