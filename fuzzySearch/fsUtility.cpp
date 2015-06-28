#include "fsUtility.h"

#include <string>
#include <vector>

using namespace fsUtility;
using namespace std;
//------------------------------------------------------------------------------
AlphabetMaster::AlphabetMaster ()
{
	map['Q'] = 'Й';
	map['W'] = 'Ц';
	map['E'] = 'У';
	map['R'] = 'К';
	map['T'] = 'Е';
	map['Y'] = 'Н';
	map['U'] = 'Г';
	map['I'] = 'Ш';
	map['O'] = 'Щ';
	map['P'] = 'З';
	map['['] = 'Х';
	map[']'] = 'Ъ';
	map['A'] = 'Ф';
	map['S'] = 'Ы';
	map['D'] = 'В';
	map['F'] = 'А';
	map['G'] = 'П';
	map['H'] = 'Р';
	map['J'] = 'О';
	map['K'] = 'Л';
	map['L'] = 'Д';
	map[';'] = 'Ж';
	map['\''] = 'Э';
	map['Z'] = 'Я';
	map['X'] = 'Ч';
	map['C'] = 'С';
	map['V'] = 'М';
	map['B'] = 'И';
	map['N'] = 'Т';
	map['M'] = 'Ь';
	map[','] = 'Б';
	map['.'] = 'Ю';
	map['`'] = 'Ё';
}
//------------------------------------------------------------------------------
void AlphabetMaster::ToCyrillic (string &s)
/*
** Заменяет латинские символы кириллицей.
** Без анализа кодов клавиш -
** соответствие сохранено в хеше.
*/
{
	for (size_t i = 0; i < s.length(); i++) {
		char ch = s[i];
		s[i]    = map [ch];
	}
}
//------------------------------------------------------------------------------
bool AlphabetMaster::IsLatin (const string &s)
/*
** определяет, набрано ли слово латиницей,
** в лоб - по наличию первого символа в хеш-таблице :
** GetKeyboardLayout не подходит, так как запрос нередко
** может быть набран латиницей при русской раскладке
** (например, в режиме удаленного доступа)
*/
{
	if (s.length() > 0)
	{
		char ch = s[0];
		if (map.find(ch) != map.end())
			return true;
	}
	return false;
};
//------------------------------------------------------------------------------
void fsUtility::SplitIntoWords (const std::string & s, char delim, std::vector <std::string> & words)
/*
** разбивает строку на слова, символ конца слова - delim
*/
{
	int begin = 0, end = 0;
	//  find_first_not_of (const string& str, size_t pos ),
	//  где pos индекс символа строки, с которого следует начать поиск
	while ((begin = s.find_first_not_of(delim, end)) != s.npos) {
		end = s.find_first_of(delim, begin);
		words.push_back(s.substr(begin, end - begin));
		begin = end;
	}
}
//------------------------------------------------------------------------------
