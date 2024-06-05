#ifndef VECTOR_H
#define VECTOR_H

#include "cmath"
#include "iostream"

class vector {
public:
	float x, y, z;

	//add two vectors
	vector operator+(vector v) {
		vector temp;
		temp.x = this->x + v.x;
		temp.y = this->y + v.y;
		temp.z = this->z + v.z;
		return temp;
	}

	//scale a vector depending on the factor
	vector operator*(float scale) {
		vector temp;
		temp.x = (this->x) * scale;
		temp.y = (this->y) * scale;
		temp.z = (this->z) * scale;
		return temp;
	}

	//subtract two vectors
	vector operator-(vector v) {
		vector temp;
		temp.x = this->x - v.x;
		temp.y = this->y - v.y;
		temp.z = this->z - v.z;
		return temp;
	}

	//normalise vector
	vector normalise() {
		vector temp;
		float len = sqrt(x * x + y * y + z * z);
		temp.x = (this->x) / len;
		temp.y = (this->y) / len;
		temp.z = (this->z) / len;
		return temp;
	}

	void print() {
		std::cout << "X is " << this->x;
		std::cout << ", Y is " << this->y;
		std::cout << ", Z is " << this->z;
	}

	//constructors
	vector() = default;

	vector(float a, float b, float c) {
		this->x = a;
		this->y = b;
		this->z = c;
	}
};

class polarVector {
public:
	float psi, phi;

	//polar to cartesian
	vector toCartVec() {
		vector temp;
		temp.x = cos(this->psi) * cos(this->phi);
		temp.y = cos(this->psi) * sin(this->phi);
		temp.z = sin(this->psi);
		return temp;
	}
};

#endif 
