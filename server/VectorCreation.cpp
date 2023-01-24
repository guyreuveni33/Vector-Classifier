#include "VectorCreation.h"
#include "MasterDistance.h"
#include <iostream>
#include <sstream>

int numCheck(string s) {
    int i, flag = 0, flag2 = 0, eflag = 0;
    // This is checking if the first character is a digit or a minus sign.
    if (!isdigit(s.at(0)) && (s.at(0) != 45) && (s.at(0) != 46)) {
        return 0;
    }
    // This is checking if the string is a number.
    for (i = 0; i < s.size(); i++) {
        if ((s.at(0) == 45) && (s.size() > 1) && flag2 == 0) {
            flag2 = 1;
            continue;
        }
        // This is checking if the string contains E or e and if is in the right format.
        if (s.at(i) == 'E' || s.at(i) == 'e') {
            if (i == s.size() - 1) {
                return 1;
            }
            if (s.at(i + 1) == '-' || s.at(i + 1) == '+') {
                i++;
                continue;
            }
            if (isdigit(s.at(i + 1))) {
                continue;
            }
        }
        if (!(isdigit(s.at(i)))) {
            if (s.at(i) == 46) {
                if (i == s.size() - 1) {
                    return 0;
                }
                flag++;
                continue;
            }
            // Check for E or e, which indicates a scientific notation number
            if (s.at(i) == 'E' || s.at(i) == 'e') {
                eflag = 1;
                continue;
            }
            return 0;
        }
        if (flag >= 2 || eflag >= 2) {
            return 0;
        }
    }
    // Check the actual representation of the number without the E or e
    if (eflag == 1) {
        string rep = s.substr(0, s.find('E'));
        rep += s.substr(s.find('E') + 1);
        if (numCheck(rep) == 0) {
            return 0;
        }
    }
    return 1;
}
