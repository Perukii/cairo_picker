
#include <gtkmm.h>
#include <cstdio>

namespace Capr{

    using Cairo_cont = const Cairo::RefPtr<Cairo::Context> &;

    // =====

    class C_window : public Gtk::Window{
    public:
        C_window();
    };

    // =====

    class C_area : public Gtk::DrawingArea{
    public:
        C_area();
        void(*loop_func)(Cairo_cont);
        bool on_draw(Cairo_cont);
    };


    // =====

    class C_launcher{
    public:
        C_launcher(int, char**);
        Glib::RefPtr<Gtk::Application> app;
    };

    // =====

    class C_picker{

    private:
        C_launcher launcher;
        C_window   window;
        C_area     area;

        int timeout_interval = 0;

    public:
        C_picker();
        void run(void(*)(Cairo_cont));

        void set_title(std::string);
        void set_default_size(uint, uint);
        void set_loop(uint);
        void set_key_input(void(*)(uint), void(*)(uint));

        void write_to_png(std::string);

        uint w();
        uint h();


    protected:

        void(*key_press)(uint);
        void(*key_release)(uint);

        bool on_timeout();
        bool on_key_press_event(GdkEventKey * event);
        bool on_key_release_event(GdkEventKey * event);
        
    };

}


#include "cairo_picker.cpp"
#include "functions/capr_pictures.cpp"