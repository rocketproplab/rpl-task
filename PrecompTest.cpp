#include <gtest/gtest.h>
#include "PrecompTopSort.h"

using namespace std;


TEST(GetFileContentsTest, FileContents){
	string path = "TestTaskFolder/Task1.h";
	string output = getFileContents(path);

	string expected = "/*\nRPL-TASK-HEADER\nCLASS: Task1\nSTART-ON-BOOT: TRUE\nTASK-DEPENDENCIES\nTask2\nTask3\nEND-TASK-DEPENDENCIES\nEND-RPL-TASK-HEADER\n*/\n\nclass Task1{\n\n};\n";
	EXPECT_EQ(output, expected) << "Got:\n" << output << "\nExpected:\n" << expected;
}

TEST(GetTaskNameTest, TaskName){
	string path = "TestTaskFolder/Task2.h";
	string contents = getFileContents(path);

	string output = getTaskName(contents);
	string expected = "Task2";
	
	//EXPECT_EQ(output, expected) << "Got:\n" << output << "\nExpected:\n" << expected;
	EXPECT_EQ(output, expected) << "Got:\n" << output << "\nExpected:\n" << expected;
}

TEST(IsStartOnBootTest, TrueTest){
	string path = "TestTaskFolder/Task2.h";
	string contents = getFileContents(path);

	bool output = isTaskStartOnBoot(contents);
	bool expected = true;
	
	//EXPECT_EQ(output, expected) << "Got:\n" << output << "\nExpected:\n" << expected;
	EXPECT_EQ(output, expected); //<< "Got:\n" << output << "\nExpected:\n" << expected;
}

TEST(IsStartOnBootTest, FalseTest){
	string path = "TestTaskFolder/Task4.h";
	string contents = getFileContents(path);

	bool output = isTaskStartOnBoot(contents);
	bool expected = false;
	
	//EXPECT_EQ(output, expected) << "Got:\n" << output << "\nExpected:\n" << expected;
	EXPECT_EQ(output, expected); //<< "Got:\n" << output << "\nExpected:\n" << expected;
}

TEST(GetDependenciesTest, NoDependencies){
	string path = "TestTaskFolder/Task3.h";
	string contents = getFileContents(path);

	vector<string> output = getDependencies(contents);
	vector<string> expected;
	
	ASSERT_EQ(output.size(), expected.size()) << "Different size outputs";
	for(int i = 0; i < output.size(); ++i){	
		EXPECT_EQ(output[i], expected[i]);// << "Got:\n" << output[i] << "\nExpected:\n" << expected[i];
	}
}

TEST(GetDependenciesTest, OneDependency){
	string path = "TestTaskFolder/Task4.h";
	string contents = getFileContents(path);

	vector<string> output = getDependencies(contents);
	vector<string> expected;
	expected.push_back("Task3");
	
	ASSERT_EQ(output.size(), expected.size()) << "Different size outputs";
	for(int i = 0; i < output.size(); ++i){	
		EXPECT_EQ(output[i], expected[i]);// << "Got:\n" << output[i] << "\nExpected:\n" << expected[i];
	}
}

TEST(GetDependenciesTest, MultipleDependencies){
	string path = "TestTaskFolder/Task1.h";
	string contents = getFileContents(path);

	vector<string> output = getDependencies(contents);
	vector<string> expected;
	expected.push_back("Task2");
	expected.push_back("Task3");
	
	ASSERT_EQ(output.size(), expected.size()) << "Different size outputs";
	for(int i = 0; i < output.size(); ++i){	
		EXPECT_EQ(output[i], expected[i]);// << "Got:\n" << output[i] << "\nExpected:\n" << expected[i];
	}
}
