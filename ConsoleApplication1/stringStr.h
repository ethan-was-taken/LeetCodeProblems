#include <string>

using namespace std;

class stringStr {
public:
	int strStr(string haystack, string needle) {
		int limit = (needle.size() <= haystack.size()) ? (haystack.size() - needle.size()) : -1;

		for (int i = 0; i <= limit; i++)
			if (haystack.substr(i, needle.size()) == needle)
				return i;

		return -1;
	};
};