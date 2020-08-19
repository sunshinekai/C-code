#include "Address Book.h"

void TestAddressBook()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	/*AddressInfo info1 = {"杨佳琪", "110", 18, Man};
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "小王", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "小李", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	AddressBookSave(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);*/

	AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);
}

int main()
{
	TestAddressBook();
	return 0;
}