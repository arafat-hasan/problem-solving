//Find if string ends with another string in C++
//How can I find if a string ends with another string in C++?
//Simply compare the last n characters using std::string::compare:
//https://stackoverflow.com/questions/874134


#include <iostream>


bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(),
                                         ending.length(), ending));

    } else {
        return false;
    }
}

int main () {
    std::string test1 = "binary";
    std::string test2 = "unary";
    std::string test3 = "tertiary";
    std::string test4 = "ry";
    std::string ending = "nary";
    std::cout << hasEnding (test1, ending) << std::endl;
    std::cout << hasEnding (test2, ending) << std::endl;
    std::cout << hasEnding (test3, ending) << std::endl;
    std::cout << hasEnding (test4, ending) << std::endl;
    return 0;
}



//how to check string start in C++
//Is there any way in C++ to check whether a string starts with a certain
//string (smaller than the original) ?
//https://stackoverflow.com/a/8095132/7829174



//std::string s ("Hello world");

//if (s.find ("Hello") == 0) {
//    std::cout << "String starts with Hello\n";
//}


