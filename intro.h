#pragma once
#include <iostream>
using std::cout;
using std::endl;

void intro() {

    cout << "    _    ____  ____      _ __   ______   ___ ____  _  _   " << endl;
    cout << "   / \\  |  _ \\|  _ \\    / \\\\ \\ / /___ \\ / _ \\___ \\| || |  " << endl;
    cout << "  / _ \\ | |_) | |_) |  / _ \\\\ V /  __) | | | |__) | || |_ " << endl;
    cout << " / ___ \\|  _ <|  _ <  / ___ \\| |  / __/| |_| / __/|__   _|" << endl;
    cout << "/_/   \\_\\_| \\_\\_| \\_\\/_/   \\_\\_| |_____|\\___/_____|  |_|  " << endl;
    std::cout << std::endl << std::endl;




}

void progressbar(size_t a, size_t total) {

    int progress = (a * 100) / total;
    int bars = progress / 4;
    std::string bar = "[";
    for (int i = 0; i < 25; i++) {
        if (i < bars) {
            bar += "/";
        }
        else {
            bar += " ";
        }
    }
    bar += "]";
    cout << bar << " - " << progress << "%" << endl;
    if (progress >= 96 ) {
        cout << "[////////////////////////] - 100%" << endl;
        std::cout << "Sort is successful!" << std::endl;

    }
}
    
