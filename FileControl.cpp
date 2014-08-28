#include "FileControl.h"

FileControl::FileControl(){
	FILE_ALREADY_SPECIFIED = "filealreadyspecified";
}

std::string FileControl::getFilename(){
	std::string s;
	std::cout << "Enter filename: ";
	std::cin >> s;
	return s;
}

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

void FileControl::saveData(std::vector<std::string> &data, std::string filename){
	myFile.open(filename.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	for(unsigned int i=0; i<data.size(); i++){
		myFile << data[i] << std::endl;
	}
	myFile.close();
}