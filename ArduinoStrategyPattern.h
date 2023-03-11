#include "iOutputStrategyPattern.h"
#include <cctype>

#pragma once

using namespace std;
/*
	static Task1 task1;
	static Task2 task2;

	RplTask* tasks[] = {&task1, &task2};
	const int taskCount = xyz;

	void setup(){
		task1->start();
		task2->start();
	}

	void loop(){
		task1->process();
		task2->process();
	}
*/

class ArduinoStrategyPattern : public iOutputStrategyPattern{
	void output(vector<Task> list){
		string file_output = "";
		vector<string> variableNames;
		for(Task task : list){
			string lowerFirst(1, tolower(task.className.at(0)));
			string variableName = lowerFirst +  task.className.substr(1);
			variableNames.push_back(variableName);
			file_output +=  "static " + task.className + " " + variableName + ";\n";
		}			
		file_output += "\n";
		file_output += "RplTask* tasks[] = {";
		bool flag = true;
		for(string s : variableNames){
			if(flag){
				file_output += "&" + s;
				flag = false;
			}else{
				file_output += ", &" + s;
			}
		}
		file_output += "};\n";
		file_output += "const int taskCount = " + to_string(variableNames.size()) + ";\n";
		file_output += "\n";
		file_output += "void setup(){\n";
		for(string s : variableNames){
			file_output += "\t" + s + ".init(&tasks, taskCount);\n";
		}
		file_output += "\n";
		for(int i = 0; i < variableNames.size(); ++i){
			if(list[i].startOnBoot){
				file_output += "\t" + variableNames[i] + ".start();\n";
			}
		}
		file_output += "}\n";
		file_output += "\n";
		file_output += "void loop(){\n";
		for(string s : variableNames){
			file_output += "\t" + s + ".process();\n";
		}
		file_output += "}";
		ofstream inoFile;
		inoFile.open("main.ino");
		inoFile << file_output << endl;
		inoFile.close();
		cout << file_output << endl;
	}
};
