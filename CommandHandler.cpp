#include "CommandHandler.h"

//Handles adding a line to the data set delimited by the newline character
std::vector<std::string> CommandHandler::add(std::vector<std::string> &data, std::string filename){
	std::string line;
	std::getline(std::cin, line);
	std::cout << "Added to " << filename << ": " << line << std::endl;
	data.push_back(line.substr(1, std::string::npos));
	return data;
}

//Handles removing a line from the data set. Must be given an integer number from the user interface.
//Non-existing data numbers will be rejected with the error message "Data not found"
std::vector<std::string> CommandHandler::del(std::vector<std::string> &data, std::string filename){
	unsigned int linenum;
	std::cin >> linenum;
	if (linenum <= data.size() && linenum > 0){
		std::cout << "Removed from " << filename << ": " << data[linenum - 1] << std::endl;
		data.erase(data.begin() + linenum - 1);
	}
	else{
		print.printErrorMsg("Data not found");
	}
	return data;
}

//Removes all data from the dataset
std::vector<std::string> CommandHandler::clear(std::vector<std::string> &data, std::string filename){
	data.clear();
	std::cout << "All content deleted from " << filename << std::endl;
	return data;
}


//Prints all data from the data set prefixed by the line number
//Will print an error message if the data set is empty
void CommandHandler::display(std::vector<std::string> data, std::string filename){
	if (data.empty()){
		print.printErrorMsg(filename + " is empty");
	}
	else{
		print.printData(data);
	}
}

//Processes the different cases of possible commands
//Non-acceptable commands are given an error message
std::vector<std::string> CommandHandler::processCommand(std::string cmd, std::vector<std::string> &data, std::string filename){
	if (cmd == "add"){
		data = add(data, filename);
	}
	else if (cmd == "delete"){
		data = del(data, filename);
	}
	else if (cmd == "clear"){
		data = clear(data, filename);
	}
	else if (cmd == "display"){
		display(data, filename);
	}
	else if (cmd == "exit"){
		NULL;
	}
	else{
		std::string burnline;
		getline(std::cin,burnline);
		print.printErrorMsg("Command not recognised");
	}
	return data;
}

