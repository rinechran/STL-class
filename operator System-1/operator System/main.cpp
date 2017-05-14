#include <algorithm>
#include "Process.h"
#include "RR.hpp"
#include "SJF.hpp"
#include "Feeback.hpp"




int main() {
	SJF b;
	b.run();
	Feeback<2, 3> a;
	a.run();

}