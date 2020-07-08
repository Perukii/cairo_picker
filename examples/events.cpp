
#include "../src/cairo_picker.hpp"
#include <iostream>

Capr::C_picker picker;
Capr::Function::C_picture pic;

void press(uint keyval){
    if (keyval==GDK_KEY_1) std::cout<<"key pressed"<<std::endl;
}

void release(uint keyval){
    if (keyval==GDK_KEY_1) std::cout<<"key released"<<std::endl;
}

void motion(uint x, uint y){
    std::cout<<"motioned"<<std::endl;
}

void bpress(uint button, uint x, uint y){
    if(button == 1) std::cout<<"button pressed"<<std::endl;
}

void brelease(uint button, uint x, uint y){
    if(button == 1) std::cout<<"button released"<<std::endl;
}

void func(Capr::Cairo_cont cr){

}

int main(){
    picker.set_default_size(400,400);
    picker.set_loop(1);
    picker.set_title("sss");
    picker.set_key_input(press, release);
    picker.set_motion_input(motion);
    picker.set_button_input(bpress, brelease);

    picker.run(func);
}