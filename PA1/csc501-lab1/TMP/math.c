#include <stdio.h>
#include <math.h>
#define RAND_MAX 077777


double pow(double base, double exponent){
	if(exponent < 0){
		return pow((1/base), exponent);
	}
	
	int i;

	double ans = 1;
	for(i = 1;i <= exponent; i++){
		ans = base * ans;
	}

	return ans;
}



double log(double x){
//	kprintf("In : log () \n");
	double ans = 0;
        double numerator = -1.0;
        int i;
        for(i = 1;i <= 20;i++){
                numerator = (-1.0) * numerator * (x - 1);
                ans = ans + (numerator / i);
        }
// 	kprintf("Exiting : log () \n");
        return ans;
}


 double expdev(double lambda){

        double ans = 0;
        double numerator = -1.0;
        int i;
	double dummy;
	double answer;
	do{
		dummy = (double)rand() / RAND_MAX;
	}while(dummy == 0.0);
	ans = -1 *(log(dummy) / lambda);
	
	return (ans);
}

