#include <map>
#include <vector>
#include <functional>
namespace numbers
{
complex
eval(const std::vector<std::string> &args, const complex &z)
{
    complex_stack st;
    std::map<std::string, std::function<void(void)>> ops;
    ops["!"] = [&]() { st = st << +st; };
    ops[";"] = [&]() { st = ~st; };
    ops["~"] = [&]() {
        complex tmp = +st;
        ops[";"]();
        st = st << (~tmp);
    };
    ops["/"] = [&]() {
        complex tmp1 = +st;
        ops[";"]();
        complex tmp2 = +st;
        ops[";"]();
        st = st << (tmp2 / tmp1);
    };
    ops["*"] = [&]() {
        complex tmp1 = +st;
        ops[";"]();
        complex tmp2 = +st;
        ops[";"]();
        st = st << (tmp1 * tmp2);
    };
    ops["-"] = [&]() {
        complex tmp1 = +st;
        ops[";"]();
        complex tmp2 = +st;
        ops[";"]();
        st = st << (tmp2 - tmp1);
    };
    ops["+"] = [&]() {
        complex tmp1 = +st;
        ops[";"]();
        complex tmp2 = +st;
        ops[";"]();
        st = st << (tmp1 + tmp2);
    };
    ops["#"] = [&]() {
        complex tmp = +st;
        st = ~st;
        st = st << (-tmp);
    };
    for (auto i : args) {
        if (i == "z") {
            st = st << z;
        } else if (ops.count(i)) {
            ops[i]();
        } else {
            st = st << complex(i);
        }
    }
    complex ans = +st;
    ops[";"]();
    return ans;
}
}
