//BaseModel.h - Base Model Interface
#ifndef _BASEMODEL_H_
#define _BASEMODEL_H_

#include <iomanip>//setw()
#include <iostream>
#include <vector>

using namespace std;

class BaseModel {
public:
    virtual double predict(double input ) = 0;
};
#endif// _BASEMODEL_H_