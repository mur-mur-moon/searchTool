#include "fsFuzzySearch.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;
using namespace FS;
//------------------------------------------------------------------------------
Metrics::Metrics(int maxLength) : MaxDist (2*1000000)
{
	currentRow.resize      (maxLength + 1);
	previousRow.resize     (maxLength + 1);
	transpositionRow.resize(maxLength + 1);
}
//------------------------------------------------------------------------------

int Metrics::getDistance(const std::string & str, const std::string & prefix, int max)
{
		int stringLength = str.length();
		int prefixLength = prefix.length();
		// если ошибочно передано отриц. расстояние
		if (max < 0) max = prefixLength;

		if (prefixLength == 0)	return 0;
		else if (stringLength == 0) return prefixLength;

		if (stringLength < prefixLength - max) return max + 1;

		if (prefixLength > currentRow.size()) {
			currentRow.resize      (prefixLength + 1);
			previousRow.resize     (prefixLength + 1);
			transpositionRow.resize(prefixLength + 1);
		}
		//цена вставки в начало префикса равна +1
		for (int i = 0; i <= prefixLength; i++)
			previousRow[i] = i;

		int distance = MaxDist;

		char lastStrCh = 0;
		for (int i = 1; i <= stringLength; i++) {
				char strCh = str[i - 1];
				//так как ищем подстроку, цена вставки в начало строки равна 0
				currentRow[0] = 0;

				int from = 1;
				int to   = prefixLength;

				char lastPrefixCh = 0;
				for (int j = from; j <= to; j++) {
						char prefixCh = prefix[j - 1];

						// вычисляем минимальную цену перехода в текущее состояние из предыдущих
						// среди удаления, вставки и замены соответственно
						int cost = prefixCh == strCh ? 0 : 1;
						int value = std::min(std::min(currentRow[j - 1] + 1, previousRow[j] + 1),
														 previousRow[j - 1] + cost);

						// если была транспозиция, учесть и её стоимость
						if (prefixCh == lastStrCh && strCh == lastPrefixCh)
								value = std::min(value, transpositionRow[j - 2] + cost);

						currentRow[j] = value;
						lastPrefixCh = prefixCh;
				}
				lastStrCh = strCh;

				if (currentRow[prefixLength] < distance)
						distance = currentRow[prefixLength];

				// transpositionRow = бывший previousRow, previousRow = бывший currentRow
				swap(transpositionRow, previousRow);
				swap(previousRow,currentRow);
		}
		return distance;
}
//==============================================================================
bool FuzzySearcher::FirstInSecond (const std::string & WhatToFind, const std::string & WhereToFind,
																	 int & dist)
{
	int k = WhatToFind.length() * MaxDistGrad;
	dist = M.getDistance(WhereToFind, WhatToFind, k);

	if (dist <= k)
		return true;

	return false;
}
//------------------------------------------------------------------------------



