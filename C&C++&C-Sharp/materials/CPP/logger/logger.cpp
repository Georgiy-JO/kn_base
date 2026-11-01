#include "logger.hpp"

void logger(std::string str){
    static long int line=0;
  std::ofstream ofs("log.txt",std::ios::app);
  ofs<<line<< ": "<<str<<std::endl;
  ofs.close();
  line++;
}