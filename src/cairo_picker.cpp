

namespace Capr{
    // =====

    C_window::C_window() {
        
    }

    // =====

    C_launcher::C_launcher(int argc = 0, char** argv = NULL) {
        app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    }

    // =====


    C_area::C_area() {}

    bool Capr::C_area::on_draw(Cairo_cont cr){
        if(loop_func != NULL) loop_func(cr);
        return true;
    }

    // =====

    C_canvas::C_canvas(){
        window.set_title("C_canvas");
        window.add(area);
    }

    void C_canvas::run( void(*tar_loop_func)(Cairo_cont) = NULL ){
        
        window.set_default_size(def_size.x, def_size.y);
        area.loop_func = tar_loop_func;
        if( timeout_interval != 0 ){
            Glib::signal_timeout().connect(
                sigc::mem_fun(*this, &Capr::C_canvas::on_timeout), timeout_interval);
        }
        
        area.show();
        launcher.app->run(window);


    }

    void C_canvas::set_default_size(int w = 0, int h = 0){
        def_size.x = w;
        def_size.y = h;
    }

    void C_canvas::set_timeout(int interval = 1 ){
        timeout_interval = interval;
    }

    bool C_canvas::on_timeout() {
        area.queue_draw();
        return true;
    }

}
