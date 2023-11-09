#pragma once

#include <your_api_name_here/implementation/implementation.h>

#include <string>

namespace your_api_name_here::implementation
{
   struct foo_t : implementation_t
   {
      foo_t();
      ~foo_t();

      foo_t(const std::string& name);

      const std::string& get_name() const;
      void set_name(const std::string& name);

      int get_value() const;

      // Both of these functions changed in v2.

      // Add the count to the internal count and return the total.
      int do_foo(int count, const char* name);

      // Return x times 2 plus y.
      virtual double do_virtual(double x, double y);

   private:
      std::string my_name;
      int my_value = 0;
      double my_y = 0;
   };
}
