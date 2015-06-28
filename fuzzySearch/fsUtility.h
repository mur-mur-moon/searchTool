#pragma once

#include <string>
#include <vector>

#include <boost/unordered/unordered_map.hpp>

namespace fsUtility
{
	class AlphabetMaster
	/*
	** Хранит таблицу соответствий латинских букв кириллическим.
	** Определяет алфавит строки.
	** Конвертирует строку в кириллицу in place.
	*/
	{
	private:
		boost::unordered_map <char, char>  map;
	public:
		AlphabetMaster ();
		bool     IsLatin     (const std::string &s) ;
		void     ToCyrillic  (std::string &s) ;
	};

	//--------------------------------------------------------------------------
	/* Делит строку на слова, записывает их в вектор. */
	void SplitIntoWords (const std::string & s, char delim, std::vector <std::string> & words);
//------------------------------------------------------------------------------
}


