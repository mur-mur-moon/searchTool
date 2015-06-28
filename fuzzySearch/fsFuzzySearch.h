#pragma once

#include <string>
#include <vector>

namespace FS
{
//------------------------------------------------------------------------------
	class Metrics
	/*
	** для двух строк - str и prefix -
	** вычисляет расстояние Дамерау-Левенштейна (расстояние редактирования) методом Вагнера-Фишера;
	** асимптотика : время - O(str.length()*prefix.length()), память - O( max(maxLength, prefix.length()) ).
	** int max - максимально допустимое количество операций редактирования
	** (вставка символа, замена символа, удаление символа, транспозация символов).
	*/
	{
	public:
		Metrics(int maxLength);
		int getDistance   (const std::string & str, const std::string & prefix, int max);
	private:
		std::vector <int> currentRow;
		std::vector <int> previousRow;
		std::vector <int> transpositionRow;
		const int MaxDist;
	};
//------------------------------------------------------------------------------
	class FuzzySearcher
	/*
	** Jпределяет, является ли расстояние между строками допустимым;
	** допустимое расстояние между строками
	** зависит от длины подстроки, которую ищем.
	**
	*/
	{
	private:
		const double MaxDistGrad;
		Metrics  M;
	public:
		FuzzySearcher() :  MaxDistGrad (1 / 4.0), M(255) {}
		bool FirstInSecond (const std::string & WhatToFind, const std::string & WhereToFind, int & dist);
	};
//------------------------------------------------------------------------------
}

