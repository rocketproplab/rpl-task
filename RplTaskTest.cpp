#include <gtest/gtest.h>
#include "RplTask.h"

/*tests TODO:
* - check all statuses are set correctly
* - onStart, onResume, onPause, onLoop are called when intended
* - dependencies STOPPED before running task
* - 
*/


TEST(statusTest, ) {
	TaskLinkedList list;
	RplTask* task1 = (RplTask*)new TestTask();

	list.add(task1);
	EXPECT_EQ(list.getSize(), 1);
	EXPECT_EQ(list.head->value, task1);
	//delete task1;
	//RplTask* task2 = new RplTask();
	//list.add(task2);
}

TEST(addDependTest, AddEmptyTest) {
	
}

TEST(checkDependTest, AddEmptyTest) {
	
}

TEST(startTest, AddEmptyTest) {
	
}

TEST(pauseTest, AddEmptyTest) {
	
}

TEST(resumeTest, AddEmptyTest) {
	
}

TEST(processTest, AddEmptyTest) {
	
}
