
#include <iostream>
#include "UnitTests.cpp"

int main(){

	UnitTests ut ("unittest_output");

	bool result = ut.testHealth();
	if( result == false ){
		std::cerr << "testHealth test FAILED" << std::endl;
	} else {
		std::cout << "testHealth passed" << std::endl;
	}

	return 0;

}
