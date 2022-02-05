# include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	Contacts ct;

	ct.addInfo();
	pb.addContacts(ct, pb.getIdx());
	pb.printContacts();
}