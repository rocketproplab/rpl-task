#include <gtest/gtest.h>
#include "TaskLinkedList.h"
#include "RplTask.h"

/*
	Adding a new node to an empty list and check add method
*/
TEST(AddTest, AddEmptyTest){
	TaskLinkedList list;
	RplTask* task1 = new RplTask();
	list.add(task1);
	EXPECT_EQ(list.getSize(), 1);
	EXPECT_EQ(list.head->value, task1);
	//delete task1;
	//RplTask* task2 = new RplTask();
	//list.add(task2);
}

/*
	Adding a new node to a non-empty list and check add method
*/
TEST(AddTest, AddMultiple){
	TaskLinkedList list;
	RplTask* task1 = new RplTask();
	RplTask* task2 = new RplTask();
	RplTask* task3 = new RplTask();

	list.add(task1);
	list.add(task2);
	list.add(task3);
	EXPECT_EQ(list.getSize(),3);
	EXPECT_EQ(list.head->value, task1);
	EXPECT_EQ(list.head->next->value, task2);
	EXPECT_EQ(list.head->next->next->value, task3);

	//delete task1;
	//delete task2;
	//delete task3;
}

/*
	Test get method in a empty list
*/
TEST(GetTest, GetNodeEmptyList){
	TaskLinkedList list;
	EXPECT_EQ(list.get(1), nullptr);
}

/*
	Test get method with an index number in a non-empty list
*/
TEST(GetTest, GetNodeWithIndex){
	TaskLinkedList list;
	
	RplTask* task1 = new RplTask();
	RplTask* task2 = new RplTask();
	RplTask* task3 = new RplTask();


	list.add(task1);
	list.add(task2);
	list.add(task3);

	EXPECT_EQ(list.get(0), task1);
	EXPECT_EQ(list.get(1), task2);
	EXPECT_EQ(list.get(2), task3);
	
	//delete task1;
	//delete task2;
	//delete task3;
}

/*
	Test get index method with an empty list, should return -1
*/
TEST(GetIndexTest, GetIndexWithEmptyList){
	TaskLinkedList list;
	RplTask* task1 = new RplTask();
	EXPECT_EQ(list.getIndex(task1), -1);
}

/*
	Test the get index method in a non-empty list
*/
TEST(GetIndexTest, GetIndexWithNonEmptyList){
	TaskLinkedList list;
	
	RplTask* task1 = new RplTask();
	RplTask* task2 = new RplTask();
	RplTask* task3 = new RplTask();

	list.add(task1);
	list.add(task2);
	list.add(task3);

	EXPECT_EQ(list.getIndex(task1),0);
	EXPECT_EQ(list.getIndex(task2),1);
	EXPECT_EQ(list.getIndex(task3),2);

	//delete task1;
	//delete task2;
	//delete task3;
}
/*
	Test contains method for an non empty list
*/
TEST(ContainsTest, ContainsTestNonEmptyList){
	TaskLinkedList list;
	
	RplTask* task1 = new RplTask();
	RplTask* task2 = new RplTask();
	RplTask* task3 = new RplTask();

	list.add(task1);
	list.add(task2);

	EXPECT_EQ(list.contains(task1), true);
	EXPECT_EQ(list.contains(task2), true);
	EXPECT_EQ(list.contains(task3), false);

	//delete task1;
	//delete task2;
	//delete task3;
}
