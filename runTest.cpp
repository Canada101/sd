
#include <iostream>
#include "UnitTests.cpp"

int main(){

	bool returnValue = 0;
	UnitTests ut ("unittest_output");

	bool result = ut.testHealth();
	if( result == false ){
		std::cerr << "testHealth test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testHealth passed" << std::endl;
	}

	return returnValue;
}
