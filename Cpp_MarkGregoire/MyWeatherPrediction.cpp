#include "MyWeatherPrediction.h"

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
	setCurrentTempFahrenheit(convertCelsiusToFahrenheit(temp));
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	return convertFahrenheitToCelsius(getTomorrowTempFahrenheit());

}
