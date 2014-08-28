#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <iostream>
#include <vector>
#include "MessageSender.h"


class CommandHandler{
private:
	MessageSender print;
public:
	std::vector<std::string> add(std::vector<std::string> &data, std::string filename);
	std::vector<std::string> del(std::vector<std::string> &data, std::string filename);
	std::vector<std::string> clear(std::vector<std::string> &data, std::string filename);
	void display(std::vector<std::string> data, std::string filename);
	std::vector<std::string> processCommand(std::string cmd, std::vector<std::string> &data, std::string filename);
	
};
#endif