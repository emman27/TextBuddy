#ifndef FILECONTROL_H
#define FILECONTROL_H

#include <fstream>
#include "MessageSender.h"

class FileControl{

private:
	std::fstream myFile;
	MessageSender p;
	std::string FILE_ALREADY_SPECIFIED;

public:
	FileControl();
	bool checkFileSpecified(int n);
	std::string getFilename();
	std::string checkFile(int i);
	std::vector<std::string> readFile(std::string filename);
	void saveData(std::vector<std::string> &data, std::string filename);

};
#endif