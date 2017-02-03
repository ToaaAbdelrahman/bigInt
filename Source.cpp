
//#include<iostream>

#include <stack>
#include<string>
#include <stack>
#include<string>
#include <sstream>
#include <cstdio>
#include <cstdlib> 


using namespace std;





 /*template <typename T>
    std::string to_string(T value)
    {
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
    }

*/

string add(string x, string y)
{
	int x_length = x.length();
	int y_length = y.length();
	string sum = "";
	stack<int> sum_stack;
	stack<int>carry;
	carry.push(0);
	if (x_length == y_length)
	{
		
		for (int i = x_length; i > 0; i--)
		{
			string xelement = x.substr(i - 1, 1);
			string yelement = y.substr(i - 1, 1);
			int xelementint = atoi(xelement.c_str());
			int yelementint = atoi(yelement.c_str());
			int sumelement = xelementint + yelementint+carry.top();
			carry.pop();
			if (sumelement <= 9) carry.push(0);
			else 
			{
				carry.push(1);
				sumelement -= 10;
			}
			/*else if (sumelement < 29)
			{
				carry.push(2);
				sumelement -= 20;
			}*/
			sum_stack.push(sumelement);
		


		}
		//cout << carry.top();
		//bool flag = false;
		int xplus = x_length;
		if (carry.top() != 0)
		{
		//	flag = true;
			sum_stack.push(carry.top());
			carry.push(0);
			xplus++;

		}
		
		for (int j = 0; j < xplus; j++)
		{

			int c = sum_stack.top();
			std::string cc=std::to_string(c);
			sum += cc;
			sum_stack.pop();

		}
		/*if (flag == true) {
			int c = sum_stack.top();
			string cc = to_string(c);
			sum += cc;
			sum_stack.pop();
		}*/


		
		return sum;
	}
	else if (x_length > y_length)
	{
		int remainder = x_length - y_length;
		for (int i = 0; i < remainder; i++)
		{
			y.insert(0, 1,'0');
			

		}
		return add(x, y);

	}
	else if (y_length>x_length)
	{
		int remainder = y_length - x_length;
		for (int i = 0; i < remainder; i++)
		{
			x.insert(0, 1, '0');


		}
		return add(x, y);
	}

}
string add_zeros(string y, int number)
{
	for (int i = 0; i < number; i++)
		y += "0";

	return y;
}
string multiply(string x, string y)
{

	int x_length = x.length();
	int y_length = y.length();
	string result = "";
	stack<int> sum_stack;
	stack<int>carry;
	stack <string>result_stack;
	
	for (int j = y.length(); j > 0; j--)
	{
         carry.push(0);

		//de ll loop al tnya 
		string yelement = y.substr(j - 1, 1);
		//cout << "y element for this loop " << yelement << "\n";
		//
		string xelement;
		int xelementint;
		int yelementint;
		int resultelement;
		string resultstring;
		int lastnumberposition;
		string resulttaht;
		string carries;
		int resultwithcarry;
		//x for one element multiplication
		for (int i = x_length; i > 0; i--)
		{
			xelement = x.substr(i - 1, 1);
			xelementint = atoi(xelement.c_str());
			yelementint = atoi(yelement.c_str());
			resultelement = xelementint*yelementint + carry.top();
			resultstring = std::to_string(resultelement);
			lastnumberposition = resultstring.length() - 1;


			resulttaht = resultstring.substr(lastnumberposition, 1);
			resultwithcarry = atoi(resulttaht.c_str());
			//carry.pop();
			//string resultwcarry = to_string(resultwithcarry);
			carries = resultstring.substr(0, lastnumberposition);
			carry.push(atoi(carries.c_str()));
			sum_stack.push(resultwithcarry);


			//cout << resulttaht << "\n" << carries << "\n";







//till here one element mult

		}

		if (carry.top() != 0)
		{
			//sum_stack.pop();
			sum_stack.push(carry.top());
			carry.pop();
		}

	

		// unchangeable just for displaying
		int tol = sum_stack.size();
		for (int j = 0; j < tol; j++)
		{

			int c = sum_stack.top();
			std::string cc = std::to_string(c);
			result += cc;
			sum_stack.pop();
		}

		 result=add_zeros(result, y.length() - j);
		 //cout << result << "\n";
		 result_stack.push(result);
		 result = "";

		 //test 

	/*	 while (!result_stack.empty())
		 {
			 cout << result_stack.top()<<"\n"; 
			 result_stack.pop();
		 }*/



	}
	string tempresult="0";
	while (!result_stack.empty())
	{
		/*int x = atoi(result_stack.top().c_str());
		tempresult += x;
		result_stack.pop();*/
		//printf("%s\n",result_stack.top().c_str() );
		
			tempresult=add(tempresult,result_stack.top());
			result_stack.pop();
		



	}
	result = tempresult;

	return result;




}

/*string borrow (string x)
{
	stack<string> result_stack;

string result="";
stack<int>borrow_stack;
string extras=add_zeros("1",1);
borrow_stack.push(0);
for (int i=x.length();i>0;i--){
string xelement = x.substr(i-1,1);
string before = x.substr(i-2,1);
int xelementint=atoi(xelement.c_str());
int beforeint=atoi(before.c_str());
if (beforeint==0) borrow(x-xelement);
else {
xelementint+=10;
beforeint--;
xelement=std::to_string(xelementint);
before=std::to_string(beforeint);
result_stack.push(xelement);
result_stack.push(before);			

}
}
while(!result_stack.empty())
{
	result+=result_stack.top();
	result_stack.pop();
}
}*/



string result = "";
bool f = false;

string substraction(string x, string y)
{

    int x_length = x.length();
    int y_length = y.length();
    stack<int> result_stack;
    stack<int>borrow;
    borrow.push(0);
    borrow.push(0);
    string firstelementx = x.substr(0, 1);
    string firstelementy = y.substr(0, 1);
    int fxint = atoi(firstelementx.c_str());
    int fyint = atoi(firstelementy.c_str());



    if (x_length>y_length) {
        int remainder = x_length - y_length;
        for (int i = 0; i < remainder; i++)
        {
            y.insert(0, 1, '0');


        }
        return substraction(x, y);

    }

/*    if (x_length == y_length&&fxint == fyint)

    {

        for (int i = 1; i<x_length; i++)

        {
            firstelementx = x.substr(i, 1);
            firstelementy = y.substr(i, 1);
            fxint = atoi(firstelementx.c_str());
            fyint = atoi(firstelementy.c_str());
            if (fxint>fyint) return substraction(x, y);
            else if (fxint>fyint) return "-" + substraction(y, x);
            else continue;

        }


    }*/
      if (x_length == y_length&&fxint>fyint||f)
    {

        //printf("%s\n","yes" );
        int flag = 0;

        for (int i = x_length; i>0; i--)

        {
            string xelement = x.substr(i - 1, 1);
            string yelement = y.substr(i - 1, 1);
            int xelementint = atoi(xelement.c_str());
            int yelementint = atoi(yelement.c_str());
            if (flag == 0)
            {
                if (xelementint >= yelementint)
                {
                    int resultelementint = xelementint - yelementint;
                    result_stack.push(resultelementint);

                }
                else {
                    xelementint += 10;
                    flag = 1;
                    int resultelementint = xelementint - yelementint;
                    result_stack.push(resultelementint);
                    continue;


                }
            }
            else if (flag == 1)
            {
                xelementint--;
                if (xelementint<yelementint)
                {
                    flag = 1;
                    xelementint += 10;
                    int resultelementint = xelementint - yelementint;
                    result_stack.push(resultelementint);

                }
                else { //xelementint--;
                    int resultelementint = xelementint - yelementint;
                    result_stack.push(resultelementint);
                    flag = 0;
                }


            }



        }
    }

    //else
    else if (y_length>x_length){
        int remainder = y_length - x_length;
        for (int i = 0; i < remainder; i++)
        {
            x.insert(0, 1, '0');


        }
        return "-" + substraction(y, x);

    }
    else if (x_length == y_length&&fxint<fyint){
        return "-" + substraction(y, x);

    }




    if (result_stack.empty())
    {

        f = true;
        return "-"+ substraction(y, x);



    }
    while (!result_stack.empty())
    {
        int temp = result_stack.top();
        std::string ts = std::to_string(temp);
        result += ts;
        result_stack.pop();
    }
    // if (result!="")
    return result;
    // else return substraction(y,x);

    //string r = substraction(y,x);
    //printf("%s\n",r.c_str());
    //return "substraction(y,x)";


}






string find_min(string A,string B, string C,string D)

{   string local_minAB="";
	string local_CD="";

	if (A.substr(0,1)=="-"&&B.substr(0,1)=="-"&&C.substr(0,1)=="-"&&D.substr(0,1)=="-") return "reduce number of zeros";
	else {
	if (A.substr(0,1)=="-"&&B.substr(0,1)!="-") local_minAB=B;
	else if (A.substr(0,1)!="-"&&B.substr(0,1)=="-")local_minAB=A;
	else if (A.substr(0,1)=="-"&&B.substr(0,1)=="-")local_minAB=add(local_CD,"0");
	else {
 string temp1=substraction(A,B);
 if (temp1.substr(0,1)=="-") local_minAB=A;
 else local_minAB =B;
}
if (C.substr(0,1)=="-"&&D.substr(0,1)!="-") local_CD=D;
	else if (C.substr(0,1)!="-"&&D.substr(0,1)=="-")local_CD=C;
		else if (C.substr(0,1)=="-"&&D.substr(0,1)=="-")local_CD=add(local_minAB,"0");

	else {
string temp2=substraction(C,D);
if (temp2.substr(0,1)=="-") local_CD=C;
else local_minAB =D;
}
string temp3=substraction(local_minAB,local_CD);
if (temp3.substr(0,1)=="-")return local_minAB;
else return local_CD;
}



}
string division (string x, string y)

{
stack <string> output_result;
string one =multiply(y,"1");
string two = multiply(y,"2");
string four = multiply(y,"4");
string eight = multiply(y,"8");

int number_of_zeros=0;
string temp1="";
string temp2="";
string temp4="";
string temp8="";
string result;
string number_of_zerosString;
//while (1)

 temp1=substraction(x,add_zeros(one , number_of_zeros));
	//printf("temp1 is:%s\n\n",temp1.c_str() );


//printf("%s\n%s\n",a.c_str(),b.c_str() );
 temp2=substraction(x,add_zeros(two , number_of_zeros));
 	//printf("temp2 is :%s\n\n",temp2.c_str() );

 temp4=substraction(x,add_zeros(four , number_of_zeros));
 	//printf("%s\n",temp4.c_str() );
printf("%s\n",temp8.c_str());
 temp8=substraction(x,add_zeros(eight ,number_of_zeros));
 //printf("%s\n%s\n",x.c_str(),add_zeros(eight ,number_of_zeros).c_str() );
 	printf("%s\n",temp8.c_str());

 result = find_min(temp1,temp2,temp4,temp8);
/*if (result=="reduce number of zeros") 
	{number_of_zeros -- ;
		//printf("%s\n","wrong" );
continue;

	}
else break;*/
//printf("%s\n",result.c_str() );
//break;
	
// result = find_min(temp1,temp2,temp4,temp8);



 number_of_zerosString=add_zeros("1",number_of_zeros);

if (result==temp1) output_result.push(multiply("1",number_of_zerosString));
if (result==temp2) {output_result.push(multiply("2",number_of_zerosString));};
if (result==temp8) output_result.push(multiply("8",number_of_zerosString));
if (result==temp4) output_result.push(multiply("4",number_of_zerosString));

	// string againtest =division(result,y);



//printf("%s\n%s\n%s\n%s\n",temp1.c_str(),temp2.c_str(),temp4.c_str(),temp8.c_str() );
return output_result.top() 	;

}


int main()
{
	//string test = division("85434","37");
	//std::cout << test;
	//string test = division("11434","37");
	//string test = find_min("7734","4034","-3366","-18166");
	//string test = substraction("11111111140","11111111144");
	//string test = division("11434","37");
	//string test = division("11434","37");

	string test = division("85434","37");
       // printf("%s\n",test.c_str());

	return 0;
}

