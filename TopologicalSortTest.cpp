#include <gtest/gtest.h>
#include "TopologicalSort.h"
#include "TopologicalSortTest.h"


TEST(SortTest, EmptyGraph){
	Graph g;
	g.size = 0;
	TaskLinkedList sort = topologicalSort(g);
	ASSERT_EQ(sort.getSize(), 0) << "nonzero list returned"; 
}

