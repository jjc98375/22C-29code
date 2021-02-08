/*
	Name: Joshua Cho
	Project: Lab4
	IDE: Visual Studio 2019
	OS: Windows
	Description:
		This code mainly built to decipher the secret message from one binary file, which
		all contained as integer value.
*/

#include "Thing.h"
#include "Circular.h"
#include "ColoredCube.h"
#include "ColoredCylinder.h"
#include "ColoredRectangularPrism.h"
#include "ColoredSphere.h"
#include "ColoredThing.h"
#include "Cube.h"
#include "Cylinder.h"
#include "GeometricSolid.h"
#include "RectangularPrism.h"
#include "Sphere.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 50;

void buildThing(ifstream& , Thing**, int);


int main() {

	int count = 0;
	/*vector<Thing> things;*/
	Thing** tarr = new Thing*[SIZE];

	ifstream fin("ass4data.bin", ios::in | ios::binary); 

	if (!fin) {
		cerr << "You failed to open the binary file!" << endl;
	}
	else {
		buildThing(fin, tarr, count);
	}


	return 0;
}

void buildThing(ifstream& fin, Thing** tarr, int count) {


		do {
			//make something that keep tracks on it

			unsigned char uc; //contains all info
			fin.read(reinterpret_cast<char*>(&uc), 1);


			cout << dec;
			cout << static_cast<int>(uc) << endl;
			uc ^= 0x81; //toggle the first and last bit
			cout << hex << showbase;
			cout << static_cast<int>(uc) << endl;
			unsigned char firstN = uc >> 4;
			cout << static_cast<int>(firstN) << endl;
			unsigned char secondN = uc & 0x0F;
			cout << static_cast<int>(secondN) << endl;

			int shapeType = static_cast<int>(firstN);
			int colorType = static_cast<int>(secondN);

			int numDouble = 0;

			if (shapeType == 1) { //cylinder
				numDouble = 2;
			}
			else if (shapeType == 2) {
				numDouble = 1;
			}
			else if (shapeType == 4) {
				numDouble = 3;
			}
			else if (shapeType == 8) {
				numDouble = 1;
			}

			if (colorType > 0) {
				++numDouble;
			}
			//just finished how much double that it need to receive
			vector<double> doubleArr;

			for (int i = 0; i < numDouble; i++) {
				double d;
				fin.read(reinterpret_cast<char*>(&d), sizeof(double));
				//cout << d << "    ";
				doubleArr.push_back(d);
			}
			
			//when there is color
			if (colorType > 0) {
				string color;
				switch (colorType) {
					case 1:
						color = "red";
						break;
					case 2:
						color = "blue";
						break;
					case 4:
						color = "green";
						break;
					case 8:
						color = "yellow";
						break;

				}

				double radius, height, weight, width, length, side;
				switch(shapeType) {
					case 1:
						radius = doubleArr.at(0);
						height = doubleArr.at(1);
						weight = doubleArr.at(2);
						tarr[count] = new ColoredCylinder(radius, height, weight, color);
						break;
					case 2:
						radius = doubleArr.at(0);
						weight = doubleArr.at(1);
						tarr[count] = new ColoredSphere(radius, weight, color);
						break;
					case 4:
						length = doubleArr.at(0);
						width = doubleArr.at(1);
						height = doubleArr.at(2);
						weight = doubleArr.at(3);
						tarr[count] = new ColoredRectangularPrism(length, width, height, weight, color);
						break;
					case 8:
						side = doubleArr.at(0);
						weight = doubleArr.at(1);
						tarr[count] = new ColoredCube(side, weight, color);
						break;

				}
			}
			else { // when there is no color
				double radius, height, width, length, side;
				switch (shapeType) {
					case 1:
						 radius = doubleArr.at(0);
						 height = doubleArr.at(1);
						tarr[count] = new Cylinder(radius, height);
						break;
					case 2:
						 radius = doubleArr.at(0);
						tarr[count] = new Sphere(radius);
						break;
					case 4:
						length = doubleArr.at(0);
						width = doubleArr.at(1);
						height = doubleArr.at(2);
						tarr[count] = new RectangularPrism(length, width, height);
						break;
					case 8:
						side = doubleArr.at(0);
						tarr[count] = new Cube(side);
						break;
				}
			
			}



			count++;

		} while (!fin.eof() && count < 50);

		cout << dec;
		cout << "Count " << count << endl;




};
