
// Inline declaration of the enumeration:
#define IMPROVED_ENUM_NAME  MyDay
#define IMPROVED_ENUM_LIST  ENUMITEM(Sunday)    \
                            ENUMITEM(Monday)    \
                            ENUMITEM(Tuesday)   \
                            ENUMITEM(Wednesday) \
                            ENUMITEM(Thursday)  \
                            ENUMITEM(Friday)    \
                            ENUMITEM(Saturday)
#include <DefineImprovedEnum.h>


void InlineTest()
{
	// Conversion to string and conversion to enum:
	MyDay::EnumType t = MyDay::Monday;
	std::string text = MyDay::Enum2String(t);
	t = MyDay::String2Enum("Friday");

	// Iteration:
	t = MyDay::FirstEnumItem();
	t = MyDay::NextEnumItem(t);
	t = MyDay::LastEnumItem();
	t = MyDay::PreviousEnumItem(t);

	// Count:
	int n = MyDay::NumberOfValidEnumItem();
}

// At the end of InlineTest() the value of t is Friday and the value of text is "Monday".

