#pragma once
/*
* Lab 5 - CSE 332
* AbstractParsingStrategy.h
* Contains the declarations for the AbstractParsingStrategy interface 
*/
#include <vector>
#include <string>
class AbstractParsingStrategy {
public: 
	virtual std::vector<std::string> parse(std::string s) = 0;
};