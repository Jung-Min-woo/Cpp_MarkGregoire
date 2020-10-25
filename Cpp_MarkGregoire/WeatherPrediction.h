#pragma once
#include <iostream>
#include <string>
//Object : F 2 C / showResult Err
class WeatherPrediction {
public:
	virtual ~WeatherPrediction();
	virtual void setCurrentTempFahrenheit(int temp);
	virtual void setPositionOfJupiter(int distanceFromMars);
	virtual int getTomorrowTempFahrenheit() const;
	virtual double getChanceOfRain() const;
	virtual void showResult() const;
	virtual std::string getTemperature() const;
private:
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};