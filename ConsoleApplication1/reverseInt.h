#include <math.h>
#include <string> 

using namespace std;

class reverseInt {
	public:
		int reverse(int x) {
			
			bool isNegative = (x < 0) ? true : false;

			x = abs(x);

			int size = to_string(x).size();

			long long reversed = 0;
			for (int i = (size - 1); i >= 0; i--) {
				long long modifier = pow(10,i);
				int mod = x % 10;
				x /= 10;
				reversed += (modifier * mod);
			}

			reversed *= (isNegative) ? -1 : 1;

			if (reversed > INT_MAX || reversed < INT_MIN)
				return 0;

			return reversed;
		};
};