#pragma once
#include "WeatherPrediction.h"

class MyWeatherPrediction :public WeatherPrediction {
public:
	virtual void setCurrentTempCelsius(int temp);
	virtual int getTomorrowTempCelsius() const;
private:
	static int convertCelsiusToFahrenheit(int celsius);
	static int convertFahrenheitToCelsius(int fahrenheit);
};