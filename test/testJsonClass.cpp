#include <gtest/gtest.h>
#include "../src/Json.h"

// 测试构造函数
TEST(JsonTest, ConstructorTest) {
    // 测试整数构造函数
    Json intJson(42);
    EXPECT_EQ(intJson.toString(), "42");

    // 测试浮点数构造函数
    Json floatJson(3.14f);
    EXPECT_EQ(floatJson.toString(), "3.140000");

    // 测试字符串构造函数
    Json stringJson(std::string("hello"));
    EXPECT_EQ(stringJson.toString(), "hello");

    // 测试布尔构造函数
    Json boolJson(true);
    EXPECT_EQ(boolJson.toString(), "1");

    // 测试数组构造函数
    // std::vector<Json> arr = {Json(1), Json("test")};
    // Json arrayJson(arr);
    // EXPECT_EQ(arrayJson.toString(), "[1,\"test\"]");

    // 测试对象构造函数
    Json objJson("key", Json(std::string("value")));
    EXPECT_EQ(objJson.toString(), "{key: value}");
}

// 测试 add 函数
// TEST(JsonTest, AddTest) {
//     Json parent;
//     Json child1(10);
//     Json child2("child2");
//
//     // 添加第一个子节点
//     parent.add(&child1);
//     EXPECT_NE(parent.child, nullptr); // 确保子节点不为空
//     EXPECT_EQ(parent.child->i_data, 10); // 验证子节点内容
//
//     // 添加第二个子节点
//     parent.add(&child2);
//     EXPECT_NE(parent.child->next, nullptr); // 确保链表连接正确
//     EXPECT_EQ(parent.child->next->s_data, "child2"); // 验证第二个子节点内容
// }

// 测试 toString 函数
TEST(JsonTest, ToStringTest) {
    // 测试简单结构
    Json simpleJson(std::string ("simple"));
    EXPECT_EQ(simpleJson.toString(), "simple");

    // 测试嵌套结构
    // Json nestedJson("outer");
    // Json innerJson("inner");
    // nestedJson.add(&innerJson);
    // EXPECT_EQ(nestedJson.toString(), "{outer:{inner:}}"); // 注意：此处需根据实际逻辑调整预期结果

    // 测试空对象
    Json emptyObj;
    EXPECT_EQ(emptyObj.toString(), "{}");

    // 测试空数组
    // Json emptyArr(std::vector<Json>());
    // EXPECT_EQ(emptyArr.toString(), "[]");
}

// 测试 print 函数
TEST(JsonTest, PrintTest) {
    Json json(std::string("test"));
    testing::internal::CaptureStdout(); // 捕获标准输出
    json.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "test\n"); // 根据实际 print 实现调整预期输出
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }