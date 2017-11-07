#include <iostream>
#include <stack>
#include <cstdlib>
#include <climits>
#include <cassert>

class ExprCalculator{
public:
	explicit ExprCalculator(const std::string & expr):expr_(expr){
		opcode.push('#');
	}
	
	ExprCalculator & setNewExpression(const std::string & expr){
		
		expr_ = expr;
		return *this;
	}

	int work();

private:
	int getPrecedence(char op);

	int opcode2res(char op, int operand1,int operand2);

	inline void throwException(){
		std::cerr<<"unexpected exception occurred!";
		exit(EXIT_FAILURE);
	}

private:
	std::string expr_;
	std::stack<char> opcode;
	// lets assume that this program only support integer computation
	std::stack<int> integer;
};

int ExprCalculator::opcode2res(char op, int operand1,int operand2){
	switch(op){
	case '+':return operand1 + operand2;
	case '-':return operand1 - operand2;
	case '*':return operand1 * operand2;
	case '/':return operand1 / operand2;
	default:
		return INT_MIN;
	}
}

int ExprCalculator::getPrecedence(char op){
	if(op=='+'||op=='-'){
		return 1;
	}else if(op=='*'|| op=='/'){
		return 2;
	}
	return -1;
}

int ExprCalculator::work(){
	for(size_t i=0;i<expr_.size();i++){
		if(expr_[i] >='0' && expr_[i] <='9'){
			integer.push(expr_[i]-'0');
		}else if(expr_[i]=='('){
			opcode.push('(');
		}
		else if(expr_[i]=='+' || expr_[i]=='-'||expr_[i]=='*' || expr_[i]=='/'){
			if(getPrecedence(opcode.top())<getPrecedence(expr_[i])){
				opcode.push(expr_[i]);
			}else{
				int operand2 = integer.top();
				integer.pop();
				int operand1 = integer.top();
				integer.pop();
				int res = opcode2res(opcode.top(),operand1,operand2);
				integer.push(res);
				opcode.pop();
				opcode.push(expr_[i]);
			}
		}else if(expr_[i]==')'){
			do{
				int operand2 = integer.top();
				integer.pop();
				int operand1 = integer.top();
				integer.pop();
				int res = opcode2res(opcode.top(),operand1,operand2);
				integer.push(res);
				opcode.pop();
			}while(opcode.top()!='(');
			opcode.pop();
		}else if(expr_[i]=='#'){
			do{
				int operand2 = integer.top();
				integer.pop();
				int operand1 = integer.top();
				integer.pop();
				int res = opcode2res(opcode.top(),operand1,operand2);
				integer.push(res);
				opcode.pop();
				//opcode.pop();
			}while(expr_[i]!='#');
			
		}else{
			throwException();
		}
	}
	int finalResult = integer.top();
	integer.pop();
	return finalResult;
}

int main(){
	//this stupid calcuator do not support ANY COMPUATION MORE THAN ONE SINGLE INTEGER AND NEGATIVE INTEGER;
	std::string expr("3+2-5#");
	
	//assert(calcuator.work() == 0);
	//assert(calcuator.setNewExpression("3+2-9#").work()==-4);
	//assert(calcuator.setNewExpression("(3*2)-9#").work()==-3);
	//assert(calcuator.setNewExpression("(3*2)-(5*1)#").work()==1);
	std::string str;
	std::getline(std::cin,str);
	while(str!="#"){
		ExprCalculator calcuator(str);
		std::cout<<"the result of expression "<<str<<" is "<<calcuator.work()<<"\n";
		std::getline(std::cin,str);
	}
	return 0;
}
