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



class windows_window{
};

class windows_scrollbar{

};  

class linux_window{

};  

class linux_scrollbar{

};  