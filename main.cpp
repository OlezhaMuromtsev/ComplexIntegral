#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_eval.h"
#include <iostream>


int
main(int argc, char **argv)
{
    numbers::complex c = numbers::complex(std::string(argv[1]));
    double r = std::stod(std::string(argv[2]));
    const double pi_v = std::numbers::pi;
    long long n = std::stoll(std::string(argv[3]));
    std::vector<std::string> formula;
    for (int i = 4; i < argc; i++) {
        formula.push_back(std::string(argv[i]));
    }
    double angle = 0.0;
    numbers::complex tmp = numbers::complex(0.0, 0.0);
    numbers::complex point = numbers::complex(0.0, 0.0);
    numbers::complex dif = numbers::complex(0.0, 0.0);
    for (long long i = 0; i < n; i++) {
        angle = i * 2.0d * pi_v / (1.0d * n);
        point = c + numbers::complex(r * std::cos(angle), r * std::sin(angle));
        dif = numbers::complex(-r * std::sin(angle), r * std::cos(angle)) * (2 * pi_v / n);
        tmp += numbers::eval(formula, point) * dif;
    }
    std::cout << tmp.to_string() << std::endl;
    return 0;
}
