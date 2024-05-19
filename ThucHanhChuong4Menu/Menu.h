#pragma once
// Menu.h
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu {
private:
    std::string menuTitle;
    std::vector<std::string> options;

public:
    Menu(const std::string& title) : menuTitle(title) {}

    Menu& operator<<(const std::string& option) {
        options.push_back(option);
        return *this;
    }

    void themLuachon(const std::string& option) {
        options.push_back(option);
    }

    int chon() const {
        int choice;
        std::cout << "======== " << menuTitle << " ========\n";
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i << ". " << options[i] << std::endl;
        }
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        return choice;
    }
};

#endif // MENU_H
