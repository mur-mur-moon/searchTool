#include "testMetrics.h"

#include<iostream>
using namespace std;
//------------------------------------------------------------------------------
TestMetrics::TestMetrics () : M(255) {}
//------------------------------------------------------------------------------
void TestMetrics::PerformAll()
{
	for(int i = 0; i<=10;i++)
		PerfomTests (i);
}
//------------------------------------------------------------------------------
void TestMetrics::PerfomTests (int k)
{
	TwoEquelStrings_ret_0 (k);
	OneTransposition_ret_1 (k);
	Two_Insertions_ret_2 (k);
	Two_Deletions_ret_2 (k);
	Is_Prefix_ret_0 (k);
	Is_Postfix_ret_0 (k);
	Is_Suffix_ret_0 (k);
	Suffix_with_mistakes_ret_1 (k);
	Suffix_with_mistakes_ret_2 (k);
	Is_Suffix_with_long_prefix_ret_0 (k);
	Is_Suffix_with_long_prefix_ret_1 (k);
	Str_To_Find_Is_Longer_ret_7 (k);
	Str_To_Find_Is_Longer_ret_5 (k);
	General_ret_2 (k);
	General_ret_1 (k);
}
//------------------------------------------------------------------------------
void TestMetrics::TwoEquelStrings_ret_0 (int k)
{
	string S1 = "тесто";
	string S2 = "тесто";
	int actual = M.getDistance(S1,S2, k);
	int expected = 0;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoEquelStrings_ret_0 " << "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::OneTransposition_ret_1 (int k)
{
	string S1 = "етсто";
	string S2 = "тесто";
	int actual = M.getDistance(S1,S2, k);
	int expected = 1;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! OneTransposition_ret_1 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Two_Insertions_ret_2 (int k)
{
	string S1 = "ткестко";
	string S2 = "тесто";
	int actual = M.getDistance(S1,S2, k);
	int expected = 2;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Two_Insertions_ret_2 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Two_Deletions_ret_2 (int k)
{
	string S1 = "тесто";
	string S2 = "теоo";
	int actual = M.getDistance(S1,S2, k);
	int expected = 2;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Two_Deletions_ret_2 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Is_Prefix_ret_0 (int k)
{
	string S1 = "тестомес";
	string S2 = "тес";
	int actual = M.getDistance(S1,S2, k);
	int expected = 0;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Is_Prefix_ret_0 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Is_Postfix_ret_0 (int k)
{
	string S1 = "тестомес";
	string S2 = "омес";
	int actual = M.getDistance(S1,S2, k);
	int expected = 0;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Is_Postfix_ret_0 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Is_Suffix_ret_0 (int k)
{
	string S1 = "тестопаровоз";
	string S2 = "паров";
	int actual = M.getDistance(S1,S2, k);
	int expected = 0;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Is_Suffix_ret_0 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Suffix_with_mistakes_ret_1 (int k)
{
	string S1 = "тестопаровоз";
	string S2 = "пров";
	int actual = M.getDistance(S1,S2, k);
	int expected = 1;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Suffix_with_mistakes_ret_1 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Suffix_with_mistakes_ret_2 (int k)
{
	string S1 = "тестопаровоз";
	string S2 = "апровд";
	int actual = M.getDistance(S1,S2, k);
	int expected = 2;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Suffix_with_mistakes_ret_2 "<< "k = " << k ;;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Is_Suffix_with_long_prefix_ret_0 (int k)
{
	string S1 = "тестопаровоз";
	string S2 = "оз";
	int actual = M.getDistance(S1,S2, k);
	int expected = 0;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Is_Suffix_with_long_prefix_ret_0 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Is_Suffix_with_long_prefix_ret_1 (int k)
{
	string S1 = "тестопаровоз";
	string S2 = "озр";
	int actual = M.getDistance(S1,S2, k);
	int expected = 1;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Is_Suffix_with_long_prefix_ret_1 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Str_To_Find_Is_Longer_ret_7 (int k)
{
	string S1 = "кот";
	string S2 = "переезд";
	int actual = M.getDistance(S1,S2, k);
	int expected;
	3 < 7 - k ? expected = k + 1 : expected = 7;

	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Str_To_Find_Is_Longer_ret_7 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::Str_To_Find_Is_Longer_ret_5 (int k)
{
	string S1 = "кее";
	string S2 = "переезд";
	int actual = M.getDistance(S1,S2, k);
	int expected;
	3 < 7 - k ? expected = k + 1 : expected = 5;

	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! Str_To_Find_Is_Longer_ret_5 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::General_ret_2 (int k)
{
	string S1 = "Д/С № 94 Московская Ирина Владимировна";
	string S2 = "мирошни";
	int actual = M.getDistance(S1,S2, k);
	int expected = 2;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! General_ret_2 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestMetrics::General_ret_1 (int k)
{
	string S1 = "ДЮСШ Левченко Антон Викторович";
	string S2 = "Ливчен";
	int actual = M.getDistance(S1,S2, k);
	int expected = 1;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! General_ret_1 "<< "k = " << k ;
	cout << endl;
};
//------------------------------------------------------------------------------

