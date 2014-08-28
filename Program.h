#ifndef PROGRAM_H
#define PROGRAM_H

#include "CommandHandler.h"
#include "FileControl.h"

class Program{

private:
	MessageSender p;
	CommandHandler cmdHandler;
	FileControl fileCont;

public:
	std::string requestCommand();
	void mainLoop(std::vector<std::string> &data, std::string filename);
};
#endif