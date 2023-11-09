#include <your_api_name_here/foo.h>
#include <your_api_name_here/bar.h>

#include <iostream>

int main(int argc, char** argv)
{
   your_api_name_here::foo_t foo;
   std::cout << foo.do_foo(7, "hi") << std::endl;

   your_api_name_here::foo_t foo2(foo);
   std::cout << foo.do_virtual(3.0, 4.0) << std::endl;

   your_api_name_here::bar_t bar;
   std::cout << bar.do_bar(2., "hello") << std::endl;

   return 0;
}

