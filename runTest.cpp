
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
	
	bool resultFour = ut.testArmor();
	if( resultOne == false ){
		std::cerr << "testArmor test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testArmor passed" << std::endl;
	}
		
	bool resultFive = ut.testSpeed();
	if( resultOne == false ){
		std::cerr << "testSpeed test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testSpeed passed" << std::endl;
	}


	bool resultTwo = ut.testInventory();
	if ( resultTwo == false){
		std:: cerr << "testInventory test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testInventory passed" << std::endl;
	}

	bool resultThree = ut.testInventoryTwo();
	if ( resultThree == false){
		std:: cerr << "testInventoryTwo test FAILED" << std::endl;
		returnValue = -1;
	} else {
		std::cout << "testInventoryTwo passed" << std::endl;
	}


	return returnValue;
}
