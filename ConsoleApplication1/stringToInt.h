#include <string>
#include <map>
#include <math.h>
#include <regex>

#define SPACE -1
#define PLUS  -2
#define MINUS -3

using namespace std;

//myAtoi()

// This solution, while wordy, is O(3n) -> O(n)
class stringToInt {

	public:
		stringToInt() {
			asciiCodes["43"] = PLUS;
			asciiCodes["45"] = MINUS;
			asciiCodes["48"] = 0;
			asciiCodes["49"] = 1;
			asciiCodes["50"] = 2;
			asciiCodes["51"] = 3;
			asciiCodes["52"] = 4;
			asciiCodes["53"] = 5;
			asciiCodes["54"] = 6;
			asciiCodes["55"] = 7;
			asciiCodes["56"] = 8;
			asciiCodes["57"] = 9;
			isNegative = false;
		};

		int myAtoi(string str) {

			long long toReturn = 0;

			str = removeLeadingSpace(str);
			// an affector, in this case, is a + or -
			str = removeAffector(str);
			str = makeValid(str);

			long long size = (long long) str.size() - 1;

			if (size >= 11 && !isNegative) { return INT_MAX; }
			else if (size >= 11 && isNegative) { return INT_MIN; }

			for (unsigned int i = 0; i < str.size(); i++) {

				// curr holds a ascii code
				string curr = to_string(str[i]);

				long dividend = pow(10, (size - i - 1));
				if (curr == "32") {
					toReturn /= dividend;
					return (toReturn *= (isNegative) ? -1 : 1);
				}

				map<string, int>::iterator it = asciiCodes.find(curr);
				if (it == asciiCodes.end())
					return 0;
				else if (it->second == PLUS || it->second == MINUS) {
					toReturn /= dividend;
					continue;
				}

				long multiplier = pow(10, size - i);
				multiplier *= it->second;
				toReturn += multiplier;
			}
			
			toReturn *= (isNegative) ? -1 : 1;

			if (toReturn > INT_MAX) { return INT_MAX; }
			else if (toReturn < INT_MIN) { return INT_MIN; }

			return (int) toReturn;
		};

	private:
		string removeLeadingSpace(string str) {

			int i = 0;
			for (; i < str.size(); i++) {
				string curr = to_string(str[i]);
				if (curr == "32") { continue; }
				else { break; }
			}

			return str.substr(i, (str.size() - i));
		};

		// Looks for a space, +, -, or char then returns a 
		//  substring from 0 to where it encountered it
		string makeValid(string str) {

			for (int i = 0; i < str.size(); i++) {
				string curr = to_string(str[i]);
				
				map<string, int>::iterator it = asciiCodes.find(curr);
				if (curr == "32" || it == asciiCodes.end())
					return str.substr(0, i);
			}
		
			return str;
		};

		string removeAffector(string str) {

			string curr = to_string(str[0]);
			string next = to_string(str[1]);

			// Since each they all return something there's no reason to use if-else 
			//  and having each as an if makes it look more neat
			if ( (curr == "43" || curr == "45") && (next == "43" || next == "45") )
				return "";
			if (curr == "43")
				return str.substr(1, (str.size() - 1));
			if (curr == "45") {
				isNegative = true;
				return str.substr(1, (str.size() - 1));
			}

			return str;
		};

		map<string, int> asciiCodes;
		bool isNegative;

};