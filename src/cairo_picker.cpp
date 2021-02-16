
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

    C_picker::C_picker(){
        window.add(area);
    }

    void C_picker::set_title(std::string title){
        window.set_title(title);
    }

    //void(*tar_loop_func)(Cairo_cont)

    template<class FUNC>
    void C_picker::run(FUNC tar_loop_func){
        
        area.loop_func = tar_loop_func;
        if( timeout_interval != 0 ){
            Glib::signal_timeout().connect(
                sigc::mem_fun(*this, &Capr::C_picker::on_timeout), timeout_interval);
        }
        
        area.show();
        launcher.app->run(window);

    }

    void C_picker::set_default_size(uint w = 0, uint h = 0){
        window.set_default_size(w, h);
    }

    void C_picker::set_loop(uint interval) {
        timeout_interval = interval;
    }

    void C_picker::set_key_input(void(*tar_key_press)(uint), void(*tar_key_release)(uint)) {
        key_press = tar_key_press;
        key_release = tar_key_release;

        window.signal_key_press_event().connect(
            sigc::mem_fun(*this, &Capr::C_picker::on_key_press_event) );
        window.signal_key_release_event().connect(
            sigc::mem_fun(*this, &Capr::C_picker::on_key_release_event) );

    }

    void C_picker::set_motion_input(void(*tar_mouse_motion)(uint, uint)){

        mouse_motion = tar_mouse_motion;

        window.signal_motion_notify_event().connect(
            sigc::mem_fun(*this, &Capr::C_picker::on_motion_notify_event) );


        window.add_events(Gdk::POINTER_MOTION_MASK);
    }

    void C_picker::set_button_input(void(*tar_button_press)(uint, uint, uint), void(*tar_button_release)(uint, uint, uint)){
        button_press = tar_button_press;
        button_release = tar_button_release;

        window.signal_button_press_event().connect(
            sigc::mem_fun(*this, &Capr::C_picker::on_button_press_event) );
        window.signal_button_release_event().connect(
            sigc::mem_fun(*this, &Capr::C_picker::on_button_release_event) );
    }

    void C_picker::write_to_png(std::string filename){

        Cairo::RefPtr<Cairo::ImageSurface> surface =
            Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, w(), h());

        Cairo_cont cr = Cairo::Context::create(surface);
        area.on_draw(cr);
        surface->write_to_png(filename);
        printf("write_to_png : %s\n", filename.c_str());

    }

    uint C_picker::w() { return window.get_width();  }
    uint C_picker::h() { return window.get_height(); }

    bool C_picker::on_timeout() {
        area.queue_draw();
        return true;
    }

    bool C_picker::on_key_press_event(GdkEventKey * event){
        if(key_press != NULL) key_press(event->keyval);
        return true;
    }

    bool C_picker::on_key_release_event(GdkEventKey * event){
        if(key_release != NULL) key_release(event->keyval);
        return true;
    }

    bool C_picker::on_motion_notify_event(GdkEventMotion * event){
        if(mouse_motion != NULL) mouse_motion(event->x, event->y);
        return true;
    }

    bool C_picker::on_button_press_event(GdkEventButton * event){
        if(button_press != NULL) button_press(event->button, event->x, event->y);
        return true;
    }

    bool C_picker::on_button_release_event(GdkEventButton * event){
        if(button_release != NULL) button_release(event->button, event->x, event->y);
        return true;
    }
    
}
