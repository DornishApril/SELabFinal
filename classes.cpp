#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<math.h>
using namespace std;


// 
class window {
public:
    virtual void render() = 0;
};

class scrollbar {
public:
    virtual void render() = 0;
};  



class windows_window : public window {
public:
    void render() override {
        std::cout << "Drawing Windows window" << std::endl;
    }
};

class windows_scrollbar : public scrollbar {
public:
    void render() override {
        std::cout << "Drawing Windows scrollbar-" << std::endl;
    }

};  

class linux_window{

};  

class linux_scrollbar{

};  