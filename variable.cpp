#include "variable.h"
string type_str[8]={"int","float","str","list","fun","None","left","leftlist"};
variable::variable(){
	this->anony = false;
	type=TYPE_NONE;
	value=NULL;
	this->size = 1;
}
variable::variable(float n, bool anonymous ) {
	this->type = TYPE_FLOAT;
	this->anony = anonymous;
	this->value = new float(n);
}

variable::variable(int n, bool anonymous ) {
	this->type = TYPE_INT;
	this->anony = anonymous;
	this->value = new int(n);
}
variable::variable(string str, bool anonymous ){
	this->type=TYPE_STR;
	this->anony = anonymous;
	this->value=new string(str);
	this->size = 0;
}
variable::variable(variable *var, bool anonymous ) {
	this->type = var->type;
	this->anony = anonymous;
	if (this->type == TYPE_INT)
			this->value = new int(*((int*)var->value));
	else if (this->type==TYPE_FLOAT)
			this->value = new float(*((float*)var->value));
	else this->value = var->value;
	size = var->size;
}
variable::variable(variable** add){
	this->type=TYPE_LEFT;
	this->anony=true;
	this->value=add;
}

variable::variable(variable*** add,int n){
	this->type=TYPE_LEFTLIST;
	this->anony=true;
	this->size=n;
	this->value=add;
}


variable::variable(variable **a,int n,bool anonymous){
	this->type=TYPE_LIST;
	this->size=n;
	this->anony = anonymous;
	this->value = a;
}
void  variable::print(bool b) {
if(this==0) {cout<<"error print"<<endl; return;}
	if (this->type==TYPE_FLOAT)
			cout<<*((float*)this->value);
		else if (this->type==TYPE_INT)
			cout<<*((int*)this->value);
	else if (this->type==TYPE_STR)
		cout<<'"'<<*((string*)this->value)<<'"';
	else if (this->type==TYPE_LIST){
		cout<<"[";
			if (size!=0){
				if (((variable**)value)[0] == this) cout<<"[...]";
				else(*(variable**)value)->print(false);
			for (int i = 1; i < size ; i++){
				cout<<",";
				if (((variable**)value)[i] == this) cout<<"[...]";
				else(*((variable**)value+i))->print(false);
			}
		}
		cout<<"]";
	}
	else if (this->type==TYPE_NONE){
		cout<<"None";
	}
	if (b) cout<<endl;
}
variable::~variable(){
	//cout << type<<"variable deconstructor start" << endl;
	//print();
	if (type==TYPE_FLOAT)
			delete((float*)value);
		else if (type==TYPE_INT)
			delete((int*)value);
}

void variable::deleteannoy(variable* var) {
	if (var->anony)
		delete var;
}

variable* variable::add(variable* var1, variable* var2) {
	if (((var1->type == TYPE_INT)||(var1->type == TYPE_FLOAT)) && ((var2->type == TYPE_INT) || (var2->type == TYPE_FLOAT))) {
		if ((var1->type==TYPE_INT) && (var2->type==TYPE_INT)) {
			//cout<<"int"<<*((int*)(var1->value)) + *((int*)(var2->value));
			return new variable(*((int*)(var1->value)) + *((int*)(var2->value)));
		}
		else {
			float f1, f2;
			if (var1->type==TYPE_FLOAT)
				f1 = (float)(*(float*)(var1->value));
			else
				f1 = (float)(*(int*)(var1->value));
			if (var2->type == TYPE_FLOAT)
				f2 = (float)(*(float*)(var2->value));
			else
				f2 = (float)(*(int*)(var2->value));
			return new variable(f1 + f2);
		}
	}
	if ((var1->type == TYPE_LIST) && (var2->type == TYPE_LIST)) {
		variable **l = new variable * [var1->size + var2->size];
		variable** l1 = (variable**)var1->value;
		variable** l2= (variable**) var2->value;
		for (int i = 0; i < var1->size; i++) {
			l[i] = l1[i];
		}
		for (int i = 0; i < var2->size; i++) {
			l[var1->size + i] = l1[i];
		}
		return new variable(l, var1->size + var2->size);
	}
	if ((var1->type == TYPE_STR) && (var2->type == TYPE_STR)) {
		return new variable(*((string*)(var1->value)) + *((string*)(var2->value)));
	}
}

variable* variable::sub(variable* var1, variable* var2)
{
	if (((var1->type == TYPE_INT) || (var1->type == TYPE_FLOAT)) && ((var2->type == TYPE_INT) || (var2->type == TYPE_FLOAT))) {
		if ((var1->type == TYPE_INT) && (var2->type == TYPE_INT)) {
			return new variable(*((int*)(var1->value)) - *((int*)(var2->value)));
		}
		else {
			float f1, f2;
			if (var1->type == TYPE_FLOAT)
				f1 = (float)(*(float*)(var1->value));
			else
				f1 = (float)(*(int*)(var1->value));
			if (var2->type == TYPE_FLOAT)
				f2 = (float)(*(float*)(var2->value));
			else
				f2 = (float)(*(int*)(var2->value));
			return new variable(f1 - f2);
		}
	}
}

variable* variable::mul(variable* var1, variable* var2) {
	if (((var1->type == TYPE_INT) || (var1->type == TYPE_FLOAT)) && ((var2->type == TYPE_INT) || (var2->type == TYPE_FLOAT))) {
		if ((var1->type == TYPE_INT) && (var2->type == TYPE_INT)) {
			return new variable(*((int*)(var1->value)) * *((int*)(var2->value)));
		}
		else {
			float f1, f2;
			if (var1->type == TYPE_FLOAT)
				f1 = (float)(*(float*)(var1->value));
			else
				f1 = (float)(*(int*)(var1->value));
			if (var2->type == TYPE_FLOAT)
				f2 = (float)(*(float*)(var2->value));
			else
				f2 = (float)(*(int*)(var2->value));
			return new variable(f1 * f2);
		}
	}
	if ((var1->type == TYPE_LIST) && (var2->type == TYPE_INT)) {
		variable** l = new variable * [var1->size*(*(int*)var2->value)];
		variable** l1 = (variable**)var1->value;
		for (int i = 0; i < *(int*)var2->value; i++) {
			for (int j = 0; j < var1->size; j++) {
				l[i * var1->size + j] = l1[j];
			}
		}
		return new variable(l, var1->size * (*(int*)var2->value));
	}
	if ((var1->type == TYPE_STR) && (var2->type == TYPE_INT)) {
		string tep;
		tep = "";
		for (int i = 0; i < *(int*)var2->value; i++) {
			tep = tep + *(string*)var1->value;
		}
		return new variable(tep);
	}
}
variable* variable::div(variable* var1, variable* var2)
{
	float f1, f2;
	if (var1->type == TYPE_FLOAT)
		f1 = (float)(*(float*)(var1->value));
	else
		f1 = (float)(*(int*)(var1->value));
	if (var2->type == TYPE_FLOAT)
		f2 = (float)(*(float*)(var2->value));
	else
		f2 = (float)(*(int*)(var2->value));
	return new variable(f1/f2);
}

variable* variable::mod(variable* var1, variable* var2)
{
	if (((var1->type == TYPE_INT) || (var1->type == TYPE_FLOAT)) && ((var2->type == TYPE_INT) || (var2->type == TYPE_FLOAT))) {
		if ((var1->type == TYPE_INT) && (var2->type == TYPE_INT)) {
			return new variable(*((int*)(var1->value)) % *((int*)(var2->value)));
		}
		else {
			float f1, f2;
			if (var1->type == TYPE_FLOAT)
				f1 = (float)(*(float*)(var1->value));
			else
				f1 = (float)(*(int*)(var1->value));
			if (var2->type == TYPE_FLOAT)
				f2 = (float)(*(float*)(var2->value));
			else
				f2 = (float)(*(int*)(var2->value));
			return new variable(f1 -(float)(int)(f1/f2));
		}
	}
}

variable* variable::at(variable* var1, variable* var2) {
	if ((var1->type == TYPE_LIST) && (var2->type == TYPE_INT)) {
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < var1->size)) {
			return ((variable**)var1->value)[*(int*)var2->value];
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
	}
	
}


variable* variable::leftat(variable* var1, variable* var2) {
	if ((var1->type == TYPE_LIST) && (var2->type == TYPE_INT)) {
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < var1->size)) {
			return new variable (&((variable**)var1->value)[*(int*)var2->value]);
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
	}
	
}

variable* variable::slice(variable* var1, variable* var2,variable* var3,variable* var4) {

	if ((var1->type == TYPE_LIST) && ((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT)) {
		int numl;
		int numh;	
		int step ;
		step= *((int*)(var4->value));
	if (step == 0) {
		return 0;
	}
	if (var2->type == TYPE_NONE) {
			if (step > 0)
				numl = 0;
			else
				numl =var1->size-1;
		}
		else {
			numl = *(int*)var2->value;
			if (numl>var1->size-1) numl=var1->size-1;
			if (numl<-var1->size) numl=0;
			if (numl<0) numl=numl+var1->size;

		}

		if (var3->type == TYPE_NONE) {
			if (step > 0)
				numh = var1->size;
			else
				numh =-1;
		}
		else {
			numh=*(int*)var3->value;
			if (numh>var1->size) numh=var1->size;
			if(numh<-var1->size-1) numh=-1;
			if (numh<0) numh=numh+var1->size;

		}
		//cout<<numl<<","<<numh<<"s"<<step<<endl;
		
		if ((numh - numl) * step <= 0) {
			variable** t = 0;
			return new variable(t, 0);
		}
		int count = 0;
		int tep = numl;
		while (((numh - tep) * step > 0)&&(count>=0)&&(count<var1->size)) {
			tep += step;
			count++;
		}
		variable** l = new variable * [count];
		for (int i = 0; i < count; i++) {
			l[i] = ((variable**)var1->value)[numl + i * step];
		}
		return new variable(l, count);

	}
}

variable* variable::leftslice(variable* var1, variable* var2,variable* var3,variable* var4) {
	if ((var1->type == TYPE_LIST) && ((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT)) {
		int numl;
		int numh;	
		int step ;
		step= *((int*)(var4->value));
	if (step == 0) {
		return 0;
	}
	if (var2->type == TYPE_NONE) {
			if (step > 0)
				numl = 0;
			else
				numl =var1->size-1;
		}
		else {
			numl = *(int*)var2->value;
			if (numl>var1->size-1) numl=var1->size-1;
			if (numl<-var1->size) numl=0;
			if (numl<0) numl=numl+var1->size;

		}

		if (var3->type == TYPE_NONE) {
			if (step > 0)
				numh = var1->size;
			else
				numh =-1;
		}
		else {
			numh=*(int*)var3->value;
			if (numh>var1->size) numh=var1->size;
			if(numh<-var1->size-1) numh=-1;
			if (numh<0) numh=numh+var1->size;

		}
		//cout<<numl<<","<<numh<<"s"<<step<<endl;
		
		if ((numh - numl) * step <= 0) {
			return 0;
		}
		int count = 0;
		int tep = numl;
		while ((numh - tep) * step > 0) {
			tep += step;
			count++;
		}
		variable*** l = new variable** [count];
		for (int i = 0; i < count; i++) {
			l[i] = &((variable**)var1->value)[numl + i * step];
		}
		return new variable(l, count);

	}
}


variable* variable::posop(variable* var)
{
	if (var->type == TYPE_INT) {
		return new variable(*(int*)var->value);
	}
	if (var->type == TYPE_FLOAT) {
		return new variable(*(float*)var->value);
	}
}
variable* variable::negop(variable* var)
{
	if (var->type == TYPE_INT) {
		return new variable(-*(int*)var->value);
	}
	if (var->type == TYPE_FLOAT) {
		return new variable(-*(float*)var->value);
	}
}
