#include <iostream>
#include <iomanip>
using namespace std;

string checkBMI(double bmi) {

	// �ǂ̂��炢�̔얞�x�����肷��B
	if (bmi < 18.5) {
		return "��̏d�ł��B";
	}
	else if (bmi < 25.0) {
		return "���ʑ̏d�ł��B";
	}
	else if (bmi < 30.0) {
		return "�얞�i�P�x�j�ł��B";
	}
	else if (bmi < 35.0) {
		return "�얞�i�Q�x�j�ł��B";
	}
	else if (bmi < 40.0) {
		return "�얞�i�R�x�j�ł��B";
	}
	else {
		return "�얞�i�S�x�j�ł��B";
	}

	return "";
}