#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Media {
protected:
	string uniqueID;
	string name;
	int runningTime;

public:
	Media();
	Media(string uniqueID, string name, int runningTime);
	~Media();
	void setUniqueID(string uniqueID);
	void setName(string name);
	void setRunningTime(int runningTime);
	string getUniqueID() const;
	string getName() const;
	int getRunningTime() const;
	virtual string getType();
	virtual bool ReadData(istream& in);
	virtual bool WriteData(ostream& out);
};
