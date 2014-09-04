#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstdio>

//This class handles printing

class MessageSender{
private:
	static const std::string MESSAGE_ERROR;
	static const std::string MESSAGE_WELCOME;
public:
	MessageSender();
	void printErrorMsg(std::string msg);
	void printData(std::vector<std::string> &data);
	void printWelcome(std::string filename);
};
#endif