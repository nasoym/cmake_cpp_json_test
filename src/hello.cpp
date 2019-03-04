#include <iostream>
#include <string>
#include <cstring> 
#include <deque>

#include <chrono>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/poll.h>

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

  char c1[1024];
  string line;
  deque<string> lines;


  ssize_t bytes_read;

  struct pollfd fds;
  int ret;
  fds.fd = 0; /* this is STDIN */
  fds.events = POLLIN;

  char newline = '\n';
  json json_line;

  while(1) {
    ret = poll(&fds, 1, 0);
    if(ret == 1) {
      // printf("Yep: ");
      // bytes_read = read(&fds, message, nbytes);
      bytes_read = read(0, c1, sizeof(c1));
      // printf("(%zd) ", bytes_read);
      c1[bytes_read] = 0;
      // printf("%s ", c1);
      line.append(c1);
      if ((bytes_read > 0 ) && (newline == c1[bytes_read-1])) {
        // printf("EOL");
        // std::cout << '\n' << line << '\n';
        lines.push_back(line);
        line.clear();

      }
    } else if(ret == 0) {
    //   printf("No");
    } else {
      printf("Error");
    }

    while (!lines.empty())
    {
      // std::cout << " -:" << lines.front() << ":- \n";
      json_line = json::parse(lines.front());
      lines.pop_front();
      // std::cout << " -:" << json_line.dump() << ":- \n";
      if (json_line.find("command") != json_line.end()) {
        std::cout << "command: " << json_line["command"].get<string>() << "\n";
        // there is an entry with key "foo"

        if (json_line["command"].get<string>().compare("abc") == 0) {
          std::cout << "ABC" << "\n";
        }

      }
    }

    // printf("\n");
    sleep(1);
    //   std::cout << "- before sleep" << std::endl;
    //   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //   std::cout << "- after sleep" << std::endl;
  }
  return 0;
}

