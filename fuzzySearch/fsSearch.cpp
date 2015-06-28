#include "fsSearch.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace fsUtility;
using namespace FS;
using namespace Precise_And_Fuzzy_Search;


//------------------------------------------------------------------------------
StrToFindMaster::StrToFindMaster (const string &StrToFind)
	: WordsQuanDefault(4), WrongLayout(false)
{
	ToFind = &StrToFind;

	words.reserve(WordsQuanDefault);
	SplitIntoWords(*ToFind, ' ', words);

	if ( AM.IsLatin(*ToFind))
	{
		WrongLayout = true;
		CyrillicCopy = *ToFind;
		AM.ToCyrillic (CyrillicCopy);
		boost::to_upper(CyrillicCopy);
	}
}
//------------------------------------------------------------------------------
const string * StrToFindMaster::GetStrToFind()
{
	return ToFind;
}
//------------------------------------------------------------------------------
MSP_Searcher::MSP_Searcher (const string &StrToFind)
	:  StrMaster (StrToFind), ResultsSizeDefault (16),
	Founds(false), FoundsWithMistakes(false)
{
	Matches.reserve(ResultsSizeDefault);
	if (StrMaster.WrongLayout) {
		Matches_If_WrongLayout.reserve(ResultsSizeDefault);
	}
	// По умолчанию результат будем искать среди точных совпадений.
	Result = &Matches;
}
//------------------------------------------------------------------------------
void MSP_Searcher::AddResult(mspFuz & mspFuz)
{
	Result->push_back(mspFuz);
}
//------------------------------------------------------------------------------
MSP_PreciseSearcher::MSP_PreciseSearcher (const string &StrToFind)
	: MSP_Searcher (StrToFind)
{
}
//------------------------------------------------------------------------------
bool MSP_PreciseSearcher::DoesMatch(const string & WhereToFind)
{
	bool res = false;

	if (WhereToFind.find(*StrMaster.GetStrToFind()) != WhereToFind.npos) {
		Result = &Matches;
		res = true;
	}
	else if (StrMaster.WrongLayout
		&& WhereToFind.find(StrMaster.CyrillicCopy) != WhereToFind.npos) {
			Result = &Matches_If_WrongLayout;
			res = true;
		}

	return res;
}
//------------------------------------------------------------------------------
void MSP_PreciseSearcher::GetResult()
{
	if (!Matches.empty()) { Result = &Matches; Founds = true;}
		// Для данной подстроки совпадений в базе не найдено.
		// Проверим, нет ли совпадений для подстроки, обращенной в кириллицу.
		else if (!Matches_If_WrongLayout.empty()) {
			Result = &Matches_If_WrongLayout;
			FoundsWithMistakes = true;
		 }
}
//------------------------------------------------------------------------------
MSP_FuzzySearcher::MSP_FuzzySearcher (const string & StrToFind)
	: MSP_Searcher (StrToFind)
{
	Matches_If_WrongLayout.reserve(ResultsSizeDefault);
}
//------------------------------------------------------------------------------
bool MSP_FuzzySearcher::DoesMatch(const string & StrWhereToFind)
{
	bool res = false;
	bool notFound = false;
	// Сумма стоимостей редактирования всех слов строки, которую ищем.
	int sumCost = 0;
	// Для каждого слова проверим, входит ли оно в строку.
	for(int i = 0; i < StrMaster.words.size();i++)
	{
		int cost = 0;
		if (FS.FirstInSecond(StrMaster.words[i],StrWhereToFind,cost)==true)
			 sumCost += cost;
		else {
		// Если расстояние между одним из слов и строкой больше допустимого,
		// прекращаем поиск.
			notFound = true;
			break;
		}
	}
	if (notFound == false) {
		if (sumCost==0)
			// Строка содержит все слова подстроки, которую ищем.
			Result = &Matches;
		else
			// Строка содержит слова подстроки с допустимым кол-вом несоответствий.
			Result = &Matches_If_Mistakes;

		res = true;
	}else {
		// Проверим, нет содержится ли подстрока, обращенная в кириллицу.
		if (StrMaster.WrongLayout) {
			if (StrWhereToFind.find(StrMaster.CyrillicCopy) != StrWhereToFind.npos)  {
				Result = &Matches_If_WrongLayout;
				res = true;
			}
		}
	}

	return res;
}
//------------------------------------------------------------------------------
void MSP_FuzzySearcher::GetResult()
{
	if (!Matches.empty())  {	Result = &Matches; Founds = true;}
		else if (!Matches_If_Mistakes.empty()) {
			Result = &Matches_If_Mistakes;
			FoundsWithMistakes = true;
		} else if (!Matches_If_WrongLayout.empty()) {
				Result = &Matches_If_WrongLayout;
				FoundsWithMistakes = true;
			}
}
//------------------------------------------------------------------------------

