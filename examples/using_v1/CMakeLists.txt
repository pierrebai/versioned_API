add_executable(using_v1
   using_v1.cpp
)

add_compile_definitions(YOUR_API_NAME_HERE_VERSION=v1)

target_link_libraries(using_v1 PUBLIC
   your_api_name_here
)

target_compile_features(using_v1 PUBLIC
   cxx_std_20
)

target_include_directories(using_v1 PUBLIC
   your_api_name_here
)
