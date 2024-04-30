
#include <iostream>
#include "UnitTests.cpp"

int main(){

	bool returnValue = 0;
	UnitTests ut ("unittest_output");

	bool resultOne = ut.testHealth();
	if( resultOne == false ){
		std::cerr << "testHealth test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testHealth passed" << std::endl;
	}

	bool resultTwo = ut.testInventory();
	if ( resultTwo == false){
		std:: cerr << "testInventory test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testInventory passed" << std::endl;
	}

	return returnValue;
}
