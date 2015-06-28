#include "testMetrics.h"
#include "TestFuzzySearcher.h"
#include "fsUtility.h"
#include "fsSearch.h"

#include <iostream>


using namespace std;
using namespace fsUtility;

#pragma argsused
//---------------------------------------------------------------------------
void main()
{
	TestMetrics tM;
	tM.PerformAll();

	TestFuzzySearcher tFS;
	tFS.PerformAll();

}
//---------------------------------------------------------------------------
