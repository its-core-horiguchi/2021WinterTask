#include <iostream>
#include <iomanip>
#include "HumanData.h"
using namespace std;

void HumanData::setName(string name) {
	this->name = name;
}

string HumanData::getName() {
	return this->name;
}

void HumanData::setWeight(int weight) {
	this->weight = weight;
}

int HumanData::getWeight() {
	return this->weight;
}

void HumanData::setHeight(double height) {
	this->height = height;
	this->mHeight = this->height / 100;
}

double HumanData::getHeight() {
	return this->height;
}

double HumanData::getMHeight() {
	return this->mHeight;
}