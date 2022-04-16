//
// Created by Admin on 4/11/2022.
//

#include "Alpha.h"
//c`tors:
Alpha::Alpha(){
}
Alpha::Alpha(std::string s) : SARS_COV_2(s) {

}

void Alpha::printHey() {
    std::cout << "Hello, World! from Alpha "<< this->getATCG() << std::endl;
}


