#include "Insurance.h"
#include <string>

ostream &operator<<(ostream &strm, Insurance &s)
{
	strm << "Sale: " << s.commission << s.type << endl;
	return strm;
}
