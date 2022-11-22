#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include "Slot.h"
#include "TTM.h"
#include "BaseMenu.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>
#include <queue>

#define students_classes "../students_classes.csv"
#define classes "../classes.csv"
using namespace std;
using namespace TTM;


int main() {
    BaseMenu::displayBaseMenu();
    cout << "End";

    return 0;
}
