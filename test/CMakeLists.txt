project(googleTest)
## 启用测试支持
enable_testing()

# 查找 Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 创建测试可执行文件
add_executable(test_runner testJsonClass.cpp ../src/json.cpp ../src/json.h)
target_link_libraries(test_runner ${GTEST_LIBRARIES} pthread  GTest::gtest GTest::gtest_main)
# 注册测试
add_test(NAME test_runner COMMAND test_runner)