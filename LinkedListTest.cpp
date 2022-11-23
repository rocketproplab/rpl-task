#include <gtest/gtest.h>
#include "TaskLinkedList.h"
#include "RplTask.h"

TEST(AddTest, BasicAssertions){
	TaskLinkedList list;
	RplTask* task1 = new RplTask();
	list.add(task1);
	EXPECT_EQ(list.getSize(), 1);
	//RplTask* task2 = new RplTask();
	//list.add(task2);
}
