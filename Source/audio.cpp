#include "audio.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Audio::Audio() : Media() {
	formatDescriptor = "";
	qualitySpec = "";
	type = "Audio";
}


Audio::Audio(string uniqueID, string name, int runningTime, string formatDescriptor, string qualitySpec) : Media(uniqueID, name, runningTime) {
	this->formatDescriptor = formatDescriptor;
	this->qualitySpec = qualitySpec;
	type = "Audio";
}


Audio::~Audio() {}

bool Audio::ReadData(istream& in) {
	Media::ReadData(in);
	in.ignore();
	getline(in, formatDescriptor);
	getline(in, qualitySpec);
	return true;
}


bool Audio::WriteData(ostream& out) {
	Media::WriteData(out);
	out << formatDescriptor << endl;
	out << qualitySpec << endl;
	out << "***************************************" << endl;
	return true;
}


