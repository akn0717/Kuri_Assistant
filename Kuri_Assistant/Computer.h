#pragma once
#include <string>
using std::string;
class Computer
{
public:
	//execute a command through cmd
	//pre-condition: a string which is the command
	//post-condition: execute the command, return 0 if any error, 1 otherwise
	bool execute_cmd(const string& command) const;

	//start a process
	//pre-condition: a string which is the path of program
	//post-condition: run the program, return 0 if any error, 1 otherwise
	bool start_process(const string& path) const;

	//control mouse to click a specific position
	//pre-condition: int x, int y
	//post-condition: click at position x,y return 0 if any errors, 1 otherwise
	bool mouse_click(const int& x, const int& y) const;

};

