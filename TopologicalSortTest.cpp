#include <gtest/gtest.h>
#include "TopologicalSort.h"
#include "TopologicalSortTest.h"
#include <stdlib.h>
#include  <iostream>

using namespace std;

TEST(SortTest, EmptyGraph){
	Graph g;
	g.size = 0;
	TaskLinkedList sort = topologicalSort(g);
	ASSERT_EQ(sort.getSize(), 0) << "nonzero list returned"; 
}

TEST(SortTest, TwoLists){
	Graph g ; 
	TaskLinkedList l1 ;
	TaskLinkedList l2 ;
	TaskLinkedList perm ;
	TaskLinkedList temp ;

	TestTask * t1 = new TestTask() ;
	TestTask * t2 = new TestTask() ;
	l1.add(t2) ;

	TestTask * t3 = new TestTask() ;
	TestTask * t4 = new TestTask() ; 
	l2.add(t4) ;

	std::cout << t1 << " " << t2 << " " << t3 << " " << t4 << std::endl;

	TaskLinkedList labels ;

	labels.add(t1);
	labels.add(t2);
	labels.add(t3);
	labels.add(t4);

	TaskLinkedList* graph = (TaskLinkedList *) malloc(4 * sizeof(TaskLinkedList));

	*graph = l1;
	*(graph + 2) = l2;


	g.labels = labels ;
	g.size = 4 ;
	g.graph = graph ;
	g.temporaryMarks = temp;
	g.permanentMarks = perm;

	TaskLinkedList output = topologicalSort(g) ;


	ASSERT_EQ(output.getSize(), 4) << "Size was incorrect.";

	
	
	for (int i = 0 ; i < 3 ; ++i) {
		std::cout << output.get(i) << std::endl;
	}

}

