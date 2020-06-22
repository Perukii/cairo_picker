
#include <gtkmm.h>

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

    protected:
        bool on_draw(Cairo_cont);
    };


    // =====

    class C_launcher{
    public:
        C_launcher(int, char**);
        Glib::RefPtr<Gtk::Application> app;
    };

    // =====

    class C_canvas{

    private:
        C_launcher launcher;
        C_window   window;
        C_area     area;

        struct{ int x;int y; } def_size = {100, 100};
        int timeout_interval = 0;

    public:
        C_canvas();
        void run(void(*)(Cairo_cont));
        void set_default_size(int, int);
        void set_timeout(int);

    protected:
        bool on_timeout();
        
    };

}


#include "cairo_picker.cpp"
#include "functions/capr_pictures.cpp"