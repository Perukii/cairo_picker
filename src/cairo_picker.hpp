
#include <gtkmm.h>
#include <cstdio>
#include <functional>

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
        std::function<void(Cairo_cont)> loop_func;
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
        template<class FUNC>
        void run(FUNC);

        void set_title(std::string);
        void set_default_size(uint, uint);
        void set_loop(uint);
        void set_key_input(void(*)(uint), void(*)(uint));
        void set_motion_input(void(*)(uint, uint));
        void set_button_input(void(*)(uint, uint, uint), void(*)(uint, uint, uint));

        void write_to_png(std::string);

        uint w();
        uint h();

    protected:

        void(*key_press)(uint);
        void(*key_release)(uint);
        void(*mouse_motion)(uint, uint);
        void(*button_press)(uint, uint, uint);
        void(*button_release)(uint, uint, uint);

        bool on_timeout();
        bool on_key_press_event(GdkEventKey *);
        bool on_key_release_event(GdkEventKey *);
        bool on_motion_notify_event(GdkEventMotion *);
        bool on_button_press_event(GdkEventButton *);
        bool on_button_release_event(GdkEventButton *);
        
    };

}


#include "cairo_picker.cpp"
#include "functions/capr_pictures.cpp"