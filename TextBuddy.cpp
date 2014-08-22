// TextBuddy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void print_error_msg(std::string msg){
	std::vector<std::string> data;
	std::cout << "Operation failed. Reason: " << msg << std::endl;
}

bool check_file_specified(int n){
	if (n < 2){
		return false;
	}
	return true;
}

std::string get_filename(){
	std::string s;
	std::cout << "Enter filename: ";
	std::cin >> s;
	return s;
}

std::string check_file(int i){
	std::string s = "filealreadyspecified";
	while (!check_file_specified(i)){
		print_error_msg("Txt file not specified.");
		get_filename();
	}
	return s;
}

std::vector<std::string> read_file(std::string filename){
	std::fstream myfile;
	std::vector<std::string> data;
	std::string line;
	myfile.open(filename, std::ios::in || std::ios::out);
	while (getline(myfile, line)){
		data.push_back(line);
	}
	myfile.close();
	return data;
}

void print_welcome(std::string filename){
	std::cout << "Welcome to TextBuddy. " << filename << " is ready for use\n";
}

std::string request_command(){
	std::string cmd;
	std::cout << "command: ";
	std::cin >> cmd;
	return cmd;
}

std::vector<std::string> add(std::vector<std::string> data, std::string filename){
	std::string line;
	std::getline(std::cin, line);
	std::cout << "Added to " << filename << ": " << line << std::endl;
	data.push_back(line.substr(1, std::string::npos));
	return data;
}

std::vector<std::string> del(std::vector<std::string> data, std::string filename){
	unsigned int linenum;
	std::cin >> linenum;
	if (linenum <= data.size() && linenum > 0){
		std::cout << "Removed from " << filename << ": " << data[linenum - 1] << std::endl;
		data.erase(data.begin() + linenum - 1);
	}
	else{
		print_error_msg("Data not found");
	}
	return data;
}

std::vector<std::string> clear(std::vector<std::string> data, std::string filename){
	data.clear();
	std::cout << "All content deleted from " << filename << std::endl;
	return data;
}

void print_data(std::vector<std::string> data){
	for (unsigned int i = 0; i < data.size(); i++){
		std::cout << i + 1 << ". " << data[i] << std::endl;
	}
}

void display(std::vector<std::string> data, std::string filename){
	if (data.empty()){
		print_error_msg(filename + " is empty");
	}
	else{
		print_data(data);
	}
}

std::vector<std::string> process_cmd(std::string cmd, std::vector<std::string> data, std::string filename){
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
	else{
		print_error_msg("Command not recognised");
	}
	return data;
}

void save_data(std::vector<std::string> data, std::string filename){
	std::fstream myfile;
	myfile.open(filename, std::ios::trunc | std::ios::out);
	for (unsigned int i = 0; i < data.size(); i++){
		myfile << data[i] << std::endl;
	}
	myfile.close();
}

void mainloop(std::vector<std::string> data, std::string filename){
	std::string cmd = NULL;
	while(cmd != "exit"){
		cmd = request_command();
		data = process_cmd(cmd, data, filename);
		save_data(data, filename);
	}
}

int main(int argc, char* argv[])
{
	std::string filename;
	std::vector<std::string> data;
	
	filename = check_file(argc);
	if (filename == "filealreadyspecified") filename = argv[1];

	data = read_file(filename);

	print_welcome(argv[1]);
	mainloop(data, filename);
	return 1;
}