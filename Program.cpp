#include "Program.h"


std::string Program::requestCommand(){
	std::string cmd;
	std::cout << "command: ";
	std::cin >> cmd;
	return cmd;
}

void Program::mainLoop(std::vector<std::string> &data, std::string filename){
	std::string cmd = "";
	while(cmd != "exit"){
		cmd = requestCommand();
		data = cmdHandler.processCommand(cmd, data, filename);
		fileCont.saveData(data, filename);
	}
}