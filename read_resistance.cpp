#include<iostream>
//#include<iomanip> //setprecision() 
#include<string>
#include"AnalogIn.h"

using namespace std;

int main() {

	cout << "Using AIN0 to read analog value." << endl;
	cout << "Measuring resistance..." << endl;
	
	AnalogIn ADC(0);

	int ADC_val = ADC.readADCsample();
	cout << "ADC value is: " << ADC_val << endl;
	
	float voltage = ADC_val * (1.80f/4096.0f); // convert bit to voltage
	//cout << "Node voltage is: " << voltage << endl;
	
	float resistance = (10000.0f*voltage)/(1.8f - voltage);
	//cout << "The resitance is: " << resistance << endl;
	
	if (resistance < 1000.0f) {
		cout.precision(3);
		cout << "Resistance: " << resistance << " Ohms" << endl;
	}
	else {
		resistance = resistance/1000.0f;
		cout.precision(4);
		cout << "Resistance: " << resistance << "K Ohms" << endl;
	}
	return 0; 
}


