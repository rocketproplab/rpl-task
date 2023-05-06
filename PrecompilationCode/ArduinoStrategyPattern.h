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

		file_output += "#include \"main.h\"\n\n";

		vector<string> variableNames = getVariableNames(list);

		writeHeaderDefs(&header_output, list);
		writeTaskVariableNames(&file_output, list, variableNames);
		writeTaskArray(&file_output, variableNames);
		writeSetupFunc(&file_output, variableNames, list);
		writeLoopFunc(&file_output, variableNames);

		//Output to files + print to console
		ofstream inoFile;
		inoFile.open("main.ino");
		inoFile << file_output << endl;
		inoFile.close();

		ofstream headerFile;
		headerFile.open("main.h");
		headerFile << header_output << endl;
		headerFile.close();
		
		cout << file_output << endl;
		cout << endl;
		cout << header_output << endl;

		return file_output + "\n" + header_output;
	}
	
	vector<string> getVariableNames(vector<Task> list){
		vector<string> variableNames;
		for(Task task : list){
			string lowerFirst(1, tolower(task.className.at(0)));
			string variableName = lowerFirst +  task.className.substr(1);
			variableNames.push_back(variableName);
		}
		return variableNames;
	}

	void writeHeaderDefs(string *header_output, vector<Task> list){
		for(int i = 0; i < list.size(); ++i){
			*header_output += "#define " + list[i].className+ "_INDEX " + to_string(i) + ";\n";
		} 
	}

	void writeTaskVariableNames(string *file_output, vector<Task> list, vector<string> variableNames){
		for(int i = 0; i < list.size(); ++i){
			*file_output +=  "static " + list[i].className + " " + variableNames[i] + ";\n";
		} 
	}

	void writeTaskArray(string *file_output, vector<string> variableNames){
		*file_output += "\n";
		*file_output += "RplTask* tasks[] = {";
		bool flag = true;
		for(string s : variableNames){
			if(flag){
				*file_output += "&" + s;
				flag = false;
			}else{
				*file_output += ", &" + s;
			}
		}
		*file_output += "};\n";
		*file_output += "const int taskCount = " + to_string(variableNames.size()) + ";\n";
		*file_output += "\n";
	}

	void writeSetupFunc(string *file_output, vector<string> variableNames, vector<Task> list){
		*file_output += "void setup(){\n";
		for(string s : variableNames){
			*file_output += "\t" + s + ".init(&tasks, taskCount);\n";
		}
		*file_output += "\n";
		for(int i = 0; i < variableNames.size(); ++i){
			if(list[i].startOnBoot){
				*file_output += "\t" + variableNames[i] + ".start();\n";
			}
		}
		*file_output += "}\n";
		*file_output += "\n";
	}

	void writeLoopFunc(string *file_output, vector<string> variableNames){
		*file_output += "void loop(){\n";
		for(string s : variableNames){
			*file_output += "\t" + s + ".process();\n";
		}
		*file_output += "}";
	}
};
