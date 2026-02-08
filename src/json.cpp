//
// Created by ZHT END on 2026/2/7.
//
#include "json.h"

#include <map>
#include <iostream>


Json::Json() {
    type = Object; // 对象类型
}

Json::Json(const int value) {
    type = Nums_int; // 整数类型
    i_data = value;
}

Json::Json(const float value) {
    type = Nums_float; // 浮点数类型
    f_data = value;
}

Json::Json(const std::string& value) {
    if (value == "null") {
        type = Null;
        n_data = "null";
        return;
    }
    type = Str; // 字符串类型
    s_data = value;
}
Json::Json(const bool value) {
    type = Bool; // 布尔类型
    b_data = value;
}

Json::Json(const std::vector<Json> value) {
    type = Array; // 数组类型
    a_data = value;
}

Json::Json(const std::string key, const Json value) {
    type = Object; // 对象类型
    o_data[key] = value;
}


Json::~Json() {

}

void Json::add(Json *json) {
    Json *tmp = this->child;
    this->child = json;
    json->parent = this;
    json->next = tmp;
    if (tmp) {
        tmp->prev = json;
    }

}

// TODO: 优化输出逻辑
std::string Json::toString() {
    std::string res;
    // 输出数据
    switch (type) {
        case Nums_int:
            res += std::to_string(i_data);
            break;
        case Nums_float:
            res += std::to_string(f_data);
            break;
        case Bool:
            res += std::to_string(b_data);
            break;
        case Str:
            res += s_data;
            break;
        case Null:
            res += n_data;
            break;
        case Array:
            res += "[" ;
            for (auto &item: a_data) {
                res += item.toString();
            }
            res += "]";
            break;
        case Object:
            res += "{" ;
            for (auto &item: o_data) {
                res += item.first + ": " + item.second.toString();
            }
            res += "}";
            break;
    }

    return res;
}

void Json::print() {
    std::cout << this->toString() << std::endl;
    while (child) {
        child->print();
        break;
    }
    while (next) {
        next->print();
        break;
    }
}

