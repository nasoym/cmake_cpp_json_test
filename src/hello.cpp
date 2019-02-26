#include <iostream>
#include <string>
#include <cstring> 

#include <chrono>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#include <nlohmann/json.hpp>

using namespace std;
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


    // while(true) {
    //   for (std::string line; std::getline(std::cin, line);) {
    //       std::cout << "---" << line << "---" << std::endl;
    //   }
    //
    //   std::cout << "- before sleep" << std::endl;
    //   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //   std::cout << "- after sleep" << std::endl;
    //
    // }

   // cout << cin.rdbuf()->in_avail() << endl;

    // FILE *pFile ;
    // int i ;
    // pFile = stdin ;
    // i = (int) sizeof (stdin) ;
    // printf("%d bytes in stdin\n", i) ;

    fd_set readfds;
    FD_ZERO(&readfds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    char message[50];

    string str;

    while(1)
    {
        FD_SET(STDIN_FILENO, &readfds);

        if (select(1, &readfds, NULL, NULL, &timeout))
        {
          // for (std::string line; std::getline(std::cin, line);) {
          //     std::cout << "---" << line << "---" << std::endl;
          // }
            // scanf("%s", message); 
            // printf("Message: %s\n", message);
            getline(cin, str); 
            cout << str << " : newline" << endl; 

        }

        printf("...\n");
        sleep(1);
    }

   return 0;
}


