#include "IOutputStrategyPattern.h"
#include <cctype>
#include <fstream>

#pragma once

using namespace std;
//Basic idea of generated code
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

/**
* Arduino Strategy pattern which when given a sorted list of tasks it
* produces the code above and places the result in a created main.ino
*/
class ArduinoStrategyPattern : public IOutputStrategyPattern{
	string output(vector<Task> list){
		//Initialize file outputs
		string file_output = "";
		string header_output ="";

		//Add header
		file_output += "#include \"main.h\"\n\n";

		//Get Task names
		vector<string> variableNames;
		int task_index = 0;
		for(Task task : list){
			string lowerFirst(1, tolower(task.className.at(0)));
			string variableName = lowerFirst +  task.className.substr(1);
			variableNames.push_back(variableName);
			file_output +=  "static " + task.className + " " + variableName + ";\n";
			header_output += "#define " + task.className+ "_INDEX " + to_string(task_index) + ";\n";
			++task_index;
		}			

		//Write array to access tasks
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

		//Add # of tasks (needed to access array)
		file_output += "const int taskCount = " + to_string(variableNames.size()) + ";\n";
		file_output += "\n";

		//Make setup function to initialize tasks
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

		//Make loop function to process tasks that are on at startup
		file_output += "void loop(){\n";
		for(string s : variableNames){
			file_output += "\t" + s + ".process();\n";
		}
		file_output += "}";

		//Output to files
		ofstream inoFile;
		inoFile.open("main.ino");
		inoFile << file_output << endl;
		inoFile.close();


		ofstream headerFile;
		headerFile.open("main.h");
		headerFile << header_output << endl;
		headerFile.close();
		
		//Print to Console
		cout << file_output << endl;
		cout << endl;
		cout << header_output << endl;

		//Return what was written
		return file_output + "\n" + header_output;
	}
};
