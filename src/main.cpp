#include <qpl/qpl.hpp>

struct foo2 {
    int a = 0;
    double b = 0.5;
};
struct foo5 {
    int a = 0;
    double b = 1.1;
    std::string string = "hi";
    std::vector<int> vec;
    char c = '#';
    std::array<foo2, 2> array;
};

int main() {

    foo5 a;
    a.a = 42;
    a.vec = { 1, 2, 3 };
    a.string = "cats";

    auto s = qpl::struct_content_to_string(a);
    qpl::println(qpl::struct_content_info_string(a));

    foo5 b;
    qpl::struct_content_from_string(s, b);
    qpl::println(qpl::struct_content_info_string(b));
}