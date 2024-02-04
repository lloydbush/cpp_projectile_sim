#include <iostream>

double f(double t,double y){
	return t*y/9.81;
}

// runge kutta 4 
double rk4(double t,double y,double h){
	double k1=f(t,y),
	       k2=f(t+h/2,y+h*k1/2),
	       k3=f(t+h/2,y+h*k2/2),
	       k4=f(t+h,y+h*k3);
	
	return (y+h/6*(k1+2*k2+2*k3+k4));
}

/*
int main(){
	double h=0.01,t=0.0,y=0.1;
	std::cout <<"t,y\n";

	for(int i=0;i<10;i++){
		std::cout<<t<<","<<y<<"\n";
		y+=rk4(t,y,h);
		t+=h;
	}

	return 0;
}
*/

