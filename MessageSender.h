#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <iostream>
#include <vector>
#include <string>

class MessageSender{
private:

public:
	void printErrorMsg(std::string msg);
	void printData(std::vector<std::string> &data);
	void printWelcome(std::string filename);
};
#endif