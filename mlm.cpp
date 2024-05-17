#include<iostream>

using namespace std;

//MLM theme lab 12
//add downline later, difficult due to multiple downlines
class Ambassador{
	double fronted;
	Ambassador * upline;
	public:
	int sernum;
	Ambassador();
	~Ambassador();

	Ambassador * getBoss() {return upline; }
	Ambassador * getSernum(int target);
	void setBoss(Ambassador * n) {upline = n; }
	double getReceipt() {return fronted;}
	void setReceipt(double investment) {fronted = investment;}
	double getPaid(Ambassador * member); // this demonstrates more than incValue would

	// methods that could/should be outside the class (the less our "reps" know, the better)
	// oh, I think I understand, the only rep that can call it is the tail, it's the only one with a pointer.
	double People(); //size
	double Money();
	double moneyBelow(Ambassador * member); //this is an inclusive value
	double bestSale(); //largest
	double worstSale(); //smallest
	double aveSale() {return (Money()/People());} //average
	void lineVals();
	void burnout(int sernum);
	void FTCinvolvement(); //clear
	
	//funcitons I want to add
	//Ambassador * spesific(sernum); 

};

Ambassador::Ambassador(){
	static int n = 0;
	sernum = n++;//why can't I say sernum++
	fronted = 0;
	upline = NULL;
}

Ambassador::~Ambassador(){
	delete &sernum;
	delete &fronted;
	delete &upline;
}



void Ambassador::burnout(int target){
	Ambassador * oldboss = NULL;
	for (int i = 0; i < People(); i++){
		if ((upline -> sernum) == target){
			oldboss = upline;
			setBoss(upline -> getBoss());
			delete oldboss;
		}
		else if (sernum == target)
			delete this;
		else if (upline != NULL)
			upline->burnout(target);
		else
			cout << "there is not rep " << sernum << " in this line." << endl;
	}	
}

void Ambassador::FTCinvolvement(){
	if (upline != NULL){
		burnout(upline->sernum);
	}
	delete this;
}

double Ambassador::worstSale(){
	double worst = fronted;
	double next = fronted;
	if (upline != NULL)
		next = upline->worstSale();
	if (worst > next)
		worst = next;
	return worst;
}

double Ambassador::bestSale(){
	double best = fronted;
	double next = fronted;
	if (upline != NULL)
		next = upline->bestSale();
	if (best < next)
		best = next;
	return best;
}

double Ambassador::People(){
	int people_above = 0;
	if (upline != NULL)
		people_above = (upline -> People());
	//cout << (people_above + 1) << endl;
	return people_above + 1;
}

double Ambassador::Money(){//inclusive
	double money = 0;
	if (upline != NULL)
		money += upline -> Money();
	return money + fronted;
}

double Ambassador::moneyBelow(Ambassador * member){//inclusive
	double money = 0;
	//cout << fronted << " -> " << endl; 
	if (sernum != (*member).sernum)
		money += (upline -> moneyBelow(member));
	//cout << (money + fronted) << endl;
	return money + fronted;
}

void Ambassador::lineVals(){
	if (upline != NULL)
		upline -> lineVals();
	cout << "rep" << sernum << " made " << fronted << endl; 
}

double Ambassador::getPaid(Ambassador * target){
	double didhave = target->fronted;
	target->fronted -= 0.35 * moneyBelow(target);
	return didhave;
}

Ambassador * Ambassador::getSernum(int target){
	for (int i = 0; i < People(); i++){
		if (sernum == target)
			return this;
		else if (upline != NULL)
			return upline->getSernum(target);
		else{
			cout << "there is not rep " << target << " in this line." << endl;
			return NULL;
		}
	return NULL;//it kept warning me to throw these extra returns on here
	}	
return NULL;
}

int main(){
	Ambassador * customer;//always at the bottom of the list
	Ambassador * recruiter;
	recruiter = NULL;
	for (int i = 0; i < 4; i++){
		customer = new Ambassador(); //stack has garbage collection;
		customer -> setBoss(recruiter);
		customer -> setReceipt(double ((rand() % 200) - 700));
		recruiter = customer;
	}

	recruiter -> lineVals();
	double ave = recruiter -> aveSale();
	cout << "ave profit is " << ave << endl;
	double worst = recruiter -> worstSale();
	cout << "worst profit is " << worst << endl;
	cout << "best profit is " << recruiter->bestSale() << endl;
	int num_people = customer -> People();
	cout << "there are " << num_people << " people in this line" << endl;


	for (int i = 0; i < num_people; i++){
		recruiter = customer->getSernum(i);
		if (recruiter != NULL){
			double pre_pay = customer -> getPaid(recruiter);//gets paid from customer to recruiter
			cout << "rep" << recruiter->sernum << " was paid " << recruiter->getReceipt() - pre_pay << endl;  
		}
	}	
	recruiter = customer;
	recruiter -> lineVals();

	cout << "rep2 left the company, rep3, you're now the new rep2." << endl;
	cout << "no ideia what free() means, I think I'm good with what I've got though." << endl;
	//cout << "also, I don't
	recruiter -> burnout(2);
	recruiter -> lineVals();
	recruiter -> FTCinvolvement();
	recruiter -> lineVals();
	

	

}
