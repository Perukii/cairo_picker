
#include "../src/cairo_picker.hpp"

Capr::C_picker picker;
Capr::Function::C_picture pic;

void func(Capr::Cairo_cont cr){

    pic.open_file("./examples/lena.png");
    pic.set_picture(cr, 0, 0, 400, 400);
    cr->paint();

}

int main(){
    picker.set_default_size(400,400);
    picker.set_loop(0);
    
    picker.run(func);
}