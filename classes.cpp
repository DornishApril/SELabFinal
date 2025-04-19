#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<math.h>
using namespace std;

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

class linux_window : public window {
public:
    void render() override {
        std::cout << "Drawing Linux window" << std::endl;
    }
};

class linux_scrollbar : public scrollbar {
public:
    void render() override {
        std::cout << "Drawing Linux scrollbar" << std::endl;
    }
};


// Abstract Factory interface
class GUIFactory {
public:
    virtual window* createWindow() = 0;
    virtual scrollbar* createScrollbar() = 0;
};

// Concrete factories
class WindowsFactory : public GUIFactory {
public:
    window* createWindow() override {
        return new windows_window();
    }
    
    scrollbar* createScrollbar() override {
        return new windows_scrollbar();
    }
};

class LinuxFactory : public GUIFactory {
public:
    window* createWindow() override {
        return new linux_window();
    }
    
    scrollbar* createScrollbar() override {
        return new linux_scrollbar();
    }
};


int main() {

    printf("Creating GUIFactory. . . \n");
    
    GUIFactory* windowsFactory = new WindowsFactory();
    
    window* winWindow = windowsFactory->createWindow();
    scrollbar* winScrollbar = windowsFactory->createScrollbar();
    
    cout << "Windows GUI components:" <<endl;
    winWindow->render();
    winScrollbar->render();


        

    GUIFactory* linuxFactory = new LinuxFactory();

    window* linWindow = linuxFactory->createWindow();
    scrollbar* linScrollbar = linuxFactory->createScrollbar();
    
    cout << "\nLinux GUI components:" << endl;
    linWindow->render();
    linScrollbar->render();

    return 0;
}