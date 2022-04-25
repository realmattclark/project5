#include "video.h"
#include <iostream>
#include <fstream>
#include <string>

Video::Video() : Media() {
	resolution = "";
	formatDescriptor = "";
	qualitySpec = "";
	type = "Video";
}


Video::Video(string uniqueID, string name, int runningTime,
	string resolution, string formatDescriptor, string qualitySpec)
	: Media(uniqueID, name, runningTime) {
	this->resolution = resolution;
	this->formatDescriptor = formatDescriptor;
	this->qualitySpec = qualitySpec;
	type = "Video";
};

Video::~Video() {};

bool Video::ReadData(istream& in) {
	Media::ReadData(in);
	in.ignore();
	getline(in, resolution);
	getline(in, formatDescriptor);
	getline(in, qualitySpec);
	return true;
}


bool Video::WriteData(ostream& out) {
	Media::WriteData(out);
	out << resolution << endl;
	out << formatDescriptor << endl;
	out << qualitySpec << endl;
	out << "***************************************" << std::endl;
	return true;
}


std::string Video::getType() const {
	return type;
}