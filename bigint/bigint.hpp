#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

class bigint
{
    private:
        std::string num;

        std::string add_strings(const std::string &n1, const std::string &n2) const
        {
            std::string result;
            int carry = 0, i = n1.size() - 1, j = n2.size() - 1;
            while (i >= 0 || j >= 0 || carry)
            {
                int sum = (i >= 0 ? n1[i--] - '0' : 0) + (j >= 0 ? n2[j--] - '0' : 0) + carry;
                result.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

    public:

        bigint() : num("0") {}

        bigint(unsigned long long n)
        {
            std::ostringstream oss;
            oss << n;
            num = oss.str();
        }
        bigint(const std::string &n) : num(n.empty() ? "0" : n) 
        {
            size_t i = 0;

            while (i < num.size()) // Validate that all characters are digits
            {
                if (!isdigit(num[i]))
                {
                    num = "0";
                    break;
                }
                i++;
            }

            while (num.size() > 1 && num[0] == '0') // Remove leading zeros
                num.erase(0, 1);

        }

        bigint &operator=(const bigint &oth)
        {
            if (this != &oth)
            {
                num = oth.num;
            }
            return *this;
        }
        bigint(const bigint &oth) : num(oth.num) {}
        ~bigint () {}



        friend std::ostream &operator<<(std::ostream &os, const bigint &b)
        {
            return os << b.num;
        }

        bigint operator+(const bigint &oth) const
        {
            return bigint(add_strings(num, oth.num));
        }
        bigint &operator+=(const bigint &oth)
        {
            num = add_strings(num, oth.num);
            return *this;
        }


        bigint &operator++()
        {
            return *this += bigint(1);
        }
        bigint operator++(int)
        {
            bigint tmp(*this);
            ++(*this);
            return tmp;
        }


        bigint operator<<(size_t shift) const
        {
            return bigint(num + std::string(shift, '0'));
        }
        bigint &operator<<=(size_t shift)
        {
            num += std::string(shift, '0');
            return *this;
        }

        bigint operator>>(size_t shift) const
        {
            if (shift >= num.size())
                return bigint(0);
            return bigint(num.substr(0, num.size() - shift));
        }
        bigint &operator>>=(size_t shift)
        {
            if (shift >= num.size())
                num = "0";
            else
                num = num.substr(0, num.size() - shift);
            return *this;
        }
        bigint &operator>>=(const bigint &b)
        {
            if (bigint(num.size()) <= b)
                num = "0";
            else
            {
                bigint i(0);
                while (i < b)
                {
                    num = num.substr(0, num.size() - 1);
                    ++i;
                }
            }
            return *this;
        }



        bool operator<(const bigint &oth) const
        {
            if (num.size() < oth.num.size())
                return 1;
            else if (num.size() > oth.num.size())
                return 0;
            return num < oth.num;
        }
        bool operator>(const bigint &oth) const
        {
            return oth < *this;
        }
        bool operator>=(const bigint &oth) const
        {
            return !(*this < oth);
        }
        bool operator<=(const bigint &oth) const
        {
            return !(*this > oth);
        }


        bool operator==(const bigint &oth) const
        {
            return num == oth.num;
        }
        bool operator!=(const bigint &oth) const
        {
            return num != oth.num;
        }

        
        bigint operator-(const bigint &oth) const
        {
            (void)oth;
            return bigint();
        }
};
