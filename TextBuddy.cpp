// TextBuddy.cpp : Defines the entry point for the console application.

#include "Program.h"


int main(int argc, char* argv[])
{
	std::string filename;
	std::vector<std::string> data;
	FileControl fileCont;
	MessageSender print;
	Program p;
	
	const std::string FILE_ALREADY_SPECIFIED = "filealreadyspecified";
	const int FILE_NAME_POSITION = 1;
	
	filename = fileCont.checkFile(argc);
	if (filename == FILE_ALREADY_SPECIFIED) filename = argv[FILE_NAME_POSITION];

	data = fileCont.readFile(filename);

	print.printWelcome(filename);
	p.mainLoop(data, filename);
	return 1;
}