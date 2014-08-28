#include "MessageSender.h"

//Prints error message given as a string
void MessageSender::printErrorMsg(std::string msg){
	std::vector<std::string> data;
	std::cout << "Operation failed. Reason: " << msg << std::endl;
}

//Prints welcome message with given string which is the name of the txt file
void MessageSender::printWelcome(std::string filename){
	std::cout << "Welcome to TextBuddy. " << filename << " is ready for use\n";
}

//Prints all data in the file, given the data as a vector
void MessageSender::printData(std::vector<std::string> &data){
	for (unsigned int i = 0; i < data.size(); i++){
		std::cout << i + 1 << ". " << data[i] << std::endl;
	}
}