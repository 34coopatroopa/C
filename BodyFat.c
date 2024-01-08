#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int adult;


int main(){
	int gender;
	double weight;
	double height;
	int age;
	int adult;
	printf("Are you an adult 1 for yes 0 for no: ");
	scanf("%d",&adult);
	while(adult == 1){
		printf("Enter your Age: ");
		scanf("%d", &age);
		printf("Are you M/F ?\n");
		printf("Please Enter 0 for Female, or 1 for Male: ");
		scanf("%d", &gender);
		printf("Enter your weight in kg: ");
		scanf("%lf",&weight);
		printf("Enter your height in meters: ");
		scanf("%lf", &height);
	
		double bmi = weight/(height*height);
	
		double percent = (1.39 * bmi) + (0.16 * age) - (10.34 * gender) - 9 ;
	
		
		if(gender == 1){//male
			if(age >= 20 && age <= 39){
				if(percent > 25.0 ){
					printf("Your Body Fat Percentage is HIGH\n");
					printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 19.0){
					printf("Your Body Fat Percentage is ABOVE Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
			}else if( age >= 40 && age <= 59){
				if(percent > 28.0 ){
					printf("Your Body Fat Percentage is HIGH\n");
					printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 22.0){
					printf("Your Body Fat Percentage is Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
				}else if( age >=60 && age <= 79){
					if(percent > 30.0 ){
						printf("Your Body Fat Percentage is HIGH\n");
						printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 25.0){
					printf("Your Body Fat Percentage is Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
			}
		}else if(gender == 0){//female
			if(age >= 20 && age <= 39){
				if(percent > 39.0 ){
					printf("Your Body Fat Percentage is HIGH\n");
					printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 33.0){
					printf("Your Body Fat Percentage is Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
			}else if( age >= 40 && age <= 59){
				if(percent > 40.0 ){
					printf("Your Body Fat Percentage is HIGH\n");
					printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 35.0){
					printf("Your Body Fat Percentage is Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
			}else if( age >=60 && age <= 79){
				if(percent > 42.0 ){
					printf("Your Body Fat Percentage is HIGH\n");
					printf("YOUR HEALTH MAY BE AT RISK SEEK ADVICE");
				
				}else if( percent > 36.0){
					printf("Your Body Fat Percentage is Average\n");
					printf("MAKE AN HONEST ASSESMENT OF YOUR DIET AND EXERCISE");
				}else{
					printf("Your Body Fat Percentage is NORMAL\n");
					printf("MAINTAIN A HEALTHY DIET AND EXERCISE REGIME");
				}
			}
		}
		break;
	}	

} 
