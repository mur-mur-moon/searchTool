#pragma once

#include "fsFuzzySearch.h"

class TestMetrics
{
public:
		TestMetrics ();
		void PerformAll();
private:
		FS::Metrics M;
		void PerfomTests (int k);
		void TwoEquelStrings_ret_0 (int k);
		void OneTransposition_ret_1 (int k);
		void Two_Insertions_ret_2 (int k);
		void Two_Deletions_ret_2 (int k);
		void Is_Prefix_ret_0 (int k);
		void Is_Postfix_ret_0 (int k);
		void Is_Suffix_ret_0 (int k);
		void Suffix_with_mistakes_ret_1 (int k);
		void Suffix_with_mistakes_ret_2 (int k);
		void Is_Suffix_with_long_prefix_ret_0 (int k);
		void Is_Suffix_with_long_prefix_ret_1 (int k);
		void Str_To_Find_Is_Longer_ret_7 (int k);
		void Str_To_Find_Is_Longer_ret_5 (int k);
		void General_ret_2 (int k);
		void General_ret_1 (int k);
};