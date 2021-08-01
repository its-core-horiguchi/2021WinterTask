#include <iostream>
#include <iomanip>
#include "ExcuteBMI.h"
#include "CheckBMI.cpp"
using namespace std;

InputBMI::InputBMI() {
	this->totalCount = 0;
}

bool InputBMI::inputData() {

	do {
		// 名前のキー入力
		cout << "お名前を入力してください：";
		cin >> this->name;
		this->nameList[this->totalCount] = this->name;

		// 身長（cm）のキー入力
		cout << "身長を入力してください：";
		cin >> this->height;
		heightList[this->totalCount] = this->height;

		// 体重（kg）のキー入力
		cout << "体重を入力してください：";
		cin >> this->weight;
		weightList[this->totalCount] = this->weight;

		if (this->totalCount < 2) {
			// 追加で入力するか。
			cout << "追加で入力しますか？(y/n)：";
			cin >> this->yn;

			if (this->yn == "y") {
				// 「y」の場合は入力続行。
				this->totalCount = this->totalCount + 1;
				this->end = true;
			}
			else if (yn == "n") {
				// 「n」の場合は入力を終了し、BMIの判定に移る。
				this->end = false;
			}
			else {
				// それ以外は処理終了。
				this->end = false;
				cout << "不明な入力です。処理を終了します。" << endl;
				return false;
			}
		}
		else {
			// 3人まで入力したら強制的にBMIの判定に移る。
			this->end = false;
		}

	} while (this->end);

	cout << "標準体重との差を追加で表示しますか？(y/n)：";
	cin >> this->differeceFlag;

	if (this->differeceFlag != "y" && this->differeceFlag != "n") {
		// それ以外は処理終了。
		this->end = false;
		cout << "不明な入力です。処理を終了します。" << endl;
		return false;
	}

	return true;
}

string InputBMI::getName() {
	return this->nameList[this->count];
}

double InputBMI::getHeight() {
	return this->heightList[this->count];
}

int InputBMI::getWeight() {
	return this->weightList[this->count];
}

int InputBMI::getTotalCount() {
	return this->totalCount;
}

void InputBMI::setCount(int count) {
	this->count = count;
}

string InputBMI::getDiffereceFlag() {
	return this->differeceFlag;
}

void GetBMI::calcBMI() {

	// 標準BMI値
	const int STD_BMI = 22;

	// BMI計算
	this->bmi = this->weight / (this->mHeight * this->mHeight);

	// 標準体重計算
	this->stdWeight = STD_BMI * (this->mHeight * this->mHeight);

	// 標準体重との差を計算
	this->weightDifferece = this->weight - this->stdWeight;
}

double GetBMI::getDeightDifferece() {
	return this->weightDifferece;
}

DisplayBMI::DisplayBMI(string name, double bmi, double stdWeight) {
	this->name = name;
	this->bmi = bmi;
	this->stdWeight = stdWeight;
}

void DisplayBMI::displayResult() {
	// BMIの表示
	cout << this->getName() << "さんのBMIは、" << fixed << setprecision(1) << this->getBMI() << "です。" << endl;

	// 標準体重の表示
	cout << this->getName() << "さんの標準体重は、" << this->getStdWeight() << "kgです。" << endl;

	// どのくらいの肥満度か判定する。
	cout << checkBMI(this->getBMI()) << endl;
}

void DisplayBMI::displayResult(double weightDifferece) {

	// 基本の情報を表示
	this->displayResult();

	// 標準体重との差を表示
	cout << "標準体重との差は、" << weightDifferece << "kgです。" << endl;
}