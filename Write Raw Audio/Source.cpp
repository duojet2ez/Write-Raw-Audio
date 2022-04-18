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
	int Silence()
	{
		return 0; 
	}
private:
	float frequency;
	float amplitude; 
};


int main()
{
	ofstream audioFile; 
	int duration = 2;
	
	NoiseMaker noiseMaker(440, .5);              //a 440
	NoiseMaker noiseMakerE(659.25, .5);        //E
	NoiseMaker noiseMakerFSharp(739.99, .5);   //f#
	NoiseMaker noiseMakerD(587.33, .5);     //D
	NoiseMaker noiseMakerCSharp(554.37, .5);   //C# 
	NoiseMaker noiseMakerB(493.88, .5);           //B 

	audioFile.open("wav", ios::binary);
	auto maxAmplitude = pow(2, bitDepth - 1) - 1;
	
	//plays a 440 
	for (int i = 0; i < sampleRate/2; i++)
	{
		float yValue = noiseMaker.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate/2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays a 440 
	for (int i = 0; i < sampleRate/2; i++)
	{
		float yValue = noiseMaker.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays E
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerE.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays E
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerE.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays F#
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerFSharp.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays F#
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerFSharp.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays E
	for (int i = 0; i < sampleRate * 2; i++)
	{
		float yValue = noiseMakerE.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//plays D
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerD.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays D
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerD.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays c#
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerCSharp.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}

	//plays c#
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerCSharp.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}

	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}
	//plays B
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerB.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}
	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}
	//plays B
	for (int i = 0; i < sampleRate / 2; i++)
	{
		float yValue = noiseMakerB.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}
	//1 second of silence
	for (int i = 0; i < sampleRate / 2; i++)
	{
		int silence = noiseMaker.Silence();
		audioFile.write(reinterpret_cast<char*> (&silence), 2);
	}
	//plays a 440 
	for (int i = 0; i < sampleRate * 2; i++)
	{
		float yValue = noiseMaker.YCoordinates();
		int intYValue = static_cast<int>(yValue * maxAmplitude);
		audioFile.write(reinterpret_cast<char*> (&intYValue), 2);
	}
 
	audioFile.close();


	return 0; 
}
