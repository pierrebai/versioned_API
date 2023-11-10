#pragma once

#include <atomic>

namespace your_api_name_here::implementation
{
   struct implementation_t
   {
      virtual ~implementation_t() = default;
      
      void reference_implementation() const { ++my_ref_count; }
      void forget_implementation() const { --my_ref_count; if (!my_ref_count) delete this; }

   private:
      mutable std::atomic<int> my_ref_count;
   };
}
