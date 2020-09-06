#include "InsertSort.h"

std::uint64_t InsertSort::Predict(std::uint64_t n) {
	return 8*static_cast<std::uint64_t>(std::pow(n, 2));
}
