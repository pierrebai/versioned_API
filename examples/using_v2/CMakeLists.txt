add_executable(using_v2
   using_v2.cpp
)

target_link_libraries(using_v2 PUBLIC
   your_api_name_here
)

target_compile_features(using_v2 PUBLIC
   cxx_std_20
)

target_include_directories(using_v2 PUBLIC
   your_api_name_here
)
