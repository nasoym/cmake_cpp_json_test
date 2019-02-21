#include <iostream>
#include <string>


#include <nlohmann/json.hpp>

using json = nlohmann::json;
 
int main(int argc, char *argv[]){



// // create an empty structure (null)
// json j;
//
// // add a number that is stored as double (note the implicit conversion of j to an object)
// j["pi"] = 3.141;
//
// // add a Boolean that is stored as bool
// j["happy"] = true;
//
// // add a string that is stored as std::string
// j["name"] = "Niels";
//
//
//   // parse explicitly
//   auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
//
//  
//    std::cout << j.dump() << std::endl;
//    std::cout << j3.dump() << std::endl;


    for (std::string line; std::getline(std::cin, line);) {
        std::cout << "---" << line << "---" << std::endl;
    }

   return 0;
}


