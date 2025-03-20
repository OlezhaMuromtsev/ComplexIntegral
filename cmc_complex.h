#include <string>
#include <cmath>

constexpr int BUFSZ = 256;

namespace numbers
{
class complex
{
public:
    complex(const double a, const double b)
    {
        re1 = a;
        im1 = b;
    }
    complex() : complex(0.0, 0.0) {}
    complex(const double a) : complex(a, 0) {}
    explicit complex(const std::string s)
    {
        size_t sep = s.find(',');
        std::string sre = s.substr(1, sep - 1);
        std::string sim = s.substr(sep + 1, s.size() - sep);
        re1 = stod(sre);
        im1 = stod(sim);
    }
    double
    re() const
    {
        return this->re1;
    }
    double
    im() const
    {
        return this->im1;
    }
    double
    abs2() const
    {
        return im1 * im1 + re1 * re1;
    }
    double
    abs() const
    {
        return std::sqrt(abs2());
    }
    std::string
    to_string() const
    {
        char tmp[BUFSZ];
        snprintf(tmp, sizeof(tmp), "(%.10g,%.10g)", re1, im1);
        return std::string(tmp);
    }
    complex &
    operator+=(const complex &num)
    {
        this->re1 += num.re1;
        this->im1 += num.im1;
        return (*this);
    }
    complex &
    operator-=(const complex &num)
    {
        im1 -= num.im1;
        re1 -= num.re1;
        return (*this);
    }
    complex &
    operator*=(const complex &num)
    {
        double newre = re1 * num.re1 - im1 * num.im1;
        double newim = re1 * num.im1 + im1 * num.re1;
        this->re1 = newre;
        this->im1 = newim;
        return (*this);
    }
    complex &
    operator/=(const complex &num)
    {
        double new_re = (re1 * num.re1 + im1 * num.im1) / num.abs2();
        double new_im = (im1 * num.re1 - re1 * num.im1) / num.abs2();
        this->re1 = new_re;
        this->im1 = new_im;
        return (*this);
    }
    complex
    operator~() const
    {
        complex copy{*this};
        copy.im1 = -copy.im1;
        return copy;
    }
    complex
    operator-() const
    {
        complex copy{*this};
        copy.im1 = -copy.im1;
        copy.re1 = -copy.re1;
        return copy;
    }

private:
    double re1;
    double im1;
};

complex
operator+(complex num, const complex &c)
{
    num += c;
    return num;
}
complex
operator-(complex num, const complex &c)
{
    num -= c;
    return num;
}
complex
operator*(complex num, const complex &c)
{
    num *= c;
    return num;
}
complex
operator/(complex num, const complex &c)
{
    num /= c;
    return num;
}
}; // namespace numbers
