#include "MessageSender.h"

MessageSender::MessageSender(){
}

const std::string MessageSender::MESSAGE_ERROR = "Operation failed. Reason: ";
const std::string MessageSender::MESSAGE_WELCOME = "Welcome to TextBuddy. %s is ready for use\n";


//Prints error message given as a string
void MessageSender::printErrorMsg(std::string msg){
	std::vector<std::string> data;
	std::cout << MESSAGE_ERROR << msg << std::endl;
}

//Prints welcome message with given string which is the name of the txt file
void MessageSender::printWelcome(std::string filename){
	printf(MESSAGE_WELCOME.c_str(), filename.c_str());
}

//Prints all data in the file, given the data as a vector
void MessageSender::printData(std::vector<std::string> &data){
	for (unsigned int i = 0; i < data.size(); i++){
		std::cout << i + 1 << ". " << data[i] << std::endl;
	}
}