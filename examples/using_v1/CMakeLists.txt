add_executable(using_v1
   using_v1.cpp
)

target_link_libraries(using_v1 PUBLIC
   your_api_name_here
)

target_compile_features(using_v1 PUBLIC
   cxx_std_20
)

target_include_directories(using_v1 PUBLIC
   your_api_name_here
)
