#include <iostream>
#include <cmath>
#include "MergeSort.h"
#include "InsertSort.h"
#include "include/CSVWriter.h"


template <class T>
std::uint64_t AlgorithmsPredict(int i ,T t) {
	return t(i);
}
int main()
{
	{
		CSVWriter csvWriter(",");
		InsertSort insertSort;
		MergeSort mergeSort;
		for (int i = 2; i < 100; i < i++) {
			auto insertVal = insertSort.Predict(i);
			auto mergeVal = mergeSort.Predict(i);
			csvWriter.newRow() << i << insertVal << mergeVal;

		}
		csvWriter.writeToFile("data1.csv");
	}
	{
		CSVWriter csvWriter(",");
		for (int i = 2; i < 100; i < i++) {
			auto algor1 = AlgorithmsPredict(i, [](int i) {
				return 100 * std::pow(i, 2);
				});
			auto algor2 = AlgorithmsPredict(i, [](int i) {
				return std::pow(2, i);
				});

			csvWriter.newRow() << i << algor1 << algor2;

		}
		csvWriter.writeToFile("data2.csv");

	}

}