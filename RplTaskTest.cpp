#include <gtest/gtest.h>
#include "RplTask.h"
#include "RplTaskTest.h"

/*tests TODO:
* - check all statuses are set correctly
* - onStart, onResume, onPause, onLoop are called when intended
* - dependencies STOPPED before running task
* - 
*/

/*
	start, process, pause, processs, resume, process a task; check statuses inbetween
*/
TEST(statusTest, pauseResume) {
	RplTask* task1 = (RplTask*)new TestTask();
	TaskStatus expected = CREATED;
	EXPECT_EQ(task1->getStatus(), expected) << "CREATED";

	task1->start();
	expected = STARTING;
	EXPECT_EQ(task1->getStatus(), expected) << "STARTING";

	task1->process(0); //needs to process once before pausing, so onStart() can run
	expected = RUNNING;
	EXPECT_EQ(task1->getStatus(), expected) << "RUNNING";

	task1->pause();
	expected = PAUSING;
	EXPECT_EQ(task1->getStatus(), expected) << "PAUSING";

	task1->process(0);
	expected = STOPPED;
	EXPECT_EQ(task1->getStatus(), expected) << "STOPPED";

	task1->resume();
	expected = RESUMING;
	EXPECT_EQ(task1->getStatus(), expected) << "RESUMING";

	task1->process(0);
	expected = RUNNING;
	EXPECT_EQ(task1->getStatus(), expected) << "RUNNING";
}


/*
	check onStart runs properly
*/
TEST(onTest, onStartTest) {
	TestTask* task1 = new TestTask();
	EXPECT_EQ(task1->i, 0);

	task1->start();
	task1->process(0);
	EXPECT_EQ(task1->i, 1);
}

/*
	check onLoop runs properly
*/
TEST(onTest, onLoopTest) {
	TestTask* task1 = new TestTask();
	EXPECT_EQ(task1->i, 0);

	task1->start();
	task1->process(0);
	task1->process(0);
	EXPECT_EQ(task1->i, 4);
}

/*
	check onPause runs properly
*/
TEST(onTest, onPauseTest) {
	TestTask* task1 = new TestTask();
	EXPECT_EQ(task1->i, 0);

	task1->start();
	task1->process(0);
	task1->pause();
	task1->process(0);
	EXPECT_EQ(task1->i, 3);
}

/*
	check onResume runs properly
*/
TEST(onTest, onResumeTest) {
	TestTask* task1 = new TestTask();
	EXPECT_EQ(task1->i, 0);

	task1->start();
	task1->process(0);
	task1->pause();
	task1->process(0);
	task1->resume();
	task1->process(0);
	EXPECT_EQ(task1->i, 2);
}
