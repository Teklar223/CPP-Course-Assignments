#ifndef NOTEBOOK
#define NOTEBOOK

#include <string>
#include "Direction.hpp"

namespace ariel{
    class Notebook{
        public:
        Notebook() {}
        ~Notebook() {}

        bool write(int,int,int,Direction,const std::string){
            return false;
        }

        std::string read(int,int,int,Direction,int){
            return "WIP";
        }

        bool erase(int,int,int,Direction,int){
            return false;
        }

        void show(int) {}
    };
}

#endif