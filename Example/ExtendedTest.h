
// Declaration of the base enum (Fruit):
#define IMPROVED_ENUM_NAME  Fruit
#define IMPROVED_ENUM_FILE "Fruit.h"
#include <DefineImprovedEnum.h>

// Declaration of the extended enum (MyFruit inherits from Fruit, extended with NewFruit):
#define IMPROVED_ENUM_NAME  MyFruit
#define IMPROVED_ENUM_FILE "NewFruit.h"
#define IMPROVED_ENUM_INHERITED_NAME  Fruit
#define IMPROVED_ENUM_INHERITED_FILE "Fruit.h"
#include <DefineImprovedEnum.h>


void eat(Fruit::EnumType fruit) {}; // Accepts only the base type
void consume(MyFruit::EnumType myfruit) {}; // Accepts only the extended type

void ExtendedTest()
{
	// Declarations:
	Fruit::EnumType fruitAux, fruit;
	MyFruit::EnumType myfruitAux, myfruit, newfruit;

	// Direct assignments:
	fruit    = Fruit::Orange; // OK
	myfruit  = MyFruit::Orange; // OK
	newfruit = MyFruit::Apple; // OK

	// Conversions to extended enum:
	myfruitAux = MyFruit::Inherited2Enum(fruit); // OK
	myfruitAux = MyFruit::Inherited2Enum(myfruit); // OK
	myfruitAux = MyFruit::Inherited2Enum(newfruit); // OK

	// Conversions to base enum:
	fruitAux = MyFruit::Enum2Inherited(fruit); // OK
	fruitAux = MyFruit::Enum2Inherited(myfruit); // OK
	fruitAux = MyFruit::Enum2Inherited(newfruit); // returns NotValidEnumItem

	// The following compiles:
	eat(fruit); // OK
	eat(MyFruit::Enum2Inherited(myfruitAux)); // Take care: possible NotValidEnumItem
	consume(myfruit); // OK
	consume(MyFruit::Inherited2Enum(fruit)); // OK

	// Partial iteration:
	myfruitAux = MyFruit::FirstExtendedEnumItem();
	myfruitAux = MyFruit::NextInheritedEnumItem(newfruit);
	myfruitAux = MyFruit::LastInheritedEnumItem();
	myfruitAux = MyFruit::PreviousExtendedEnumItem(newfruit);

	// Partial count:
	int n = MyFruit::NumberOfInheritedValidEnumItem();
	int m = MyFruit::NumberOfExtendedValidEnumItem();
}

