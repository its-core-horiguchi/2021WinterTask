#include <iostream>
#include <iomanip>
using namespace std;

class HumanData {

public:
    void setName(string name);
    string getName();
    void setWeight(int weight);
    int getWeight();
    void setHeight(double height);
    double getHeight();
    double getMHeight();
    double getBMI();
    double getStdWeight();

protected:
    string name;
    double height;
    int weight;
    double mHeight;
    double bmi;
    double stdWeight;
};