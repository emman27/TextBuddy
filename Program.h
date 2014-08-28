#ifndef PROGRAM_H
#define PROGRAM_H

#include "CommandHandler.h"
#include "FileControl.h"

//This class handles the main program execution

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