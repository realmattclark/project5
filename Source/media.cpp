
#include "media.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Media::Media() {
	uniqueID = "";
	name = "";
	runningTime = 0;
}


Media::Media(string uniqueID, string name, int runningTime) {
	this->uniqueID = uniqueID;
	this->name = name;
	this->runningTime = runningTime;
}


Media::~Media() {}


void Media::setUniqueID(string uniqueID) {
	this->uniqueID = uniqueID;
}


void Media::setName(string name) {
	this->name = name;
}


void Media::setRunningTime(int runningTime) {
	this->runningTime = runningTime;
}


std::string Media::getUniqueID() const {
	return uniqueID;
}


std::string Media::getName() const {
	return name;
}


int Media::getRunningTime() const {
	return runningTime;
}


bool Media::ReadData(istream& in) {
	getline(in, uniqueID);
	getline(in, name);
	in >> runningTime;
	return true;
}


bool Media::WriteData(ostream& out) {
	out << uniqueID << endl;
	out << name << endl;
	out << runningTime << endl;
	return true;
}