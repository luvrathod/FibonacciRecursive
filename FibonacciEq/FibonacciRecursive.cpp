#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;


int FibonacciRecursiveFunc(int nthPos) {
	int primitiveFibonacciNUMS[2] = { 0,1 };
	if (find(primitiveFibonacciNUMS, end(primitiveFibonacciNUMS), nthPos - 1) != end(primitiveFibonacciNUMS)) {
		return nthPos - 1;
	}
	else {
		return FibonacciRecursiveFunc(nthPos - 1) + FibonacciRecursiveFunc(nthPos - 2);
	}
	
	
	
}

int main() {
	string inputVAL; int nthPos;
	cout << "Greetings, enter a valid n value | n >= 1\n" << "type exit, quit or break to quit program \n\n" << endl << " ->";
	getline(cin, inputVAL);
	string exit_Methods[3] = { "exit", "quit", "break" };
	while(find(exit_Methods, end(exit_Methods),inputVAL) == end(exit_Methods)) {
		bool exception_caught = true;

		try {
			nthPos = stoi(inputVAL);

			exception_caught = false;
		}
		catch (invalid_argument) {
			cerr << "invalid argument" << endl;
		}
		catch (out_of_range) {
			cerr << "number is too big" << endl;
		}
		catch (exception) {
			cerr << "something went horribly wrong :v" << endl;
		}
		if (!exception_caught) {
			double timeri = 0; double timerincrementer = 1; 

			//begintimer for calculation speed
			time_t begin, end;
			time(&begin);
			int iterations = 1000;
			for (int i = 0; i < iterations; i++) {
				timeri += timerincrementer;
				timerincrementer /= 2.0;
			}
			if (nthPos >= 1) {
				cout << FibonacciRecursiveFunc(nthPos) << endl;
			}
			else {
				cout << "ERR" << endl;
			}
			
			
			// measure elapsed time
			time(&end);
			time_t elapsed = end - begin;

			printf("Time measured: %ld seconds.\n\n", elapsed);
		}
		cout << "enter a valid n value | n >= 0 ->";
		getline(cin, inputVAL);
	}
	
	
	
}