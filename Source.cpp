
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
	carry.push(0);
	for (int j = y.length(); j > 0; j--)
	{


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
		
			tempresult=add(tempresult,result_stack.top());
			result_stack.pop();
		



	}
	result = tempresult;

	return result;




}

string borrow (string x)
{

stack<int>borrow_stack;
borrow_stack.push(0);




}



string substraction (string x , string y)
{

        int x_length = x.length();
	int y_length = y.length();
	string result = "";
	stack<int> result_stack;
	stack<int>borrow;
	borrow.push(0);
        borrow.push(0);
string firstelementx = x.substr(0,1);
string firstelementy = y.substr(0,1);
int fxint=atoi(firstelementx.c_str());
int fyint=atoi(firstelementy.c_str());
        if (x_length==y_length&&fxint>fyint)
        {int flag = 0;

        for ( int i = x_length;i>0;i--)

        {
        string xelement=x.substr(i-1,1);
        string yelement=y.substr(i-1,1);
        int xelementint=atoi(xelement.c_str());
        int yelementint=atoi(yelement.c_str());
       if (flag==0)
{
        if (xelementint>=yelementint)
       { int resultelementint = xelementint-yelementint;
        result_stack.push(resultelementint);

}
       else {
              xelementint+=10;
              flag=1;
              int resultelementint = xelementint-yelementint;
              result_stack.push(resultelementint);


       }
}
else if (flag==1)
               {
               	xelementint--;
                   if (xelementint==0||xelementint<yelementint)
                   {
                   	flag=1;
                   	xelementint+=10;
                   	int resultelementint = xelementint-yelementint;
              result_stack.push(resultelementint);

                   }
                   else { //xelementint--;
                   int resultelementint = xelementint-yelementint;
              result_stack.push(resultelementint);
              flag=0;}


               }



        }
}

else if (x_length>y_length) {
	int remainder = x_length - y_length;
		for (int i = 0; i < remainder; i++)
		{
			y.insert(0, 1,'0');
			

		}
		return substraction(x, y);

	}
else if (y_length>x_length){
int remainder = y_length - x_length;
		for (int i = 0; i < remainder; i++)
		{
			x.insert(0, 1,'0');
			

		}
		return "-"+substraction(y, x);

}
else if ( x_length==y_length&&fxint<fyint){
return "-"+substraction(y,x);

}

        while (!result_stack.empty())
        {
            int temp=result_stack.top();
            std::string ts=std::to_string(temp);
            result+=ts;
            result_stack.pop();
        }
        return result;
	
}
string division (string x, string y)
{





}



int main()
{
	string test = multiply("55","22");
	//std::cout << test;
        printf("%s",test.c_str());
	return 0;
}
