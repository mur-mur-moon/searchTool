#pragma once

#include "fsUtility.h"
#include "fsFuzzySearch.h"

#include <string>
#include <vector>


namespace Precise_And_Fuzzy_Search
{
	class StrToFindMaster
	/*
	** Для подстроки хранит:
	** -её разбиение на слова,
	** -результат её набора в русской раскладке клавиатуры.
	*/
	{
	public:
		explicit StrToFindMaster (const std::string &StrToFind);
		const std::string * GetStrToFind();

		std::vector <std::string> words;
		std::string CyrillicCopy;
		bool WrongLayout;
	private:
		const  int WordsQuanDefault;
		const  std::string * ToFind;
		fsUtility::AlphabetMaster AM;
	};
	//--------------------------------------------------------------------------
	struct mspFuz
	/*
	** 1 результат запроса к базе
	*/
	{
		unsigned short k;
		unsigned short bz;
		unsigned long p1;
		unsigned long p2;
		unsigned long p3;
		unsigned long p4;
		unsigned long p5;
		unsigned long sp;
		char n[200];
	};
	//--------------------------------------------------------------------------
	class MSP_Searcher
	/*
	** Абстрактный класс для поиска подстроки в базе.
	** Знает результат запроса.
	** Классифицирует совпадения по степени точности, сохраняет их в контейнерах.
	*/
	{
	public:
		explicit MSP_Searcher (const std::string &StrToFind);
		void AddResult(mspFuz & mspFuz);

		virtual bool DoesMatch(const std::string & WhereToFind)  = 0;
		virtual void GetResult() = 0;
		virtual ~MSP_Searcher() {};

		bool Founds;
		bool FoundsWithMistakes;
		std::vector <mspFuz> * Result;
	protected:
		StrToFindMaster StrMaster;
		const int ResultsSizeDefault;
		std::vector <mspFuz> Matches;
		std::vector <mspFuz> Matches_If_WrongLayout;

	};
	//--------------------------------------------------------------------------
	class MSP_PreciseSearcher : public MSP_Searcher
	/*
	** Конкретный тип поисковика:
	** осуществляет точный поиск подстроки в базе.
	** Если необходимо, конвертирует подстроку в кириллицу.
	*/
	{
	public:
		explicit MSP_PreciseSearcher (const std::string &StrToFind);
		bool DoesMatch(const std::string & WhereToFind);
		void GetResult();

	};
	//--------------------------------------------------------------------------
	class MSP_FuzzySearcher : public MSP_Searcher
	/*
	** Конкретный тип поисковика:
	** осуществляет "нечеткий поиск" подстроки в базе.
	** Если необходимо, конвертирует подстроку в кириллицу;
	** но в этом случае ищет уже точную подстроку.
	*/
	{
	public:
		explicit MSP_FuzzySearcher (const std::string &StrToFind);
		bool DoesMatch(const std::string & WhereToFind);
		void GetResult();
	private:
		FS::FuzzySearcher FS;
		std::vector <mspFuz> Matches_If_Mistakes;
	};

}


