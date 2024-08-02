#include "header.h"

// set projectile variable
int setVar(projectile &p,std::string var,std::string num){
	double numDbl=std::stod(num); // convert string num to double numDbl
	std::cout << "setVar(" << "p," << var << "," << num << ")\n";
	
	if(var=="m"){p.m=numDbl;}
	else if(var=="cd"){p.cd=numDbl;}
	else if(var=="ar"){p.ar=numDbl;}
	else if(var=="v0x"){p.v0x=numDbl;}
	else if(var=="v0y"){p.v0y=numDbl;}
	else{std::cout << "ERROR: invalid var in function setVar\n"; return 1;}

	return 0;
}

// set environment variable
int setVar(environment &e,std::string var,std::string num){
	double numDbl=std::stod(num); // convert string num to double numDbl
	std::cout << "setVar(" << "e," << var << "," << num << ")\n";
	
	if(var=="g"){e.g=numDbl;}
	else if(var=="rho"){e.rho=numDbl;}
	else if(var=="dt"){e.dt=numDbl;}
	else{std::cout << "ERROR: invalid var in function setVar\n"; return 1;}

	return 0;
}

// READ ENVIRONMENT
int readEnv(environment &e){
	std::ifstream env("environment.cfg");

	// check for env
	if(!env){
		std::cout << "ERROR: can\'t open file \"environment.cfg\"\n";
		return 1;
	}

	std::string envStr;
	std::vector<std::string> envVec;

	// read file and push to vector
	while(getline(env,envStr)){
		// std::cout << envStr << "\n";
		envVec.push_back(envStr);
	}

	env.close(); // close file "environment.cfg"

	// remove comments from .cfg file
	std::string text;

	for(size_t i=0;i<envVec.size();i++){ // for text in envVec
		text=envVec.at(i);

		// check for the '#' character as a comment delimiter
		for(size_t j=0;j<text.size();j++){ // for char in text
			if(text[j]=='#'){
				text.erase(j); // erase chars after and including comment delimeter
			}
            else if(text[j]=='='){
                if(text[j+1]==' '){
                    text.erase(j+1,1);
                }

                if(text[j-1]==' '){
                    text.erase(j-1,1);
                }
            }
		}

		// check for the '=' char and read number till ' ' character
		for(size_t j=0;j<text.size();j++){ // for char in text
			if(text[j]=='='){ // check for '=' char
				std::string var;

				// add chars from 0 to '=' to var
				for(size_t k=0;k<j;k++){
					var+=text[k];
				}

				std::string num;

				// add chars from after '=' to ' ' or eol or '#' to num
				for(size_t k=1;j+k<text.size() && text[j+k]!=' ' && text[j+k]!='#';k++){
					num+=text[j+k];
					// std::cout << j << " + " << k << " = " << num << "\n";
					k++;
				}

				setVar(e,var,num); // char target ('e' for env and 'p' for projectile)
						     // std::string var (variable name)
						     // std::string num (number value will be converted)

				// std::cout << j << ": " << var << " = " << num << "\n";
			}

		}

		envVec.at(i)=text; // replace old text (with comment) with new text (without comment)
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
int readProj(projectile &p){
	std::ifstream proj("projectile.cfg");

	// check for proj
	if(!proj){
		std::cout << "ERROR: can\'t open file \"projectile.cfg\"\n";
		return 1;
	}

	std::string projStr;
	std::vector<std::string> projVec;

	// read file and push to vector
	while(getline(proj,projStr)){
		// std::cout << projStr << "\n";
		projVec.push_back(projStr);
	}

	proj.close(); // close file "projectile.cfg"

	// remove comments from .cfg file
	std::string text;

	for(size_t i=0;i<projVec.size();i++){ // for text in projVec
		text=projVec.at(i);

		// check for the '#' character as a comment delimiter
		for(size_t j=0;j<text.size();j++){ // for char in text
			if(text[j]=='#'){
				text.erase(j); // erase chars after and including comment delimeter
			}
            else if(text[j]=='='){
                if(text[j+1]==' '){
                    text.erase(j+1,1);
                }

                if(text[j-1]==' '){
                    text.erase(j-1,1);
                }
            }
		}

		// check for the '=' char and read number till ' ' character
		for(size_t j=0;j<text.size();j++){ // for char in text
			if(text[j]=='='){ // check for '=' char
				std::string var;

				// add chars from 0 to '=' to var
				for(size_t k=0;k<j;k++){
					var+=text[k];
				}

				std::string num;

				// add chars from after '=' to ' ' or eol or '#' to num
				for(size_t k=1;j+k<text.size() && text[j+k]!=' ' && text[j+k]!='#';k++){
					num+=text[j+k];
					// std::cout << j << " + " << k << " = " << num << "\n";
					k++;
				}

				setVar(p,var,num); // char target ('e' for env and 'p' for projectile)
						     // std::string var (variable name)
						     // std::string num (number value will be converted)

				// std::cout << j << ": " << var << " = " << num << "\n";
			}

		}

		projVec.at(i)=text; // replace old text (with comment) with new text (without comment)
	}
	
	/*
	// print out new vector
	for(int i=0;i<projVec.size();i++){
		std::cout << projVec.at(i) << "\n";
	}
	*/

	return 0;
}

