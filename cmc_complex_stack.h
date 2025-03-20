namespace numbers
{
class complex_stack
{
public:
    complex_stack()
    {
        ptr = nullptr;
        sz = 0;
    }
    complex_stack(complex *p, size_t amount)
    {
        sz = amount;
        ptr = new complex[amount];
        for (size_t i = 0; i < sz; i++) {
            ptr[i] = p[i];
        }
    }
    complex_stack(const complex_stack &templt, const complex &num)
    {
        sz = templt.size() + 1;
        ptr = new complex[sz];
        for (size_t i = 0; i < sz - 1; i++) {
            ptr[i] = templt[i];
        }
        ptr[sz - 1] = num;
    }
    complex_stack(const complex_stack &other)
    {
        this->sz = other.sz;
        this->ptr = new complex[sz];
        for (size_t i = 0; i < sz; i++) {
            this->ptr[i] = other[i];
        }
    }
    complex_stack
    operator=(const complex_stack &other)
    {
        delete[] this->ptr;
        this->sz = other.size();
        this->ptr = new complex[sz];
        for (size_t i = 0; i < sz; i++) {
            this->ptr[i] = other[i];
        }
        return *this;
    }
    complex
    operator+() const
    {
        if (sz == 0) {
            return complex(0.0, 0.0);
        }
        return ptr[sz - 1];
    }
    complex_stack
    operator~() const
    {
        return complex_stack(ptr, sz - 1);
    }
    complex &
    operator[](const size_t &i) const
    {
        return ptr[i];
    }
    ~complex_stack() { delete[] ptr; }
    size_t
    size() const
    {
        return sz;
    }

private:
    complex *ptr;
    size_t sz;
};

complex_stack
operator<<(const complex_stack &st, const complex &num)
{
    return complex_stack(st, num);
}

} // namespace numbers
