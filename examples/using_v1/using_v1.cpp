#include <your_api_name_here/foo.h>
#include <your_api_name_here/bar.h>

#include <iostream>

int main(int argc, char** argv)
{
   your_api_name_here::foo_t foo("1");
   std::cout << foo.do_foo(7) << std::endl;

   your_api_name_here::foo_t foo2(foo);
   foo2.set_name("2");
   std::cout << foo2.do_virtual(3.) << std::endl;
   std::cout << foo2.do_virtual(1.) << std::endl;

   std::cout << foo.do_virtual(4.) << std::endl;

   foo2 = foo;
   foo2.set_name("2");
   std::cout << foo2.do_virtual(1.) << std::endl;

   your_api_name_here::bar_t bar("3");
   std::cout << bar.do_bar(2., "hello") << std::endl;

   return 0;
}

