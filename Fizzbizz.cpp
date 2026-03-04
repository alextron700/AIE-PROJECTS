#include <iostream>
#include <cassert>
#include <string>
std::string fizzbuzz(int input)
{
    bool F = false;
    bool B = false;
    std::string out = "";
    if (input % 3 == 0)
    {
        out+= "fizz";
        F = true;
    }
    if (input % 5 == 0)
    {
        out+= "buzz";
        B = true;
    }
    if (input % 5 != 0 && input % 3 != 0)
    {
        out +=std::to_string(input);
    }
    return out;
    
}
int main()
{
    int input = 7;
    std::string FB = fizzbuzz(input);
    assert(FB == "7");
    input = 3;
    FB = fizzbuzz(input);
    assert(FB == "fizz");
    input = 5;
    FB = fizzbuzz(input);
    assert(FB == "buzz");
    input = 15;
    FB = fizzbuzz(input);
    assert(FB == "fizzbuzz");
    return 0;
}