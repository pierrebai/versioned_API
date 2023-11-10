#pragma once

#include <your_api_name_here/versioned.h>
#include <your_api_name_here/v1/foo.h>

#include <string>

namespace your_api_name_here::implementation
{
   struct bar_t;
}

namespace your_api_name_here::v1
{
   // Rules:
   //    - Derive from versioned_t<your-class>.
   //    - Declare current_implementation_t to be the implementation of the class.
   //    - All functions must not be inlined.
   //    - All data is kept in the implementation.
   //    - A private constructor to wrap an existing implementation.
   //    - Friend the versioned_t<your-class>.
   struct bar_t : versioned_t<bar_t>
   {
      using current_implementation_t = implementation::bar_t;

      bar_t();
      ~bar_t();

      bar_t(const bar_t& other);
      bar_t(bar_t&& other);

      bar_t& operator=(const bar_t& other);
      bar_t& operator=(bar_t&& other);

      bar_t(const std::string& name);

      const std::string& get_name() const;
      void set_name(const std::string& name);

      foo_t get_foo();

      // Return x squared mutiplied by the foo do_virtual.
      double do_bar(double x, const char* name);

   private:
      bar_t(void* implementation, bool is_ref_counted);
      friend struct versioned_t<bar_t>;
   };
}
