#pragma once

#include <iostream>
#include <sstream>
#include <string>

class CinRedirect
{
public:
    ~CinRedirect(void)
    {
        std::cin.rdbuf(old);
    }

    CinRedirect(const std::string& input):
        iss(input),
        old(std::cin.rdbuf(iss.rdbuf()))
    {}

    CinRedirect(const CinRedirect&) = delete;
    CinRedirect(CinRedirect&&) noexcept = delete;
    CinRedirect& operator = (const CinRedirect&) = delete;
    CinRedirect& operator = (CinRedirect&&) noexcept = delete;

private:
    std::istringstream iss;
    std::streambuf* old{nullptr};
};
