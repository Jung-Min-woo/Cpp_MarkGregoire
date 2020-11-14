#include <iostream>

switch(backgroundColor){
    case Color::DarkBlue:
        doSomethingForDarkBlue();
    [[fallthrough]];
    case Color::Black:
        doSomethingForBlackOrDarkBlue();
        break;
    case Color::Red:
    case Color::Green:
        break;
}