/* MIT License

Copyright (c) 2022 Asger Gitz-Johansen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef YAUUID_UUID_H
#define YAUUID_UUID_H
#include <string>
#include <random>
#include <sstream>

namespace ya {
    template<typename random_algorithm_t = std::mt19937>
    auto uuid_v4_custom(const char* header, const char* connector) -> std::string {
        std::random_device device{};
        random_algorithm_t gen{device()};
        std::uniform_int_distribution<> distribution1{0, 15};
        std::uniform_int_distribution<> distribution2{8, 11};
        std::stringstream ss;
        int i;
        ss << std::hex << header;
        for (i = 0; i < 8; i++)
            ss << distribution1(gen);
        ss << connector;
        for (i = 0; i < 4; i++)
            ss << distribution1(gen);
        ss << connector << "4";
        for (i = 0; i < 3; i++)
            ss << distribution1(gen);
        ss << connector;
        ss << distribution2(gen);
        for (i = 0; i < 3; i++)
            ss << distribution1(gen);
        ss << connector;
        for (i = 0; i < 12; i++)
            ss << distribution1(gen);
        return ss.str();
    }
    template<typename random_algorithm_t = std::mt19937>
    auto uuid_v4() -> std::string {
        return uuid_v4_custom<random_algorithm_t>("","-");
    }
}

#endif //YAUUID_UUID_H
