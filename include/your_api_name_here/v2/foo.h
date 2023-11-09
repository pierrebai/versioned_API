#pragma once

#include <your_api_name_here/versioned.h>

#include <string>

namespace your_api_name_here::implementation
{
   struct foo_t;
}

namespace your_api_name_here::v2
{
   // Rules:
   //    - Derive from versioned_t<your-class>.
   //    - Declare current_implementation_t to be the implementation of the class.
   //    - All functions must not be inlined.
   //    - All data is kept in the implementation.
   //    - A private constructor to wrap an existing implementation.
   //    - Friend the versioned_t<your-class>.
   struct foo_t : versioned_t<foo_t>
   {
      using current_implementation_t = implementation::foo_t;

      foo_t();
      ~foo_t();

      foo_t(const foo_t& other);
      foo_t(foo_t&& other);

      foo_t& operator=(const foo_t& other);
      foo_t& operator=(foo_t&& other);

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
      foo_t(void* implementation, bool is_ref_counted);
      friend struct versioned_t<foo_t>;
   };
}
