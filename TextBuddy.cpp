// TextBuddy.cpp : Defines the entry point for the console application.

#include "Program.h"

int main(int argc, char* argv[])
{
	std::string filename;
	std::vector<std::string> data;
	FileControl fileCont;
	const std::string FILE_ALREADY_SPECIFIED = "filealreadyspecified";
	MessageSender print;
	Program p;
	
	filename = fileCont.checkFile(argc);
	if (filename == FILE_ALREADY_SPECIFIED) filename = argv[1];

	data = fileCont.readFile(filename);

	print.printWelcome(filename);
	p.mainLoop(data, filename);
	return 1;
}