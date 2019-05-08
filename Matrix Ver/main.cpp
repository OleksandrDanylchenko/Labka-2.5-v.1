// LABKA 2.5 v.1 Matrix
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#define NOMINMAX
#include <Windows.h>

#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\vList.h"
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\grRepres.h"

void studentInfo();
void labInfo();
bool readFromFile(const std::string&, GrA&);
bool writeToFile(const std::string&, GrA&);
std::string getFilePath(char);
std::string formatTime(std::clock_t);

int main() {
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	studentInfo();
	labInfo();

	////MATRIX////
	std::cout << "\nMatrix representation";
	GrMA grMat;
	std::clock_t generalTimeMatrix = 0;
	while (true) {
		std::string inputFilePathM = getFilePath('i');
		std::clock_t timeStart = std::clock();
		if (readFromFile(inputFilePathM, grMat)) {
			std::clock_t timeEnd = std::clock();
			std::cout << "Input in matrix, CPU time used: " << formatTime(timeEnd - timeStart) << std::endl;
			generalTimeMatrix += (timeEnd - timeStart);
			break;
		} else
			continue;
	}
	while (true) {
		std::string outputFilePathM = getFilePath('o');
		std::clock_t timeStart = std::clock();
		if (writeToFile(outputFilePathM, grMat)) {
			std::clock_t timeEnd = std::clock();
			std::cout << "Output in matrix, CPU time used: " << formatTime(timeEnd - timeStart) << std::endl;
			generalTimeMatrix += (timeEnd - timeStart);
			break;
		} else
			continue;
	}
	std::cout << "General matrix processing time: " << formatTime(generalTimeMatrix) << std::endl << std::endl;
	system("pause");
	return 0;
}                          

void studentInfo() {
	std::cout << "Laboratory work 2 - 5 Graphs Processing\n" << 
		         "Group: K-14 Danilchenko Alexander" << std::endl;
}
void labInfo() {
	std::cout << "\nThis programm reads information about graph from the input file and converts it to an adjacency matrix and adjacency list\n" <<
				 "After that it outputs representation of graph with another format" << std::endl;
} 

std::string getFilePath(char ioVar) {
	std::string filePath = "";
	if (std::cin.bad()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (ioVar == 'i')
		std::cout << "\nEnter the path to the input file: ";
	else // ioVar == 'o'
		std::cout << "\nEnter the path to the output file: ";
	getline(std::cin, filePath);
	if (filePath.find('\\') == std::string::npos and filePath.find('/') == std::string::npos) {
		std::string rootFolder = "D:/Studying/Programming/LABS/Labka 2.5/Labka 2.5 text files/";
		filePath.insert(0, rootFolder); // prepend address of the root folder
		filePath.append(".txt"); // append extension of a text file
	}
	return filePath;
}

bool readFromFile(const std::string& inputFilePath, GrA& g) {
	std::ifstream inputS;
	inputS.open(inputFilePath);
	if (inputS.fail())
		return false;
	bool isDir; size_t n;
	inputS >> isDir >> n;
	g.setisDir(isDir);
	if (!(g.create(n)))
		return false;
	size_t i, j;
	while (inputS >> i >> j)
		g.addArc(i, j);
	inputS.close();
	return true;
}
 
bool writeToFile(const std::string& outputFilePath, GrA& g) {
	std::ofstream outputS;
	outputS.open(outputFilePath);
	if (outputS.fail())
		return false;
	
	size_t n = g.getN(), m = g.getM();
	bool dir = g.getIsDir();
	outputS << dir << ' ' << n << ' ' << m << std::endl;
	for (size_t i = 0; i < n; ++i) {
		VList nbs = g.neighbors(i);
		if (nbs.notEmpty()) {
			outputS << i << ": ";
			nbs.output(outputS);
			outputS << std::endl;
		}
	}
	outputS.close();
}

std::string formatTime(std::clock_t time) {
	std::string resultStr = "";
	size_t sec = time / 1000;
	resultStr.append(std::to_string(sec) + "s. ");
	size_t ms = time % 1000;
	resultStr.append(std::to_string(ms) + "ms.");
	return resultStr;
}