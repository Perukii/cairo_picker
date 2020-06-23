
#include <iostream>

namespace Capr::Function{

    class C_picture {
        Glib::RefPtr< Gdk::Pixbuf > pixbuf;
    public:
        C_picture(){

        }

        void open_file(std::string file){
            pixbuf = Gdk::Pixbuf::create_from_file(file);
        }
        
        void set_picture(Capr::Cairo_cont cr, double x, double y, double w, double h){
            Gdk::Cairo::set_source_pixbuf( cr, pixbuf->scale_simple( w, h, Gdk::INTERP_NEAREST ), x, y );
        }

        double w(){ return pixbuf->get_width();  }
        double h(){ return pixbuf->get_height(); }


    };

}

