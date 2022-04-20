#include "CommandPrompt.h"
#include <iostream>
#include <sstream>
CommandPrompt::CommandPrompt(): a(nullptr), f(nullptr) {

}
void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	a = afs;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	f = aff;
}
int CommandPrompt::addCommand(std::string s, AbstractCommand* ac) {
	std::pair<std::string, AbstractCommand*> stringPair(s, ac);
	m.insert(stringPair);
	return 0;
}
int CommandPrompt::run() {
	bool userQuit = false;
	
	while (userQuit == false) {
		std::string s = prompt();
		if (s.compare("q") == 0) {
			return 8;
		}
		else if (s.compare("help") == 0) {
			listCommands();
		}
		else {
			if (s.find(" ") == std::string::npos){
				if (m.count(s) != 0) {
					
					int key = m.find(s)->second->execute("");
					if (key != 0) {
						std::cout << "command failed" << std::endl;

					}
				}
				else {
					std::cout << "command not found" << std::endl;
				}
				

			}
			else {
				std::istringstream iss(s);
				std::string word1 = "";
				std::string word2 = "";
				iss >> word1 >> word2;
				if (word1 == "help") {
					if (m.count(s) != 0) {

						m.find(s)->second->displayInfo();
						
					}
					else {
						std::cout << "command not found" << std::endl;
					}
				}
				else {
					if (m.count(s) != 0) {

						int key = m.find(s)->second->execute(word2);
						std::cout << key << std::endl;

					}
					else {
						return 7;
					}

				}
				
			}
		}

	}
}

void CommandPrompt::listCommands() {
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << std::endl;
	}
}
std::string CommandPrompt::prompt(){
	std::cout << "Please enter a valid command or q to quit, help for a list of commands, or help<command name> for details about a specific command" << std::endl;
	std::cout << "$  ";
	std::string input;
	std::getline(std::cin, input);
	return input;

}

	std::map <std::string, AbstractCommand*> m;
	AbstractFileSystem* a;
	AbstractFileFactory* f;