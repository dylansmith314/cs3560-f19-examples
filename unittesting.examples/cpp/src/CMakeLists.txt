add_executable(main main.cc)

find_package(unofficial-curlpp CONFIG REQUIRED)
target_link_libraries(main PRIVATE unofficial::curlpp::curlpp)
