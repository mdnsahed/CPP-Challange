//bstring_main.cpp

#include "BString.h"
#include <iostream>

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;



void format(const BString& Ls);
template <typename T> void check(const char* mess, T expr, T result)
{
	if (expr != result)
	{
		ios::fmtflags flags = cout.flags(ios::boolalpha);
		cout << endl << ">>> " << mess << endl;
		cout << ">>> Wert soll " << result << " sein." << endl;
		cout.flags(flags);
		exit(-1);
		
	}
}
int main(void) {

	unsigned int uiL = 40;
	BString a("Krautsalat");
	const BString& acr = a;
	BString b = "Blumentopferde";
	BString c = 'Q';
	BString d(uiL);
	BString e = a;
	BString f('x', 0);
	BString g(reinterpret_cast<const char*>(NULL));

	acr.conOut(); format(acr);
	b.conOut();	format(b);
	c.conOut();	format(c);
	d.conOut();	format(d);
	e.conOut();	format(e);
	check("&a==&e", &a == &e, false);
	f.conOut();	format(f);
	check("f.capacity()", f.capacity(), 1u);
	check("f.length()", f.length(), 1u);
	g.conOut();	format(g);
	check("g.capacity()", g.capacity(), 0u);
	check("g.length()", g.length(), 0u);
	
	// Quellcode zu Teilaufgabe b

	BString sonder = BString("hallo");
	sonder.conOut();	format(sonder);
	
	check("sonder -> sonder.length(): ", sonder.length(), 5u);
	check("sonder -> sonder.capacity(): ", sonder.capacity(), 5u);
	

	cout << "Zuweisung d=b :   ";
	d = b;
	d.conOut();	format(d);

	d += a;	cout << "Operator d+=a :   ";
	d.conOut();	format(d);

	cout << "Operator d+=d :   ";
	d += d;
	d.conOut();	format(d);
	
	check("d+=d -> d.length(): ", d.length(), 48u);
	check("d+=d -> d.capacity(): ", d.capacity(), 48u);
	

	return EXIT_SUCCESS;
}


void format(const BString& Ls) {
	cout << " (" << Ls.length() << "|"
		<< Ls.capacity() << ")" << endl;
}
