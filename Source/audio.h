#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "media.h"
using namespace std;

class Audio : public Media {
private:
	string formatDescriptor;
	string qualitySpec;
	string type;

public:
	Audio();
	Audio(string uniqueID, string name, int runningTime, string formatDescriptor, string qualitySpec);
	~Audio();
	bool ReadData(istream& in);
	bool WriteData(ostream& out);
	std::string getType() const;
};
