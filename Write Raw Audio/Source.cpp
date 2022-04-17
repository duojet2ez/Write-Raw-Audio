#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

#define PI 3.14159265358979323846
const int sampleRate = 44100;
const int bitDepth = 16;

class NoiseMaker
{
public:
	int x = 0; 
	float offset = 0.f;		
	float offsetAmount = 0.0f; 
	NoiseMaker(float frequency, float amplitude) : frequency(frequency), amplitude(amplitude) 
	{
		offsetAmount = 2 * PI * frequency / sampleRate;
	}
	float YCoordinates()
	{ 
		float yCoordinate = amplitude * sin(offset);     //need to offset this value each time function called by 2 * PI * frequency / sampleRate
		offset += offsetAmount; 
		return yCoordinate; 
	}
private:
	float frequency;
	float amplitude; 
};


int main()
{
	int duration = 2;
	NoiseMaker noiseMaker(440, .5); 
	ofstream audioOutput; 
	audioOutput.open("wav", ios::binary); 
	auto maxAmplitude = pow(2, bitDepth - 1) - 1; 
	for (int i = 0; i < sampleRate * duration; i++)
	{
		float yValue = noiseMaker.YCoordinates(); 
		int intYValue = static_cast<int>(yValue * maxAmplitude); 
		audioOutput.write(reinterpret_cast<char*> (&intYValue), 2); 
	}
	audioOutput.close(); 
	return 0; 
}