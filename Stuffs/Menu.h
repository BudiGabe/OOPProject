#ifndef OOPPROJECT_MENU_H
#define OOPPROJECT_MENU_H


class Menu {
private:
    static Menu* menu;

    Menu();

public:
    static Menu* getInstance();

    void open();
};

#endif //OOPPROJECT_MENU_H