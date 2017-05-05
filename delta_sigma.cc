#include <iostream>
#include <cmath>
#include <utility>

using namespace std;


float signal(int t)
{
	//Roughly 0-1
	return (1 + sin(t/20. - 1))/2.1;
}

float quantize(float f, int levels)
{
	return min(levels-1.f, max(0.f, floor(f*levels)))/(levels-1);
}

int main()
{
	
	float integral = 0;

	for(int i=0; i < 200; i++)
	{
		//Since it's a 3 level converter
		//Quantize in the range 0,1,2
		
		
		float output = quantize(integral, 3);
		float difference = signal(i) - output;
		integral += difference;

		cout << signal(i) << " " << output << endl;
	}
	
	



}
