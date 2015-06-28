#include "TestFuzzySearcher.h"
#include<iostream>
using namespace std;
//------------------------------------------------------------------------------
void TestFuzzySearcher::PerformAll()
{
	PerfomTests ();
}
//------------------------------------------------------------------------------
void TestFuzzySearcher::PerfomTests ()
{
	TwoEquelStrings_5_ret_True ();
	TwoEquelStrings_3_ret_True ();
	TwoDifStrings_3_ret_False  ();
	TwoDifStrings_4_ret_True   ();
	TwoDifStrings_4_ret_False  ();
	TwoDifStrings_8_ret_False  ();
	TwoDifStrings_8_ret_True   ();
	General_1_ret_True ();
}
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoEquelStrings_5_ret_True ()
{
	string S1 = "тесто";
	string S2 = "тесто";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = true;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoEquelStrings_5_ret_True " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoEquelStrings_3_ret_True ()
{
	string S1 = "wer";
	string S2 = "wer";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = true;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoEquelStrings_3_ret_True " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoDifStrings_3_ret_False ()
{
	string S1 = "wer";
	string S2 = "rerty";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = false;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoDifStrings_3_ret_False  " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoDifStrings_4_ret_True ()
{
	string S1 = "wert";
	string S2 = "rerty";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = true;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoDifStrings_4_ret_True  " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoDifStrings_4_ret_False ()
{
	string S1 = "werw";
	string S2 = "rerty";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = false;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoDifStrings_4_ret_False  " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoDifStrings_8_ret_False ()
{
	string S1 = "tratapop";
	string S2 = "rerty";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = false;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoDifStrings_8_ret_False   " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::TwoDifStrings_8_ret_True ()
{
	string S1 = "tratapop";
	string S2 = "tratapr";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = true;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! TwoDifStrings_8_ret_True    " ;
	cout << endl;
};
//------------------------------------------------------------------------------
void TestFuzzySearcher::General_1_ret_True ()
{
	string S1 = "Ливчен";
	string S2 = "ДЮСШ Левченко Антон Викторович";
	bool actual   = FS.FirstInSecond(S1,S2,distToReturn);
	bool expected = true;
	actual==expected ? cout << "OK!" :
	 cout << actual << " ERROR! General_1_ret_True    " << distToReturn;
	cout << endl;
};
//------------------------------------------------------------------------------
