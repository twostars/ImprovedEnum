
namespace LetsTryRealCase
{

	class BaseClass
	{
	public:
		inline void BaseMethod() {};
		inline static void StaticBaseMethod() {};
	};


	class TestClass
	{
	public:

		// Enumeration 1.
		// Inline Subclass declaration of the enumeration:
		#define IMPROVED_ENUM_SUBCLASS // Whithout this line the enum cannot be defined inside the class
		#define IMPROVED_ENUM_NAME  SubClass
		#define IMPROVED_ENUM_LIST  ENUMITEM(Physics)		\
									ENUMITEM(Chemistry)		\
									ENUMITEM(Mathematics)	\
									ENUMITEM(Philosophy)	\
									ENUMITEM(History)
		#include <DefineImprovedEnum.h>


		// Enumeration 2.
		// Inline Subclass declaration of the enumeration:
		#define IMPROVED_ENUM_SUBCLASS_PARENT BaseClass // Subclass inherits from BaseClass
		#define IMPROVED_ENUM_NAME  MyClass
		#define IMPROVED_ENUM_LIST  ENUMITEM(Thing1)		\
									ENUMITEM(Thing2)
		#include <DefineImprovedEnum.h>


		void Run()
		{
			// Conversion to string and conversion to enum:
			SubClass::EnumType t = SubClass::Mathematics;
			std::string text = SubClass::Enum2FullString(t);
			t = SubClass::String2Enum("Philosophy");

			// Iteration:
			t = SubClass::FirstEnumItem();
			t = SubClass::NextEnumItem(t);
			t = SubClass::LastEnumItem();
			t = SubClass::PreviousEnumItem(t);

			// Count:
			int n = SubClass::NumberOfValidEnumItem();

			// Subclass inheritance:
			MyClass::EnumType m = MyClass::Thing2;
			MyClass::StaticBaseMethod();
			MyClass myObj;
			myObj.BaseMethod();
		}

	};

}


void SubclassTest()
{
	// With the right namespace:
	using namespace LetsTryRealCase;

	// Using the enum inside the class:
	TestClass MyTest;
	MyTest.Run();

	// Using the enum outside the class:
	TestClass::SubClass::EnumType t = TestClass::SubClass::Chemistry;
	std::string text = TestClass::SubClass::Enum2FullString(t);
	t = TestClass::SubClass::FullString2Enum("SubClass::Physics");
}


