
#include "../src/cairo_picker.hpp"

Capr::C_canvas canvas;                      // canvas

int x = 0;

void func(Capr::Cairo_cont cr){             // drawing context
    cr->set_source_rgba(1.0, 1.0, 1.0, 1.0);
    cr->paint();
    
    cr->set_source_rgba(1.0, 0.0, 0.0, 0.5);
    cr->rectangle(x++,100,150,150);
    cr->fill();
}

int main(){
    canvas.set_default_size(400,400);       // set window's default size ( 400x400 )
    canvas.set_timeout(10);                 // update drawing context (interval:10)

    canvas.run(func);                       // run application (function for drawing)
}