//
//  main.cpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    
    srand((unsigned) time(NULL));
    Game g;
    g.start();
    
    return 0;
}
