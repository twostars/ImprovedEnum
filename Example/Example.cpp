// Example.cpp : Defines the entry point for the console application.
//

#include "Test.h"
#include "InlineTest.h"
#include "SubclassTest.h"
#include "ExtendedTest.h"


int main(int argc, char* argv[])
{
	Test();

	InlineTest();

	ExtendedTest();

	SubclassTest();

	return 0;
}

