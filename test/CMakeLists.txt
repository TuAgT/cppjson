
## 启用测试支持
enable_testing()

# 查找 Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



# 创建测试可执行文件
add_executable(test_runner testJsonClass.cpp)
target_include_directories(test_runner PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(test_runner ${GTEST_LIBRARIES} pthread  GTest::gtest GTest::gtest_main)
target_link_libraries(test_runner json)
# 注册测试
add_test(NAME test_runner COMMAND test_runner)