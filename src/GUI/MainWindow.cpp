#include "MainWindow.h"

MainWindow::MainWindow(const Glib::RefPtr<Gtk::Application>& app){
    // Set up menubar
    // Action groups
    this->menuActionGroup = Gio::SimpleActionGroup::create();
    menuActionGroup->add_action("quit",
            sigc::mem_fun(*this, &MainWindow::onQuitAction) );

    insert_action_group("menubar", menuActionGroup);

    // Construct menubar
    Glib::RefPtr<Gtk::Builder> gtkBuilder = Gtk::Builder::create();
    gtkBuilder->add_from_string(this->menuDesc);

    Glib::RefPtr<Glib::Object> menubarObj = gtkBuilder->get_object("menubar");
    Glib::RefPtr<Gio::Menu> gMenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(menubarObj);
    Gtk::MenuBar* pMenubar = Gtk::manage(new Gtk::MenuBar(gMenu));
    box.pack_start(*pMenubar, Gtk::PACK_SHRINK);

    pMenubar->show();

    // Menubar keybindings
    app->set_accel_for_action("menubar.quit", "<Primary>q");

    // Add components
    add(box);
    box.show();
}

void MainWindow::onQuitAction(){
    hide();
}
