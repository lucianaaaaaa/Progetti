Invoice: myInvoice.o InvoiceTest.o
	g++ -o Invoice myInvoice.o InvoiceTest.o
myInvoice.o: myInvoice.cpp invoice.h
	g++ -c myInvoice.cpp -std=c++11
InvoiceTest.o: InvoiceTest.cpp invoice.h
	g++ -c InvoiceTest.cpp -std=c++11