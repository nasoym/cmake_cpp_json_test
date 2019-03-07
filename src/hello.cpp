
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/poll.h>

#include <deque>

#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
 
int main(int argc, char *argv[]){

  char newline = '\n';
  char bytes_from_stdin[1024];
  ssize_t bytes_read;
  string appended_bytes_from_stdin;
  size_t newline_pos_in_stdin = 0;

  struct pollfd fds;
  fds.fd = 0; /* this is STDIN */
  fds.events = POLLIN;
  int poll_return;

  deque<string> line_deque;

  json json_line;

  while(1) {
    poll_return = poll(&fds, 1, 0);
    if(poll_return == 1) {
      // bytes_read = read(&fds, message, nbytes);
      bytes_read = read(0, bytes_from_stdin, sizeof(bytes_from_stdin));
      appended_bytes_from_stdin.append(bytes_from_stdin, bytes_read);
      while ((newline_pos_in_stdin = appended_bytes_from_stdin.find(newline)) != std::string::npos) {
        line_deque.push_back(appended_bytes_from_stdin.substr(0, newline_pos_in_stdin));
        appended_bytes_from_stdin.erase(0, newline_pos_in_stdin + 1);
      }
    // } else if(poll_return == 0) {
    // //   printf("No");
    // } else {
    } else if(poll_return != 0) {
      std::cerr << "error while polling stdin for data" << std::endl;
    }
    while (!line_deque.empty()) {
      try {
        json_line = json::parse(line_deque.front());
        if (json_line.find("command") != json_line.end()) {
          std::cout << "command: " << json_line["command"].get<string>() << std::endl;
          if (json_line["command"].get<string>().compare("abc") == 0) {
            std::cout << "ABC" << std::endl;
          }
        }
      }
      catch (json::exception& e) {
        // output exception information
        std::cerr << "message: " << e.what() << '\n'
                   << "exception id: " << e.id << std::endl;
      }
      line_deque.pop_front();
    }

    sleep(1);
    //   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //   std::cout << "- after sleep" << std::endl;
  }
  return 0;
}

