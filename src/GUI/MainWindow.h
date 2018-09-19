#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow: public Gtk::Window {
    private:
        // XML-description of menubar
        const char* menuDesc =
            "<interface>"
            "  <menu id='menubar'>"
            "    <submenu>"
            "      <attribute name='label' translatable='yes'>_File</attribute>"
            "      <section>"
            "        <item>"
            "          <attribute name='label' translatable='yes'>_Quit</attribute>"
            "          <attribute name='action'>menubar.quit</attribute>"
            "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
            "        </item>"
            "      </section>"
            "    </submenu>"
            "    <submenu>"
            "      <attribute name='label' translatable='yes'>_Train</attribute>"
            "      <section>"
            "      </section>"
            "    </submenu>"
            "  </menu>"
            "</interface>";

        Gtk::VBox box;

        Glib::RefPtr<Gio::SimpleActionGroup> menuActionGroup;

    public:
        /**
         * Create a new main window
         */
        MainWindow(const Glib::RefPtr<Gtk::Application>& app);

        /**
         * Handle the quit action from the menu by shutting down the application
         */
        void onQuitAction();
};

#endif //MAIN_WINDOW_H
