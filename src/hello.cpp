#include <iostream>
#include <string>
#include <cstring> 

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

  FILE *pFile ;
  int i ;
  pFile = stdin ;

  fd_set readfds;
  FD_ZERO(&readfds);

  struct timeval timeout;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;

  char message[50];
  // char c1[1];
  char c1[1024];

  string str;
  size_t nbytes;
  ssize_t bytes_read;

  struct pollfd fds;
  int ret;
  fds.fd = 0; /* this is STDIN */
  fds.events = POLLIN;
  char newline = '\n';

  while(1) {
    // FD_SET(STDIN_FILENO, &readfds);
    //
    // if (select(1, &readfds, NULL, NULL, &timeout))
    // {
    //   // for (std::string line; std::getline(std::cin, line);) {
    //   //     std::cout << "---" << line << "---" << std::endl;
    //   // }
    //     cout << "data in stdin read one line:" << endl; 
    //     // scanf("%s", message); 
    //     // printf("Message: %s\n", message);
    //
    //     // getline(cin, str); 
    //     // cout << str << " : newline" << endl; 
    //
    //     nbytes = sizeof(message);
    //     int fd = 0;
    //     bytes_read = read(fd, message, nbytes);
    //     printf("Message: %s\n", message);
    //
    //
    // }
    //

    ret = poll(&fds, 1, 0);
    if(ret == 1) {
      printf("Yep: ");
      // i = (int) sizeof (stdin) ;
      // printf("%d bytes in stdin ", i) ;
      // getline(cin, str); 
      // cout << str << " : newline" << endl; 

      // bytes_read = read(&fds, message, nbytes);
      // bytes_read = read(0, message, nbytes);
      nbytes = sizeof(c1);
      bytes_read = read(0, c1, nbytes);
      // if (bytes_read == 0 ) {
      //   printf("EOF");
      //   printf(" %d", byte_count);
      //   break;
      // }
      printf("(%zd)", bytes_read);
      c1[bytes_read] = 0;
      printf("%s", c1);
      // int byte_count = 0;
      // while(1) {
      //   nbytes = sizeof(c1);
      //   bytes_read = read(0, c1, nbytes);
      //   if (bytes_read == 0 ) {
      //     printf("EOF");
      //     printf(" %d", byte_count);
      //     break;
      //   }
      //   printf("(%zd)", bytes_read);
      //   printf("%s", c1);
      //   // byte_count += 1;
      //   // if (newline == c1[0]) {
      //   //   printf("EOL");
      //   //   printf(" %d", byte_count);
      //   //   break;
      //   // } else {
      //   //   printf("%s", c1);
      //   // }
      // }

      // bytes_read = scanf("%s", message); 
      // printf(" %zd: %s", bytes_read, message);

      // std::cout << std::hex << c1 ;

      //
      // string line;
      // char c;
      // while( newline != (c = readchar(&fds)) ) {
      //   // printf("%s", c);
      //  // line.append(c);
      // }
      //
      // cout <<  line << " : newline" << endl; 
      // int c;
      // c = getchar();
      //
      // putchar(c);

    } else if(ret == 0) {
      printf("No");
    } else {
      printf("Error");
    }
    printf("\n");
    sleep(1);
  }
  return 0;
}


