#include <gtest/gtest.h>
#include "TopologicalSort.h"
#include "TopologicalSortTest.h"
#include <stdlib.h>
#include  <iostream>

using namespace std ; 


TEST(SortTest, EmptyGraph){
	Graph g;
	g.size = 0;
	TaskLinkedList sort = topologicalSort(g);
	ASSERT_EQ(sort.getSize(), 0) << "nonzero list returned"; 
}




TEST(SortTest, OneElement) {
	Graph g ;
	TaskLinkedList l ; 
	TaskLinkedList perm ;
	TaskLinkedList temp ;  
	RplTask* t1 = (RplTask*)new TestTask();

	TaskLinkedList labels ; 
	labels.add(t1) ;

	cout << t1 << endl ; 
	TaskLinkedList* graph = (TaskLinkedList *) malloc(1 * sizeof(TaskLinkedList));
	*graph = l ;

 

	g.labels = labels ;
	g.size = 1;
	g.graph = graph ;
	g.temporaryMarks = temp;
	g.permanentMarks = perm;

	TaskLinkedList output = topologicalSort(g) ;

	ASSERT_EQ(output.get(0),t1) << "Incorrect single element.";
	ASSERT_EQ(output.getSize(), 1) << "Size was incorrect.";
}



TEST(SortTest,OneList) {
	Graph g ; 
	TaskLinkedList l ;
	TaskLinkedList l2 ; 
	TaskLinkedList perm ;
	TaskLinkedList temp ; 

	TestTask * t1 = new TestTask() ;
	TestTask * t2 = new TestTask() ;
	l.add(t2) ;

	std::cout << t1 << " " << t2 << std::endl;

	TaskLinkedList labels ; 
	labels.add(t1) ;
	labels.add(t2) ;

	TaskLinkedList* graph = (TaskLinkedList *) malloc(2 * sizeof(TaskLinkedList));
	*graph = l ; 
	*(graph + 1) = l2 ;

 

	g.labels = labels ;
	g.size = 2;
	g.graph = graph ;
	g.temporaryMarks = temp;
	g.permanentMarks = perm;

	TaskLinkedList output = topologicalSort(g) ;

	ASSERT_EQ(output.getSize(), 2) << "Size was incorrect.";

	
	cout <<"Output of test: " ;
	for (int i = 0 ; i < 2 ; ++i) {
		std::cout << output.get(i) <<  " " ;
	}

}




TEST(SortTest, TwoLists){
	Graph g ; 
	TaskLinkedList l1 ;
	TaskLinkedList l2 ;
	TaskLinkedList l3 ;
	TaskLinkedList l4 ; 
	TaskLinkedList perm ;
	TaskLinkedList temp ;


	RplTask* t1 = new TestTask();
	RplTask* t2 = new TestTask();
	RplTask* t3 = new TestTask();
	RplTask * t4 = new TestTask() ;
	
	
	l1.add(t2) ;
	l2.add(t4) ;
	

	std::cout << t1 << " " << t2 << " " << t3 << " " << t4 << std::endl;

	TaskLinkedList labels ;


	labels.add(t1);
	labels.add(t2);
	labels.add(t3);
	labels.add(t4);
	

	TaskLinkedList::Node * cur  = labels.head ;


	
	TaskLinkedList* graph = (TaskLinkedList *) malloc(4 * sizeof(TaskLinkedList));
	

	*graph = l1;
	*(graph + 1) = l3;
	*(graph + 2) = l2;
	*(graph + 3) = l4;
	


	g.labels = labels ;
	g.size = 4 ;
	g.graph = graph ;
	g.temporaryMarks = temp;
	g.permanentMarks = perm;
	
	TaskLinkedList output = topologicalSort(g) ;


	ASSERT_EQ(output.getSize(), 4) << "Size was incorrect.";

	std::cout << "Output values of tests: " ;
	for (int i = 0 ; i < 4 ; ++i) {
		std::cout << " " << output.get(i) ;
	}
}

TEST(SortTest, ThreeLists){
	Graph g ; 
	TaskLinkedList l1 ;
	TaskLinkedList l2 ; 
	TaskLinkedList l3 ; // l3 is the list for t2, which will have 1 node in it (t3)
	TaskLinkedList l4 ; // l3 is the list for t5, which will have 1 node in it (t6)
	TaskLinkedList emptyList ; // This list is for the nodes at the end of the list
 
	TaskLinkedList perm ;
	TaskLinkedList temp ;


	RplTask* t1 = new TestTask();
	RplTask* t2 = new TestTask();
	RplTask* t3 = new TestTask();
	RplTask * t4 = new TestTask() ;
	RplTask * t5 = new TestTask() ;
	RplTask * t6 = new TestTask() ;
	
	
	l1.add(t2) ;
	l1.add(t3) ;
	l2.add(t5) ;
	l2.add(t6) ;

	l3.add(t3);
	l4.add(t6) ;
	

	std::cout << t1 << " " << t2 << " " << t3 << " " << t4 << " " << t5 << " " << t6 << std::endl;

	TaskLinkedList labels ;


	labels.add(t1);
	labels.add(t2);
	labels.add(t3);
	labels.add(t4);
	labels.add(t5);
	labels.add(t6);
	
	TaskLinkedList* graph = (TaskLinkedList *) malloc(6 * sizeof(TaskLinkedList));
	
	*graph = l1;
	*(graph + 1) = l3;
	*(graph + 2) = emptyList ; 
	*(graph + 3) = l2 ; 
	*(graph + 4) = l4 ; 
	*(graph + 5) = emptyList ; 
	


	g.labels = labels ;
	g.size = labels.getSize() ;
	g.graph = graph ;
	g.temporaryMarks = temp;
	g.permanentMarks = perm;
	
	TaskLinkedList output = topologicalSort(g) ;


	ASSERT_EQ(output.getSize(), 6) << "Size was incorrect.";

	std::cout << "Output values of tests: " ;
	for (int i = 0 ; i < 6 ; ++i) {
		std::cout << " " << output.get(i) ;
	}
}


