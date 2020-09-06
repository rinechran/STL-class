#include <iostream>
#include "MergeSort.h"
#include "InsertSort.h"
#include "include/CSVWriter.h"

int main()
{
	CSVWriter csvWriter(",");
	InsertSort insertSort;
	MergeSort mergeSort;
	for (int i = 2; i < 100; i < i++) {
		auto insertVal = insertSort.Predict(i);
		auto mergeVal = mergeSort.Predict(i);
		csvWriter.newRow() << i  << insertVal  << mergeVal;
		
	}
	csvWriter.writeToFile("data.csv");

}