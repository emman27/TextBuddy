#include "MessageSender.h"

void MessageSender::printErrorMsg(std::string msg){
	std::vector<std::string> data;
	std::cout << "Operation failed. Reason: " << msg << std::endl;
}

void MessageSender::printWelcome(std::string filename){
	std::cout << "Welcome to TextBuddy. " << filename << " is ready for use\n";
}

void MessageSender::printData(std::vector<std::string> &data){
	for (unsigned int i = 0; i < data.size(); i++){
		std::cout << i + 1 << ". " << data[i] << std::endl;
	}
}