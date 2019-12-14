#include "variable.h"

string type_str[9]={"int","float","str","list","fun","None","left","leftlist","leftstr"};
variable::variable(){
	this->anony = false;
	type=TYPE_NONE;
	value=NULL;
	this->size = 1;
}
variable::variable(bool b,float t){
	this->type=TYPE_BOOL;
	this->value=new bool(b);
	this->relationnum=t;
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
variable::variable(char* str[SLEN],int n){
	this->type=TYPE_LEFTSTR;
	this->anony = true;
	this->value=new char*[SLEN];
	this->size = n;
        for(int i=0;i<n;i++)
            ((char**)this->value)[i]=str[i];
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
if (this->type==TYPE_SUCCESS) return;
	if (this->type==TYPE_BOOL){
		if (*((bool*)this->value))
			cout<<"True";
		else 
			cout<<"False";
				}
		else if (this->type==TYPE_FLOAT)
			cout<<*((float*)this->value);
		else if (this->type==TYPE_INT)
			cout<<*((int*)this->value);
	else if (this->type==TYPE_BOOL)
		cout<<'"'<<*((bool*)this->value)<<'"';
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

void typeprint(int type){
    putchar('\'');
    if(type==TYPE_INT)printf("int");
    else if(type==TYPE_FLOAT)printf("float");
    else if(type==TYPE_LIST)printf("list");
    else if(type==TYPE_BOOL)printf("bool");
    else printf("string");
    putchar('\'');
}

void typeprint2(int type){
    if(type==TYPE_INT)printf("int");
    else if(type==TYPE_FLOAT)printf("float");
    else if(type==TYPE_LIST)printf("list");
    else if (type==TYPE_BOOL)printf("bool");
    else printf("string");
}

variable* variable::add(variable* var1, variable* var2) {
        if((var1==0)||(var2==0))return 0;
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
	} if(var1->type==TYPE_BOOL){
              if((*(bool*)var1->value)==true){
                     if(var2->type==TYPE_INT)return new variable(1+(*(int*)(var2->value)));
                     if(var2->type==TYPE_FLOAT)return new variable((float)(1+(*(float*)(var2->value))));
                     if(var2->type==TYPE_BOOL){
                           if(*(bool*)var2->value==true)return new variable(2);
                           else return new variable(1);
                     }
               }
              if((*(bool*)var1->value)==false){
                     if(var2->type==TYPE_INT)return new variable((*(int*)(var2->value)));
                     if(var2->type==TYPE_FLOAT)return new variable((*(float*)(var2->value)));
                     if(var2->type==TYPE_BOOL){
                           if(*(bool*)var2->value==true)return new variable(1);
                           else return new variable(0);
                     }
               }
        }
        if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                     if(var1->type==TYPE_INT)return new variable(1+(*(int*)(var1->value)));
                     if(var1->type==TYPE_FLOAT)return new variable((float)(1+(*(float*)(var1->value))));
               }
              else{
                     if(var1->type==TYPE_INT)return new variable((*(int*)(var1->value)));
                     if(var1->type==TYPE_FLOAT)return new variable((*(float*)(var1->value)));
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
			l[var1->size + i] = l2[i];
		}
		return new variable(l, var1->size + var2->size);
	}
	if ((var1->type == TYPE_STR) && (var2->type == TYPE_STR)) {
		return new variable(*((string*)(var1->value)) + *((string*)(var2->value)));
	}
        printf("TypeError: unsupported operand type(s) for +:");
        typeprint(var1->type);
        printf("and");
        typeprint(var2->type);
        putchar('\n');
        return 0;
}

variable* variable::sub(variable* var1, variable* var2)
{
        if((var1==0)||(var2==0))return 0;
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
	if(var1->type==TYPE_BOOL){
              if((*(bool*)var1->value)==true){
                     if(var2->type==TYPE_INT)return new variable(1-(*(int*)(var2->value)));
                     if(var2->type==TYPE_FLOAT)return new variable((float)(1.0-(*(float*)(var2->value))));
                     if(var2->type==TYPE_BOOL){
                           if(*(bool*)var2->value==true)return new variable(0);
                           else return new variable(1);
                     }
               }
              if((*(bool*)var1->value)==false){
                     if(var2->type==TYPE_INT)return new variable(-(*(int*)(var2->value)));
                     if(var2->type==TYPE_FLOAT)return new variable(-(*(float*)(var2->value)));
                     if(var2->type==TYPE_BOOL){
                           if(*(bool*)var2->value==true)return new variable(-1);
                           else return new variable(0);
                     }
               }
        }
        if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                     if(var1->type==TYPE_INT)return new variable((*(int*)(var1->value))-1);
                     if(var1->type==TYPE_FLOAT)return new variable((float)((*(float*)(var1->value))-1.0));
               }
              else{
                     if(var1->type==TYPE_INT)return new variable((*(int*)(var1->value)));
                     if(var1->type==TYPE_FLOAT)return new variable((*(float*)(var1->value)));
               }
        }
        printf("TypeError: unsupported operand type(s) for -:");
        typeprint(var1->type);
        printf("and");
        typeprint(var2->type);
        putchar('\n');
        return 0;
}

variable* variable::mul(variable* var1, variable* var2) {
        if((var1==0)||(var2==0))return 0;
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
	if ((var2->type == TYPE_LIST) && (var1->type == TYPE_INT)) {
		variable** l = new variable * [var2->size*(*(int*)var1->value)];
		variable** l1 = (variable**)var2->value;
		for (int i = 0; i < *(int*)var1->value; i++) {
			for (int j = 0; j < var2->size; j++) {
				l[i * var2->size + j] = l1[j];
			}
		}
		return new variable(l, var2->size * (*(int*)var1->value));
	}
	if ((var2->type == TYPE_STR) && (var1->type == TYPE_INT)) {
		string tep;
		tep = "";
		for (int i = 0; i < *(int*)var1->value; i++) {
			tep = tep + *(string*)var2->value;
		}
		return new variable(tep);
	}
        printf("TypeError: unsupported operand type(s) for *:");
        typeprint(var1->type);
        printf("and");
        typeprint(var2->type);
        putchar('\n');
        return 0;
}
variable* variable::div(variable* var1, variable* var2)
{
	float f1, f2;
        if((var1==0)||(var2==0))return 0;
	if ((var1->type == TYPE_INT) && (var2->type == TYPE_INT)){
               f2 = (int)(*(int*)(var2->value));
               if(f2==0){
                   cout<<"ZeroDivisionError: integer division of modulo by zero"<<endl;
                   return 0;
               }
               f1 = (int)(*(int*)(var1->value));
               return new variable(f1/f2);
        }
	if ((var1->type == TYPE_INT)&&(var2->type == TYPE_FLOAT)){
	       f2 = (float)(*(float*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float division by zero"<<endl;
                    return 0;
               }
               f1 = (float)(*(int*)(var1->value));
               return new variable(f1/f2);
        }
	if ((var1->type == TYPE_FLOAT)&&(var2->type == TYPE_INT)){
	       f2 = (float)(*(int*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float division by zero"<<endl;
                    return 0;
               }
               f1 = (float)(*(float*)(var1->value));
               return new variable(f1/f2);
        }
	if ((var1->type == TYPE_FLOAT)&&(var2->type == TYPE_FLOAT)){
	       f2 = (float)(*(float*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float division by zero"<<endl;
                    return 0;
               }
               f1 = (float)(*(float*)(var1->value));
               return new variable(f1/f2);
        }
        printf("TypeError: unsupported operand type(s) for /:");
        typeprint(var1->type);
        printf("and");
        typeprint(var2->type);
        putchar('\n');
        return 0;
}

variable* variable::mod(variable* var1, variable* var2)
{   
        float f1,f2;
        int t1,t2;
        if((var1==0)||(var2==0))return 0;
	if ((var1->type == TYPE_INT) && (var2->type == TYPE_INT)){
               t2 = (int)(*(int*)(var2->value));
               if(t2==0){
                   cout<<"ZeroDivisionError: integer division of modulo by zero"<<endl;
                   return 0;
               }
               t1 = (int)(*(int*)(var1->value));
               return new variable(t1%t2);
        }
	if ((var1->type == TYPE_INT)&&(var2->type == TYPE_FLOAT)){
	       f2 = (float)(*(float*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float modulo"<<endl;
                    return 0;
               }
               f1 = (float)(*(int*)(var1->value));
               return new variable(f1-((int)(f1/f2))*f2);
        }
	if ((var1->type == TYPE_FLOAT)&&(var2->type == TYPE_INT)){
	       f2 = (float)(*(int*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float modulo"<<endl;
                    return 0;
               }
               f1 = (float)(*(float*)(var1->value));
               return new variable(f1-((int)(f1/f2))*f2);
        }
	if ((var1->type == TYPE_FLOAT)&&(var2->type == TYPE_FLOAT)){
	       f2 = (float)(*(float*)(var2->value));
               if(f2<0.00001){
                    cout<<"ZeroDivisionError: float modulo"<<endl;
                    return 0;
               }
               f1 = (float)(*(float*)(var1->value));
               return new variable(f1-((int)(f1/f2))*f2);
        }
        cout<<"TypeError: unsupported operand type(s) for %:";
        typeprint(var1->type);
        printf("and");
        typeprint(var2->type);
        putchar('\n');
        return 0;
}

variable* variable::at(variable* var1, variable* var2) {
        string h="a";
        if((var1==0)||(var2==0))return 0;
	if (var1->type == TYPE_LIST) {
            if(var2->type == TYPE_INT){
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < var1->size)) {
			return ((variable**)var1->value)[*(int*)var2->value];
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
            }
            else{
                cout<<"TypeError: list indices must be integers,not ";
                typeprint2(var2->type);
                cout<<endl;
                return 0;
            }
	}
	if(var1->type == TYPE_STR) {
            if(var2->type == TYPE_INT) {
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < (*(string*)var1->value).size() )) {    
                        h[0]=(char)(*(string*)var1->value).at(*(int*)var2->value);
			return new variable(h);
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
            }
            else{
                cout<<"TypeError: string indices must be integers,not ";
                typeprint2(var2->type);
                cout<<endl;
                return 0;
            }            
	}
        cout<<"TypeError: ";
        typeprint(var1->type);
	cout<<" object has no attribute \'__getitem__\'"<<endl;
        return 0;
}


variable* variable::leftat(variable* var1, variable* var2) {
        if((var1==0)||(var2==0))return 0;
	if (var1->type == TYPE_LIST){ 
           if(var2->type == TYPE_INT) {
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < var1->size)) {
			return new variable (&((variable**)var1->value)[*(int*)var2->value]);
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
           }
           else{
                cout<<"TypeError: list indices must be integers,not ";
                typeprint2(var2->type);
                cout<<endl;
                return 0;
            }
	}
	if(var1->type == TYPE_STR) {
            if(var2->type == TYPE_INT) {
		if ((*(int*)var2->value >=0)&& (*(int*)var2->value < (*(string*)var1->value).size() )) {    
                        char* l[SLEN];
                        l[0]=&(*(string*)var1->value).at(*(int*)var2->value);
			return new variable(l,1);
		}
		else{
			cout<<"out-of-index exception"<<endl;
			return 0;
		}
            }
            else{
                cout<<"TypeError: string indices must be integers,not ";
                typeprint2(var2->type);
                cout<<endl;
                return 0;
            }            
	}
        cout<<"TypeError: ";
        typeprint(var1->type);
	cout<<" object has no attribute \'__getitem__\'"<<endl;
        return 0;
}

variable* variable::slice(variable* var1, variable* var2,variable* var3,variable* var4) {
        if((var1==0)||(var2==0)||(var3==0)||(var4==0))return 0;
	if (var1->type == TYPE_LIST){
           if(((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT) ){
		int numl;
		int numh;	
		int step ;
		step= *((int*)(var4->value));
	if (step == 0) {
                cout<<"ValueError: slice step cannot be zero"<<endl;
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
            else {
                  cout<<"TypeError:slice indices must be integers or None or have an __index__ method"<<endl;
                  return 0;
            }
	}


	if (var1->type == TYPE_STR){
           if(((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT) ){
                int size;
		int numl;
		int numh;	
		int step ;
                size=(*(string*)var1->value).size();
		step= *((int*)(var4->value));
	if (step == 0) {
                cout<<"ValueError: slice step cannot be zero"<<endl;
		return 0;
	}
	if (var2->type == TYPE_NONE) {
			if (step > 0)
				numl = 0;
			else
				numl =size-1;
		}
		else {
			numl = *(int*)var2->value;
			if (numl>size-1) numl=size-1;
			if (numl<-size) numl=0;
			if (numl<0) numl=numl+size;

		}

		if (var3->type == TYPE_NONE) {
			if (step > 0)
				numh = size;
			else
				numh =-1;
		}
		else {
			numh=*(int*)var3->value;
			if (numh>size) numh=size;
			if(numh<-size-1) numh=-1;
			if (numh<0) numh=numh+size;

		}
		//cout<<numl<<","<<numh<<"s"<<step<<endl;
		
		if ((numh - numl) * step <= 0) {
			string t = "";
			return new variable(t);
		}
		int count = 0;
		int tep = numl;
		while (((numh - tep) * step > 0)&&(count>=0)&&(count<size)) {
			tep += step;
			count++;
		}
		string l(count,'a');
		for (int i = 0; i < count; i++) {
			l[i] = (*(string*)var1->value)[numl + i * step];
		}
		return new variable(l);
            }
            else {
                  cout<<"TypeError:slice indices must be integers or None or have an __index__ method"<<endl;
                  return 0;
            }
	}
        cout<<"TypeError: ";
        typeprint(var1->type);
	cout<<" object has no attribute \'__getitem__\'"<<endl;
        return 0;
}

variable* variable::leftslice(variable* var1, variable* var2,variable* var3,variable* var4) {
	if((var1==0)||(var2==0)||(var3==0)||(var4==0))return 0;
        if (var1->type == TYPE_LIST){
            if(((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT)) {
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
            else {
                  cout<<"TypeError:slice indices must be integers or None or have an __index__ method"<<endl;
                  return 0;
            }
	}

	if (var1->type == TYPE_STR){
           if(((var2->type == TYPE_INT)||(var2->type == TYPE_NONE)) && ((var3->type == TYPE_INT) || (var3->type == TYPE_NONE))&&(var4->type==TYPE_INT) ){
                int size;
		int numl;
		int numh;	
		int step ;
                size=(*(string*)var1->value).size();
		step= *((int*)(var4->value));
	if (step == 0) {
                cout<<"ValueError: slice step cannot be zero"<<endl;
		return 0;
	}
	if (var2->type == TYPE_NONE) {
			if (step > 0)
				numl = 0;
			else
				numl =size-1;
		}
		else {
			numl = *(int*)var2->value;
			if (numl>size-1) numl=size-1;
			if (numl<-size) numl=0;
			if (numl<0) numl=numl+size;

		}

		if (var3->type == TYPE_NONE) {
			if (step > 0)
				numh = size;
			else
				numh =-1;
		}
		else {
			numh=*(int*)var3->value;
			if (numh>size) numh=size;
			if(numh<-size-1) numh=-1;
			if (numh<0) numh=numh+size;

		}
		//cout<<numl<<","<<numh<<"s"<<step<<endl;
		
		if ((numh - numl) * step <= 0) {
			char* l[SLEN];
			return new variable(l,0);
		}
		int count = 0;
		int tep = numl;
		while (((numh - tep) * step > 0)&&(count>=0)&&(count<size)) {
			tep += step;
			count++;
		}
		char* l[SLEN];
		for (int i = 0; i < count; i++) {
			l[i] = &(*(string*)var1->value)[numl + i * step];
		}
		return new variable(l,count);
            }
            else {
                  cout<<"TypeError:slice indices must be integers or None or have an __index__ method"<<endl;
                  return 0;
            }
	}

        cout<<"TypeError: ";
        typeprint(var1->type);
	cout<<" object has no attribute \'__getitem__\'"<<endl;
        return 0;
}


variable* variable::posop(variable* var)
{       if(var==0)return 0;
	if (var->type == TYPE_INT) {
		return new variable(*(int*)var->value);
	}
	if (var->type == TYPE_FLOAT) {
		return new variable(*(float*)var->value);
	}
        cout<<"TypeErrror: bad operand type for unary +:";
        typeprint(var->type);
        cout<<endl;
        return 0;
}
variable* variable::negop(variable* var)
{       if(var==0)return 0;
	if (var->type == TYPE_INT) {
		return new variable(-*(int*)var->value);
	}
	if (var->type == TYPE_FLOAT) {
		return new variable(-*(float*)var->value);
	}
        cout<<"TypeErrror: bad operand type for unary -:";
        typeprint(var->type);
        cout<<endl;
        return 0;
}
void variable::append(variable *var){
	variable **l = new variable * [this->size+1];
	for (int i = 0; i < this->size; i++) {
		l[i] = ((variable**)this->value)[i];
	}
	l[this->size]=var;
	this->size++;
	this->value=l;
}

variable* variable::boolop(variable* var){
           if(var==0)return new variable(false);
           if(var->type==TYPE_BOOL)return var;
           if(var->type==TYPE_INT)
                 if((*(int*)var->value)==0)
                          return new variable(false);
           if(var->type==TYPE_FLOAT)
                 if((*(float*)var->value)==0.0)
                          return new variable(false);
           return new variable(true);
}
variable* variable::notop(variable* var){
           if(var==0)return 0;
           if(var->type==TYPE_BOOL){
                 if((*(bool*)var->value)==true)return new variable(false);
                 else return new variable(true);
           }
           if(var->type==TYPE_INT)
                 if((*(int*)var->value)==0)
                          return new variable(true);
           if(var->type==TYPE_FLOAT)
                 if((*(float*)var->value)==0.0)
                          return new variable(true);
           else return new variable(false);
}
variable* variable::lop(variable* var1, variable* var2){
     if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)<(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
     if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)<(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)<(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)<1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)<0)return new variable(true,(float)0);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)<(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)<(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)<1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)<0)return new variable(true,(float)0);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if((int)var1->relationnum<(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum<(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                  if(var1->relationnum<1)return new variable(true,(float)1);
                  else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                  if(var1->relationnum<0)return new variable(true);
                  else return new variable(false);
              }
           }
        }
        else{
                  return new variable(false);
        }
     }
     return new variable(false);
}
variable* variable::gop(variable* var1, variable* var2){
     if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)>(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
     if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)>(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)>(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)>1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)>0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)>(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)>(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)>1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)>0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if(var1->relationnum>(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum>(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if(var1->relationnum>1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if(var1->relationnum>0)return new variable(true);
                 else return new variable(false);
              }
           }
        }
        else{
               return new variable(false);
        }
     }
    return new variable(false);
}
variable* variable::leop(variable* var1, variable* var2){
    if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)<=(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
    if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)<=(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)<=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)<=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)<=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)<=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)<=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)<=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)<=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if(var1->relationnum<=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum<=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if(var1->relationnum<=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if(var1->relationnum<=0)return new variable(true);
                 else return new variable(false);
              }
           }
        }
        else{
               return new variable(false);
        }
     }
    return new variable(false);
}
variable* variable::geop(variable* var1, variable* var2){
    if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)>=(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
    if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)>=(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)>=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)>=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)>=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)>=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)>=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)>=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)>=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if(var1->relationnum>=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum>=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if(var1->relationnum>=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if(var1->relationnum>=0)return new variable(true);
                 else return new variable(false);
              }
           }
        }
        else{
               return new variable(false);
        }
     }
    return new variable(false);
}
variable* variable::eqop(variable* var1, variable* var2){
    if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)==(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
    if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)==(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)==(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)==1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)==0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)==(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)==(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)==1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)==0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if(var1->relationnum==(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum==(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if(var1->relationnum==1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if(var1->relationnum==0)return new variable(true);
                 else return new variable(false);
              }
           }
        }
        else{
               return new variable(false);
        }
     }
    return new variable(false);
}
variable* variable::neop(variable* var1, variable* var2){
    if(var1==0||var2==0)return 0;
     if(var1->type==TYPE_STR&&var2->type==TYPE_STR){
            if((*(string*)var1->value)!=(*(string*)var2->value))return new variable(true,(float)1);
            else return new variable(false);
     }
    if(var1->type==TYPE_INT){
           if(var2->type==TYPE_INT){
                 if((*(int*)var1->value)!=(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((float)(*(int*)var1->value)!=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(int*)var1->value)!=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(int*)var1->value)!=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_FLOAT){
           if(var2->type==TYPE_INT){
                 if((*(float*)var1->value)!=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if((*(float*)var1->value)!=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if((*(float*)var1->value)!=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if((*(float*)var1->value)!=0)return new variable(true);
                 else return new variable(false);
              }
           }
     }
     if(var1->type==TYPE_BOOL){
        if((*(bool*)var1->value)==true){
           if(var2->type==TYPE_INT){
                 if(var1->relationnum!=(float)(*(int*)var2->value))return new variable(true,(float)(*(int*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_FLOAT){
                 if(var1->relationnum!=(*(float*)var2->value))return new variable(true,(*(float*)var2->value));
                 else return new variable(false);
           }
           if(var2->type==TYPE_BOOL){
              if((*(bool*)var2->value)==true){
                 if(var1->relationnum!=1)return new variable(true,(float)1);
                 else return new variable(false);
              }
              if((*(bool*)var2->value)==false){
                 if(var1->relationnum!=0)return new variable(true);
                 else return new variable(false);
              }
           }
        }
        else{
               return new variable(false);
        }
     }
    return new variable(false);
}
variable* variable::andop(variable* var1, variable* var2){
           if(var1==0||var2==0)return 0;
           if(var1->type==TYPE_BOOL)
                if((*(bool*)var1->value)==true)
                         if(var2->type==TYPE_BOOL)
                                if((*(bool*)var2->value)==true)return new variable(true);
           return new variable(false);
}
variable* variable::orop(variable* var1, variable* var2){
           if(var1==0||var2==0)return 0;
           if(var1->type==TYPE_BOOL)
                if((*(bool*)var1->value)==false){
                         if(var2->type==TYPE_BOOL)
                                if((*(bool*)var2->value)==false)return new variable(false);
                         if(var2->type==TYPE_INT)
                                if((*(int*)var2->value)==0)return new variable(false);
                         if(var2->type==TYPE_FLOAT)
                                if((*(float*)var2->value)==0)return new variable(false);
           }
           if(var1->type==TYPE_INT)
                if((*(int*)var1->value)==0){
                         if(var2->type==TYPE_BOOL)
                                if((*(bool*)var2->value)==false)return new variable(false);
                         if(var2->type==TYPE_INT)
                                if((*(int*)var2->value)==0)return new variable(false);
                         if(var2->type==TYPE_FLOAT)
                                if((*(float*)var2->value)==0)return new variable(false);
           }
           if(var1->type==TYPE_FLOAT)
                if((*(float*)var1->value)==0){
                         if(var2->type==TYPE_BOOL)
                                if((*(bool*)var2->value)==false)return new variable(false);
                         if(var2->type==TYPE_INT)
                                if((*(int*)var2->value)==0)return new variable(false);
                         if(var2->type==TYPE_FLOAT)
                                if((*(float*)var2->value)==0)return new variable(false);
           }
           return new variable(true);
}
bool VariableEqual(variable* var1, variable* var2){
       if(var1==0||var2==0)return false;
       if(var1->type==TYPE_INT&&var2->type==TYPE_INT)
            if((*(int*)var1->value)==(*(int*)var2->value))return true;
       if(var1->type==TYPE_FLOAT&&var2->type==TYPE_FLOAT)
            if((*(float*)var1->value)==(*(float*)var2->value))return true;
       if(var1->type==TYPE_STR&&var2->type==TYPE_STR)
            if((*(string*)var1->value)==(*(string*)var2->value))return true;
       if(var1->type==TYPE_LIST&&var2->type==TYPE_LIST)
            if(var1->value==var2->value)return true;
       if(var1->type==TYPE_BOOL&&var2->type==TYPE_BOOL)
            if((*(bool*)var1->value)==(*(bool*)var2->value))return true;
       return false;
}
variable* variable::objis(variable* var1, variable* var2){
       if(var1==0||var2==0)return 0;
       if(VariableEqual(var1,var2))
             return new variable(true,(float)1);
       return new variable(false);
}
variable* variable::objnot(variable* var1, variable* var2){
       if(var1==0||var2==0)return 0;
       return variable::notop(variable::objis(var1,var2));
}
variable* variable::objin(variable* var1, variable* var2){
       if(var1==0||var2==0)return 0;
       if(var2->type==TYPE_STR){
             if(var1->type==TYPE_STR){
                    if((*(string*)var2->value).find((*(string*)var2->value))!=string::npos)
                           return new variable(true,(float)1);
                    else return new variable(false);
             }
             else{
                    cout<<"TypeError: \'in <string>\' requires string as left operand,not ";
                    typeprint2(var1->type);
                    cout<<endl;
                    return 0;
            }
       }
       if(var2->type==TYPE_LIST){
            int i;
            for(i=0;i<var2->size;i++)
                 if(VariableEqual(var1,((variable**)var2->value)[i]))break;
            if(i<var2->size)return new variable(true,(float)1);
            else return new variable(false);
       }
       cout<<"TypeError: argument of type ";
       typeprint(var2->type);
       cout<<" is not iterable"<<endl;
       return 0;
}
variable* variable::objnotin(variable* var1, variable* var2){
       if(var1==0||var2==0)return 0;
       return variable::notop(variable::objin(var1,var2));
}

