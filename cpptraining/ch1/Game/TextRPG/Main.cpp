#include <iostream>
#include "Core.h"

using namespace std;


int main() {
	if (!GET_SINGLE(CCore)->Init()) {
		DESTROY_SINGLE(CCore);
		return 0;
	}

	GET_SINGLE(CCore)->Run();
	DESTROY_SINGLE(CCore);

	return 0;
}