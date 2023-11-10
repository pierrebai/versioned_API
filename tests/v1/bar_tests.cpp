#include <CppUnitTest.h>

#include <your_api_name_here/v1/bar.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace your_api_name_here::v1::tests
{		
   TEST_CLASS(bar_tests)
	{
	public:
		TEST_METHOD(default_bar_test)
		{
         bar_t bar;

         Assert::AreEqual(bar.get_name(), std::string(""));
         Assert::AreEqual(bar.get_foo().get_name(), std::string(""));
      }

		TEST_METHOD(named_bar_test)
		{
         bar_t bar("1");

         Assert::AreEqual(bar.get_name(), std::string("1"));
         Assert::AreEqual(bar.get_foo().get_name(), std::string("1"));

         bar.set_name("2");

         Assert::AreEqual(bar.get_name(), std::string("2"));
         Assert::AreEqual(bar.get_foo().get_name(), std::string("2"));
      }

		TEST_METHOD(copy_bar_test)
		{
         bar_t bar("1");
         bar_t bar_copy(bar);

         Assert::AreEqual(bar.get_name(), std::string("1"));
         Assert::AreEqual(bar_copy.get_name(), std::string("1"));

         bar.set_name("2");

         Assert::AreEqual(bar.get_name(), std::string("2"));
         Assert::AreEqual(bar_copy.get_name(), std::string("2"));
      }
   };
}
