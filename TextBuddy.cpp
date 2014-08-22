// TextBuddy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int check_file_specified(int n){
	if (n < 2){
		return 0;
	}
	return 1;
}

int check_file(std::string filename){

}

void print_error_msg(std::string msg){
	std::cout << "Operation failed. Reason: " << msg << std::endl;
}

int main(int argc, char* argv[])
{
	std::string cmd, line;
	unsigned int linenum;
	std::vector<std::string> data;

	//ensures that txt file is specified
	if (argc < 2){
		print_error_msg("Missing text file name");
		return 0;
	}

	std::fstream myfile;

	//reads old data already in file
	myfile.open(argv[1], std::ios::in||std::ios::out);

	while (getline(myfile, line)){
		data.push_back(line);
	}

	myfile.close();

	std::cout << "Welcome to TextBuddy. " <<argv[1] << " is ready for use\n";
	std::cout << "command: ";
	//Main program loop
	while (cmd!="exit")
	{
		std::cin >> cmd;

		if (cmd == "add"){
			std::getline(std::cin, line);
			std::cout << "Added to " << argv[1] << ": " << line << std::endl;
			data.push_back(line.substr(1,std::string::npos));
		}

		else if (cmd == "delete"){
			std::cin >> linenum;
			if (linenum <= data.size() && linenum > 0){ //ensures that the number is legit.
				std::cout << "Removed from " << argv[1] << ": " << data[linenum - 1] << std::endl;
				data.erase(data.begin() + linenum - 1);
			}
			else{
				std::cout << "Data not found\n";
			}
		}

		else if (cmd == "clear"){
			data.clear();
			std::cout << "All content deleted from " << argv[1] << std::endl;
		}

		else if (cmd == "display"){
			if (data.empty()){
				std::cout << argv[1] << " is empty" << std::endl;
			}
			else{
				for (unsigned int i = 0; i < data.size(); i++){
					std::cout << i + 1 << ". " << data[i] << std::endl;
				}
			}
		}
		else{
			std::cout << "Command not recognised\n";
			continue;
		}
		std::cout << "command: ";
	}

	//Write to txt file and clears old data
	myfile.open(argv[1], std::ios::trunc|std::ios::out);

	for (unsigned int i = 0; i < data.size(); i++){
		myfile << data[i] << std::endl;
	}

	myfile.close();
	return 1;
}

