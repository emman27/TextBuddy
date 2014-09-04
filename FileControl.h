#ifndef FILECONTROL_H
#define FILECONTROL_H

#include <fstream>
#include "MessageSender.h"

//This class handles operations regarding the txt file where data is saved

class FileControl{

private:
	std::fstream myFile;
	MessageSender p;
	static const std::string FILE_ALREADY_SPECIFIED;
	static const int EXPECTED_ARG_NUMBER;

public:
	FileControl();
	bool checkFileSpecified(int n);
	std::string getFilename();
	std::string checkFile(int i);
	std::vector<std::string> readFile(std::string filename);
	void saveData(std::vector<std::string> &data, std::string filename);

};
#endif