#include "FileControl.h"

FileControl::FileControl(){
	FILE_ALREADY_SPECIFIED = "filealreadyspecified";
}

//Gets intended text file used for storage from user
//File name must be legitimate - ends with .txt
std::string FileControl::getFilename(){
	std::string s;
	std::cout << "Enter filename: ";
	std::cin >> s;
	return s;
}

//Checks that the user has specified a file to use for data storage
//Loops until user provides a file name
std::string FileControl::checkFile(int i){
	std::string s = FILE_ALREADY_SPECIFIED;
	while (!checkFileSpecified(i)){
		p.printErrorMsg("Txt file not specified.");
		s = getFilename();
		if (s != FILE_ALREADY_SPECIFIED) i++;
	}
	return s;
}

bool FileControl::checkFileSpecified(int n){
	return n>1;
}

//Reads the text file specified and returns the data in form of a vector
std::vector<std::string> FileControl::readFile(std::string filename){
	std::vector<std::string> data;
	std::string line;
	myFile.open(filename.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	while (getline(myFile, line)){
		data.push_back(line);
	}
	myFile.close();
	return data;
}

//Saves the vector of data into the specified txt file
void FileControl::saveData(std::vector<std::string> &data, std::string filename){
	myFile.open(filename.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	for(unsigned int i=0; i<data.size(); i++){
		myFile << data[i] << std::endl;
	}
	myFile.close();
}