#include <iostream>
#include <iomanip>
using namespace std;

string checkBMI(double bmi) {

	// どのくらいの肥満度か判定する。
	if (bmi < 18.5) {
		return "低体重です。";
	}
	else if (bmi < 25.0) {
		return "普通体重です。";
	}
	else if (bmi < 30.0) {
		return "肥満（１度）です。";
	}
	else if (bmi < 35.0) {
		return "肥満（２度）です。";
	}
	else if (bmi < 40.0) {
		return "肥満（３度）です。";
	}
	else {
		return "肥満（４度）です。";
	}

	return "";
}