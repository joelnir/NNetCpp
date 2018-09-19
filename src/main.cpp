#include <iostream>
#include <gtkmm/application.h>

#include "MainWindow.h"

int main(int argc, char* argv[]){
    auto app = Gtk::Application::create(argc, argv);

    MainWindow win = MainWindow(app);

    // Start GUI
    return app->run(win);
}
