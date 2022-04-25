#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "media.h"
using namespace std;

class Video : public Media {
protected:
    string resolution;
    string formatDescriptor;
    string qualitySpec;
    string type;

public:
    Video();
    Video(string uniqueID, string name, int runningTime, string resolution, string formatDescriptor, string qualitySpec);
    ~Video();
    bool ReadData(istream& in);
    bool WriteData(ostream& out);
    string getType();
};
