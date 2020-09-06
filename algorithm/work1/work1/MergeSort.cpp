#include "MergeSort.h"

std::uint64_t MergeSort::Predict(std::uint64_t n) {
	return static_cast<std::uint64_t>(64 * n * (logN(n, 2)));
}
