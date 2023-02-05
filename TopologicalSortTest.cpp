#include <gtest/gtest.h>
#include "TopologicalSort.h"


TEST(SortTest, EmptyGraph){
	Graph g;

	ASSERT_EQ(topologicalSort(g).getSize(), 0) << "nonzero list returned"; 
}

