
// Declaration of the enumeration:
#define IMPROVED_ENUM_NAME  Day        // Input parameter: the name of the enumeration
#define IMPROVED_ENUM_FILE "DayEnum.h" // Input parameter: the file with the enum items
#include <DefineImprovedEnum.h>        // Batch file of preprocessing commands (uses the input parameters above)


void Test()
{
	// Conversion to string and conversion to enum:
	Day::EnumType t = Day::Monday;
	std::string text = Day::Enum2String(t);
	t = Day::String2Enum("Friday");

	// Iteration:
	t = Day::FirstEnumItem();
	t = Day::NextEnumItem(t);
	t = Day::LastEnumItem();
	t = Day::PreviousEnumItem(t);

	// Count:
	int n = Day::NumberOfValidEnumItem();
}

// At the end of Test() the value of t is Friday and the value of text is "Monday".

