
namespace Capr{
    // =====

    C_window::C_window() {
        
    }

    // =====

    C_launcher::C_launcher(int argc = 0, char** argv = nullptr) {
        app = Gtk::Application::create(argc, argv);
    }

    // =====


    C_area::C_area() {}

    bool Capr::C_area::on_draw(Cairo_cont cr){
        if(loop_func != NULL) loop_func(cr);
        return true;
    }

    // =====

    C_canvas::C_canvas(){
        window.add(area);
    }

    void C_canvas::set_title(std::string title){
        window.set_title(title);
    }

    void C_canvas::run( void(*tar_loop_func)(Cairo_cont) = NULL ){
        
        area.loop_func = tar_loop_func;
        if( timeout_interval != 0 ){
            Glib::signal_timeout().connect(
                sigc::mem_fun(*this, &Capr::C_canvas::on_timeout), timeout_interval);
        }
        
        area.show();
        launcher.app->run(window);

    }

    void C_canvas::set_default_size(uint w = 0, uint h = 0){
        window.set_default_size(w, h);
    }

    void C_canvas::set_loop(uint interval) {
        timeout_interval = interval;
    }

    bool C_canvas::on_timeout() {
        area.queue_draw();
        return true;
    }

    void C_canvas::set_key_input(void(*tar_key_press)(uint), void(*tar_key_release)(uint)) {
        key_press = tar_key_press;
        key_release = tar_key_release;

        window.signal_key_press_event().connect(
            sigc::mem_fun(*this, &Capr::C_canvas::on_key_press_event) );
        window.signal_key_release_event().connect(
            sigc::mem_fun(*this, &Capr::C_canvas::on_key_release_event) );
    }

    bool C_canvas::on_key_press_event(GdkEventKey * event){
        if(key_press != NULL) key_press(event->keyval);
        return true;
    }

    bool C_canvas::on_key_release_event(GdkEventKey * event){
        if(key_release != NULL) key_release(event->keyval);
        return true;
    }

    uint C_canvas::w() { return window.get_width();  }
    uint C_canvas::h() { return window.get_height(); }

}
