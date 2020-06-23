
#include "../src/cairo_picker.hpp"

Capr::C_canvas canvas;
Capr::Function::C_picture pic;

void func(Capr::Cairo_cont cr){

    pic.open_file("./examples/lena.png");
    pic.set_picture(cr, 0, 0, 400, 400);
    cr->paint();

}

int main(){
    canvas.set_default_size(400,400);
    canvas.set_loop(0);
    
    canvas.run(func);
}