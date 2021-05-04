#include <string>
#include "invoice.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main () {

    Invoice product("00124", "un martello bello", 3, 10);
    cout << "devi pagare questo " << product.getInvoiceAmount() << endl;


}