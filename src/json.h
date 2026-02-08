//
// Created by ZHT END on 2026/2/7.
//

#ifndef MYJSON_JSON_H
#define MYJSON_JSON_H

#include <string>
#include <vector>
#include <map>
// 数据类型
enum type {
    Nums_int=0,
    Nums_float,
    Str,
    Bool,
    Array,
    Object,
    Null
};
class Json {
private:
    Json *parent=nullptr;   // 父节点
    Json *child = nullptr;    // 子节点
    Json *next=nullptr;     // 下一个节点
    Json *prev=nullptr;     // 上一个节点
    int i_data; // 整数
    float f_data; // 浮点数
    double d_data; // 浮点数
    bool b_data; // 布尔
    std::string s_data; // 字符串
    std::vector<Json> a_data; // 数组
    std::map<std::string, Json> o_data; // 对象
    std::string n_data; // null
    int type;
public:


    Json();

    explicit Json(int value);

    explicit Json(float value);

    explicit Json(const std::string& value);

    explicit Json(bool value);

    explicit Json(std::vector <Json> value);
    Json(std::string key, Json value);
    ~Json();

    // 添加对象
    void add(Json *json);
    // 转换成字符串
    std::string toString();
    // 打印
    void print();

};
#endif //MYJSON_JSON_H