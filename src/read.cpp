// Copyright 2024 lorax
#include "./header.h"

// set projectile variable
int setVar(projectile &p, std::string var, std::string num) {
    double numDbl = std::stod(num);  // convert string num to double numDbl
    std::cout << "setVar(" << "p," << var << "," << num << ")\n";

    if (var == "m") p.m=numDbl;
    else if (var == "cd") p.cd=numDbl;
    else if (var == "ar") p.ar=numDbl;
    else if (var == "v0x") p.v0x=numDbl;
    else if (var == "v0y") p.v0y=numDbl;
    else if (var == "x0") p.x0=numDbl;
    else if (var == "y0") p.y0=numDbl;
    else {std::cout << "ERROR: invalid var in function setVar\n"; return 1;}

    return 0;
}

// set environment variable
int setVar(environment &e,std::string var,std::string num){
    double numDbl = std::stod(num);  // convert string num to double numDbl
    std::cout << "setVar(" << "e," << var << "," << num << ")\n";

    if (var == "g") e.g=numDbl;
    else if (var == "rho") e.rho=numDbl;
    else if (var == "dt") e.dt=numDbl;
    else{std::cout << "ERROR: invalid var in function setVar\n"; return 1;}

    return 0;
}

// READ ENVIRONMENT
int readEnv(environment &e){
    std::ifstream env("environment.cfg");

    // check for env
    if (!env) {
        std::cout << "ERROR: can\'t open file \"environment.cfg\"\n";
        return 1;
    }

    std::string envStr;
    std::vector<std::string> envVec;

    // read file and push to vector
    while (getline(env, envStr)) {
        // std::cout << envStr << "\n";
        envVec.push_back(envStr);
    }

    env.close();  // close file "environment.cfg"

    // remove comments from .cfg file
    std::string text;
    std::string new_text;

    for (size_t i = 0; i < envVec.size(); i++) {  // for text in envVec
        text = envVec.at(i);
        new_text = "";

        bool hasEqual = false;  // has there been an equal sign yet?

        for (char c : text) {
            if (c == '#') break;
            else if (c != ' ') new_text+=c;

            if (c == '=') hasEqual = true;
        }

        if (!hasEqual) continue;

        text = new_text;
        DEBUG_MSSG("new_text=" << new_text)

        // check for the '=' char and read number till ' ' character
        for (size_t j = 0; j < text.size(); j++) {  // for char in text
            if (text[j] == '=') {  // check for '=' char
                std::string var;

                // add chars from 0 to '=' to var
                for (size_t k = 0; k < j; k++) {
                    var+=text[k];
                }

                DEBUG_MSSG("var=" << var)

                std::string num;

                // add chars from after '=' to num
                for (size_t k = 1; j+k < text.size(); k++) {
                    num+=text[j+k];
                    DEBUG_MSSG(j << " + " << k << " : " << num);
                }

                DEBUG_MSSG("num=" << num)

                // char target ('e' for env and 'p' for projectile)
                // std::string var (variable name)
                // std::string num (number value will be converted)
                setVar(e, var, num);

                // std::cout << j << ": " << var << " = " << num << "\n";
            }
        }

        // replace old text (with comment) with new text (without comment)
        envVec.at(i) = text;
    }

    /*
    // print out new vector
    for(int i=0;i<envVec.size();i++){
        std::cout << envVec.at(i) << "\n";
    }
    */

    return 0;
}

// READ PROJECTILE
int readProj(projectile &e){
    std::ifstream proj("projectile.cfg");

    // check for proj
    if (!proj) {
        std::cout << "ERROR: can\'t open file \"projectile.cfg\"\n";
        return 1;
    }

    std::string projStr;
    std::vector<std::string> projVec;

    // read file and push to vector
    while (getline(proj, projStr)) {
        // std::cout << projStr << "\n";
        projVec.push_back(projStr);
    }

    proj.close();  // close file "projectile.cfg"

    // remove comments from .cfg file
    std::string text;
    std::string new_text;

    for (size_t i = 0; i < projVec.size(); i++) {  // for text in projVec
        text = projVec.at(i);
        new_text = "";

        bool hasEqual = false;  // has there been an equal sign yet?

        for (char c : text) {
            if (c == '#') break;
            else if (c != ' ') new_text+=c;

            if (c == '=') hasEqual = true;
        }

        if (!hasEqual) continue;

        text = new_text;
        DEBUG_MSSG("new_text=" << new_text)

        // check for the '=' char and read number till ' ' character
        for (size_t j = 0; j < text.size(); j++) {  // for char in text
            if (text[j] == '=') {  // check for '=' char
                std::string var;

                // add chars from 0 to '=' to var
                for (size_t k = 0; k < j; k++) {
                    var+=text[k];
                }

                DEBUG_MSSG("var=" << var)

                std::string num;

                // add chars from after '=' to num
                for (size_t k = 1; j+k < text.size(); k++) {
                    num+=text[j+k];
                    DEBUG_MSSG(j << " + " << k << " : " << num);
                }

                DEBUG_MSSG("num=" << num)

                // char target ('e' for proj and 'p' for projectile)
                // std::string var (variable name)
                // std::string num (number value will be converted)
                setVar(e, var, num);

                // std::cout << j << ": " << var << " = " << num << "\n";
            }
        }

        // replace old text (with comment) with new text (without comment)
        projVec.at(i) = text;
    }

    /*
    // print out new vector
    for(int i=0;i<projVec.size();i++){
        std::cout << projVec.at(i) << "\n";
    }
    */

    return 0;
}

