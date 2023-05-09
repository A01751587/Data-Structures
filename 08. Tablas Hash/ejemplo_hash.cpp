#include <functional>
#include <iostream>

struct Student {
    int id;
    std::string name;
    double grade_average;
    bool operator==(const Student& other) const
    {
        return id == other.id
            and name == other.name
            and grade_average == other.grade_average;
    }
};

namespace std {
    template<>
    class hash<Student> {
    public:
        int operator() (const Student& s)
        {
            int result = 1;
            int prime = 31;
            std::hash<int> hi;
            std::hash<std::string> hs;
            std::hash<double> hd;

            result += hi(s.id) * prime;
            result += hs(s.name) * prime;
            result += hd(s.grade_average) * prime;
            return static_cast<unsigned>(result);
        }
    };
}

int main()
{
    std::hash<std::string> hs;
    std::string s = "hello";

    std::cout << s << ' ' << hs(s) << '\n';

    std::hash<int> hi;
    int i = 108;
    std::cout << i << ' ' << hi(i) << '\n';

    std::hash<double> hd;
    double d = 3.1416;
    std::cout << d << ' ' << hd(d) << '\n';

    std::hash<Student> student_hash;
    Student student {123, "Juan", 98.5};
    std::cout << student_hash(student) << '\n';

}