#include "SimpleMC.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	double Expiry, Strike, Spot, Vol, r;
	unsigned long NumberOfPaths;
	cout << "Enter expiry: ";
	cin >> Expiry;
	cout << "Enter strike: ";
	cin >> Strike;
	cout << "Enter spot: ";
	cin >> Spot;
	cout << "Enter vol: ";
	cin >> Vol;
	cout << "r: ";
	cin >> r;
	cout << "Number of paths: ";
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, PayOff::call);
	PayOff putPayOff(Strike, PayOff::put);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot,
		Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot,
		Vol, r, NumberOfPaths);
	cout << "Call Price: " << resultCall << endl;
	cout << "Put Price: " << resultPut << endl << endl;
	
	cout << "We check using simple put-call parity: c + Ke^(-rt) = p + S" << endl;
	//cout << "Right handside of the equation is " << resultCall + Strike * exp(-r * Expiry) << endl;
	//cout << "Left handside of the equation is " << resultPut + Spot << endl;
	cout << "The absolute gap is " << abs(resultCall + Strike * exp(-r * Expiry) - (resultPut + Spot)) << endl;

	double tmp;
	cin >> tmp;
	return 0;
}