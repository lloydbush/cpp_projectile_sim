#include "header.h"

int main(){

	double g=-9.81,
	       m=1.0,
	       rho=1.22,
	       cd=0.47,
	       ar=0.078,
	       dt=0.01,

	       v0x=0.0,
	       v0y=0.0,

	       x0=0.0,
	       y0=0.0,

	       t=0.0,

	       x=x0,
	       y=y0,

	       vx=v0x,
	       vy=v0y,

	       ax=0.0,
	       ay=0.0,

	       fx=0.0,
	       fy=0.0,

	       fg=0.0,

	       fdx=0.0,
	       fdy=0.0,

	       maxX=0.0,
	       maxY=0.0;

	std::vector<double> 
		listT,

		listX,
		listY,

		listVx,
		listVy,

		listAx,
		listAy;

	std::cout<<"hello world"<<std::endl;

	while(y>=0.0){
		printAndWrite(listT,listX,listY,listVx,listVy,listAx,listAy);

		t+=dt;

		v0x=vx;
		v0y=vy;

		x0=v0x*dt;

		if(x<(x+x0)){
			maxX=x+x0;
		}

		y0=v0y*dt;

		if(y<(y+y0)){
			maxY=x+x0;
		}

		y+=y0;

		fg=m*g;

		if(vx>0.0){
			fdx=-0.5*rho*cd*vx*vx*ar;
		}
		else{
			fdx=0.5*rho*cd*vx*vx*ar;
		}

		if(vy>0.0){
			fdy=-0.5*rho*cd*vy*vy*ar;
		}
		else{
			fdy=0.5*rho*cd*vy*vy*ar;
		}

		fx=fdx;
		fy=fdy+fg;

		ax=fx/m;
		ay=fy/m;

		v0x=ax*dt;
		v0y=ay*dt;

		vx+=v0x;
		vy+=v0y;
	}

	return 0;
}

