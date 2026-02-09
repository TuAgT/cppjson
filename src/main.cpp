#include <iostream>
#include "json.h"
int main() {
    /*
     * {"name": "zhangsan",
     *  "age": 18,
     *  "sex": true,
     *  "height": 1.8,
     *  "weight": 80.5,
     *  "money": null
     * }
     */
    Json root;
    Json name(std::string("zhangsan"));
    Json age(18);
    Json sex(true);
    Json height(1.8f);
    Json weight(80.5f);
    Json money(std::string("null"));
    root.add(new Json("name", name));
    root.add(new Json("age", age));
    root.add(new Json("sex", sex));
    root.add(new Json("height", height));
    root.add(new Json("weight", weight));
    root.add(new Json("money", money));
    // std::cout << root.toString() << std::endl;
    // std::cout << name.toString() << std::endl;
    // std::cout << age.toString() << std::endl;
    // std::cout << sex.toString() << std::endl;
    // std::cout << height.toString() << std::endl;
    // std::cout << weight.toString() << std::endl;
    // std::cout << money.toString() << std::endl;

    root.print();
    // TODO: 数组
    Json arr;

    return 0;
}