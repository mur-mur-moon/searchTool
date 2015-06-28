#pragma once

#include "fsFuzzySearch.h"


class TestFuzzySearcher
{
public:
	TestFuzzySearcher () : distToReturn(0) {}
	void PerformAll();

private:
	FS::FuzzySearcher FS;
	int distToReturn;

	void PerfomTests ();
	void TwoEquelStrings_5_ret_True ();
	void TwoEquelStrings_3_ret_True ();
	void TwoDifStrings_3_ret_False ();
	void TwoDifStrings_4_ret_True ();
	void TwoDifStrings_4_ret_False ();
	void TwoDifStrings_8_ret_False ();
	void TwoDifStrings_8_ret_True ();
	void General_1_ret_True ();
};
