#include "header.h"
#include "projectile.h"
#include "environment.h"

int main(int argc,char *argv[]){
	std::string file=argv[1];

	double g=e.g, //e
	       m=p.m, //p
	       rho=e.rho, //e
	       cd=p.cd, //p
	       ar=p.ar, //p
	       dt=e.dt, //e

	       v0x=p.v0x, //p
	       v0y=p.v0y, //p

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
		listT.push_back(t);
		listX.push_back(x);
		listY.push_back(y);
		listVx.push_back(vx);
		listVy.push_back(vy);
		listAx.push_back(ax);
		listAy.push_back(ay);

		t+=dt;

		v0x=vx;
		v0y=vy;

		x0=v0x*dt;

		if(x<(x+x0)){
			maxX=x+x0;
		}

		x+=x0;

		y0=v0y*dt;

		if(y<(y+y0)){
			maxY=y+y0;
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
	printAndWrite(listT,listX,listY,listVx,listVy,listAx,listAy,maxX,maxY,file);

	return 0;
}

