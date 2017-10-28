#include "PolynomialManagerInterface.h"
#include "PolynomialList.h"
using namespace std;

class PolynomialManager : public PolynomialManagerInterface
{
private:
	PolynomialList listOne;
	PolynomialList listTwo;
public:
	PolynomialManager();
	~PolynomialManager();
	PolynomialListInterface* addLists();
	PolynomialListInterface* subtractLists();
	void fillListOne(string term);
	void fillListTwo(string term);
	void clearListOne();
	void clearListTwo();
	PolynomialListInterface* getListOne();
	PolynomialListInterface* getListTwo();
};