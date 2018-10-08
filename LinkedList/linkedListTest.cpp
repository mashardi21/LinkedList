#include <iostream>
#include <string>

#define CATCH_CONFIG_RUNNER // This is needed to utilize the catch2 testing framework
#include <catch.hpp>

int main(int argc, char * argv[]) {

	int result = Catch::Session().run(argc, argv);

	system("PAUSE");
	return result;
}