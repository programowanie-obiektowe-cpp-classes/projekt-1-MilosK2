#ifndef P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP

#include <array>
#include <format>
#include <random>

inline constexpr std::array first_names{
    "Ann",
    "Andrew",
    "John",
    "Jane",
    "Bob",
    "Alice",
    "Bertram",
    "Monica",
    "Laura",
    "Eric",
    "Richard",
    "Karen",
    "Clara",
    "Rupert",
    "Bruce",
    "Martha",
    "Elizabeth",
    "Corey",
    "Nancy",
    "Joe",
    "Amy",
    "Mike",
    "James",
    "Naomi"
};

inline constexpr std::array last_names{
    "Hendricks",
    "Smith",
    "Gates",
    "Stein",
    "Warren",
    "Booker",
    "Williamson",
    "Walters",
    "Dunn",
    "Swanson",
    "Knope",
    "Haverford",
    "Ludgate",
    "Meagle",
    "Favreau",
    "Vietor",
    "Lovett",
    "Pfeifer",
    "Rhodes",
    "Abrams",
    "McFaul",
    "Stone",
    "Sisley",
    "Hanneman",
    "Holden",
    "Nagata"
};

inline constexpr std::array faculties{"MEiL", "EiTI", "Mechatroniki",  "Elektryczny",   "SiMR", "ICHiP",
                                        "Architektury", "Fizyki", "Chemiczny", "M-T",   "AiNS",   "GiK",
                                    "MiNI", "Zarz¹dzania"};

inline auto getRandomName() -> std::string {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<std::size_t>{0, first_names.size() - 1};
    auto lnd = std::uniform_int_distribution<std::size_t>{0, last_names.size() - 1};
    const auto first_name = first_names[fnd(prng)];
    const auto last_name = last_names[lnd(prng)];
    return std::format("{} {}", first_name, last_name);
}
inline auto getRandomFaculty() -> std::string
{
    static auto prng    = std::mt19937{std::random_device{}()};
    auto        fnd     = std::uniform_int_distribution< std::size_t >{0, first_names.size() - 1};
    auto        lnd     = std::uniform_int_distribution< std::size_t >{0, last_names.size() - 1};
    const auto  faculty = faculties[fnd(prng)];
    return std::format("{}", faculty);
}
inline auto getRandomForklift()->bool
    {
    static auto  prng = std::mt19937{std::random_device{}()};
    auto         fnd  = std::uniform_int_distribution<>{0, 1};
    const bool   res  = fnd(prng); 
    return res;
    }
inline auto getRandomFollows() -> int
    {
    static auto prng = std::mt19937{std::random_device{}()};
    auto        fnd  = std::uniform_int_distribution<>{10000, 1000000};
    const int  res  = fnd(prng);
    return res;
    }
inline auto getRandomShoe() -> int
    {
    static auto prng = std::mt19937{std::random_device{}()};
    auto        fnd  = std::uniform_int_distribution<>{35, 49};
    const int  res  = fnd(prng);
    return res;
    }
#endif //P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
