#include <CppUnitTest.h>

#include <your_api_name_here/v1/foo.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace your_api_name_here::v1::tests
{		
   TEST_CLASS(foo_tests)
	{
	public:
		TEST_METHOD(default_foo_test)
		{
         foo_t foo;

         Assert::AreEqual(foo.get_name(), std::string(""));
      }

		TEST_METHOD(named_foo_test)
		{
         foo_t foo("7");

         Assert::AreEqual(foo.get_name(), std::string("7"));

         foo.set_name("3");

         Assert::AreEqual(foo.get_name(), std::string("3"));
      }
   };
}
