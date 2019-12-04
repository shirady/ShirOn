#include "System.h"

bool System::setSystemName(const char* systemName)
{
	//delete[] m_systemName; //will not run unless m_systemName was allocated
	unsigned int name_len = strlen(systemName);

	if ( (name_len < MAX_LEN_SYSTEM_NAME) && (name_len >= MIN_LEN_SYSTEM_NAME) )
	{
		m_systemName = new char[name_len + 1];
		strcpy(m_systemName, systemName);
		return true;
	}
	else
		return false;
}

bool System::setLogicSizeBuyers(unsigned int logicSizeBuyers)
{
	if (logicSizeBuyers >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeBuyers = logicSizeBuyers;
		return true;
	}
	return false;
}

bool System::setPhysSizeBuyers(unsigned int physSizeBuyers)
{
	if (physSizeBuyers >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeBuyers = physSizeBuyers;
		return true;
	}
	return false;
}

bool System::setLogicSizeSellers(unsigned int logicSizeSellers)
{
	if (logicSizeSellers >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeSellers = logicSizeSellers;
		return true;
	}
	return false;
}

bool System::setPhysSizeSellers(unsigned int physSizeSellers)
{
	if (physSizeSellers >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeSellers = physSizeSellers;
		return true;
	}
	return false;
}

const char* System::getSystemName()
{
	return m_systemName;
}

Buyer** System::getAllBuyers()
{
	return m_allBuyers;
}

Seller** System::getAllSellers()
{
	return m_allSellers;
}

System::System(char* systemName, unsigned int physSizeBuyers, unsigned int physSizeSellers)
{
	setSystemName(systemName);

	setLogicSizeBuyers(INITIAL_LOGICAL_SIZE);
	setPhysSizeBuyers(physSizeBuyers);
	m_allBuyers = new Buyer*[m_physSizeBuyers];

	setLogicSizeSellers(INITIAL_LOGICAL_SIZE);
	setPhysSizeSellers(physSizeSellers);
	m_allSellers = new Seller*[m_physSizeSellers];
}

System::~System()
{
	cleanBuyersArray();
	cleanSellersArray();
}

void System::cleanBuyersArray()
{
	for (unsigned int i = 0; i < m_logicSizeBuyers; ++i)
		delete m_allBuyers[i];
	delete[] m_allBuyers;
}

void System::cleanSellersArray()
{
	for (unsigned int i = 0; i < m_logicSizeSellers; ++i)
		delete m_allSellers[i];
	delete[] m_allSellers;
}

void System::reallocBuyers()
{
	Buyer** newAllBuyers = new Buyer*[m_physSizeBuyers];
	for (unsigned int i = 0; i < m_logicSizeBuyers; i++)
	{
		newAllBuyers[i] = m_allBuyers[i]; //changed from new Buyer(*(m_allBuyers[i]))
	}
	delete []m_allBuyers;
	m_allBuyers=newAllBuyers;
}

void System::reallocSellers()
{
	Seller** newAllSellers = new Seller*[m_physSizeSellers];
	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
	{
		newAllSellers[i] = m_allSellers[i]; //changed from new Seller(*(m_allSellers[i]))
	}
	delete[]m_allSellers;
	m_allSellers = newAllSellers;
}

bool System::addBuyerToSystem(Buyer* buyer)
{
	if (m_logicSizeBuyers == m_physSizeBuyers)
	{
		m_physSizeBuyers *= 2;
		reallocBuyers();
	}
	m_allBuyers[m_logicSizeBuyers++] = buyer;
	return true;
}

bool System::addSellerToSystem(Seller* seller)
{
	if (m_logicSizeSellers == m_physSizeSellers)
	{
		m_physSizeSellers *= 2;
		reallocSellers();
	}
	m_allSellers[m_logicSizeSellers++] = seller;
	return true;
}

const Address System::readAddress()
{
	char country[Address::MAX_LEN_COUNTRY];
	cout << "Enter your country: ";
	cin.getline(country, Address::MAX_LEN_COUNTRY);

	char city[Address::MAX_LEN_CITY];
	cout << "Enter your city: ";
	cin.getline(city, Address::MAX_LEN_CITY);

	char street[Address::MAX_LEN_STREET];
	cout << "Enter your street: ";
	cin.getline(street, Address::MAX_LEN_STREET);

	int buildNo;
	cout << "Enter your build number: ";
	cin >> buildNo;

	int apartmentNo;
	cout << "Enter your apartment number: ";
	cin >> apartmentNo;

	char zipCode[Address::MAX_LEN_ZIP_CODE];
	cout << "Enter your zip code: ";
	cleanBuffer();
	cin.getline(zipCode, Address::MAX_LEN_ZIP_CODE);

	return Address(country, city, street, buildNo, apartmentNo, zipCode);
}

const User System::readUser()
{
	char userName[User::MAX_LEN_NAME];
	cout << "Enter your user name: ";
	cin.getline(userName, User::MAX_LEN_NAME);

	char password[User::MAX_LEN_PASSWORD];
	cout << "Enter password: ";
	cin.getline(password, User::MAX_LEN_PASSWORD);

	return User(userName, password, readAddress());
}

Buyer* System::readBuyer()
{
	return new Buyer(readUser());
}

Seller* System::readSeller()
{
	return new Seller(readUser());
}

Item* System::readItem()
{
	char nameOfItem[Item::MAX_LEN_NAME];
	cout << "Enter The item name: ";
	cin.getline(nameOfItem, Item::MAX_LEN_NAME);

	Item::eCategory categoryOfItem;
	cout << "Choose category: 0 - KIDS, 1- ELECTRONICS, 2 - OFFICE, 3 - CLOTHING: ";
	int numOfCategory;
	cin >> numOfCategory;
	categoryOfItem = (Item::eCategory)(numOfCategory);

	unsigned int priceOfItem;
	cout << "Please enter the price of the product: ";
	cin >> priceOfItem;
	
	return new Item(nameOfItem, categoryOfItem, priceOfItem);
}

Seller* System::findSeller(const char* nameOfSeller) const
{
	Seller * foundSeller=nullptr;
	bool sellerExists = false;
	for (unsigned int i = 0; i < m_logicSizeSellers && !sellerExists; i++)
	{
		if (strcmp(m_allSellers[i]->getUser().getUserName(), nameOfSeller) == 0)
		{
			sellerExists = true;
			foundSeller = m_allSellers[i];
		}
	}
	return foundSeller;
}

Buyer* System::findBuyer(const char* nameOfBuyer) const
{
	Buyer* foundBuyer = nullptr;
	bool BuyerExists = false;
	for (unsigned int i = 0; i < m_logicSizeBuyers && !BuyerExists; i++)
	{
		if (strcmp(m_allBuyers[i]->getUser().getUserName(), nameOfBuyer) == 0)
		{
			BuyerExists = true;
			foundBuyer = m_allBuyers[i];
		}
	}
	return foundBuyer;
}

void System::showAllItemsOption() const
{
	char itemName[Item::MAX_LEN_NAME];
	cout << "Please enter the name of the item: ";
	cin.getline(itemName, Item::MAX_LEN_NAME);
	cout << endl;
	showAllItemsMenu(itemName);
}

bool System::showAllItemsMenu(const char* itemName) const
{
	bool itemFound = false;
	/*char nameOfItem[Item::MAX_LEN_NAME];
	cout << "Please enter the name of the item: ";
	cin.getline(nameOfItem, Item::MAX_LEN_NAME);
	cout << endl;*/
	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
	{
		unsigned int counter = m_allSellers[i]->ShowItemsOfSeller(itemName);
		if (counter > 0)
		{
			itemFound = true;
			cout << "The seller name is: " << m_allSellers[i]->getUser().getUserName() << endl;
			cout << "The seller " << m_allSellers[i]->getUser().getUserName() << " has " << counter << " items" << endl;
			cout << "--------------------------------------------------------" << endl << endl;
		}
	}
	if (!itemFound)
	{
		cout << itemName << " was not found :(" << endl;
	}
	return itemFound;
}

void System::headline()
{
	cout << "Welcome to " << m_systemName << " The world advanced shopping platform online\n";
}
void System::menu()
{
		cout << "\nChoose your option:\n"
		<< "(1) Add a buyer\n"
		<< "(2) Add a seller\n"
		<< "(3) Add an item to a seller\n"
		<< "(4) Add a feedback to a seller\n"
		<< "(5) Add an item to Cart of a buyer\n"
		<< "(6) Make an order for a buyer\n"
		<< "(7) Pay for an order of a buyer\n"
		<< "(8) Show details of all buyers\n"
		<< "(9) Show details of all sellers\n"
		<< "(10) Show details of all the products of a certain name\n"
		<< "(11) Exit\n";
}

void System::menuOptions()
{
	bool exitMenu = false;
	int option;
	Buyer* buyer;
	Seller* seller;

	headline();
	while (!exitMenu)
	{
		menu();
		cout << "Enter your option: ";
		cin >> option;
		cout << endl;
		cin.ignore();
		switch (option)
		{
		case 1:
			buyer = readBuyer();
			addBuyerToSystem(buyer);
			break;
		case 2:
			seller = readSeller();
			addSellerToSystem(seller);
			break;
		case 3:
			addItemToSellerMenu();
			break;
		case 4:
			cout << "a";
			break;
		case 5:
			addItemToCartMenu();
			break;
		case 6:
			cout << '6';
			break;
		case 7:
			cout << '7';
			break;
		case 8:
			showAllBuyers();
			break;
		case 9:
			showAllSellers();
			break;
		case 10:
			char nameOfItem[Item::MAX_LEN_NAME];
			cout << "Please enter the name of the item: ";
			cin.getline(nameOfItem, Item::MAX_LEN_NAME);
			cout << endl;
			showAllItemsMenu(nameOfItem);
			break;
		case 11:
			exitMenu = true;
			cout << "Thank you for shopping " << m_systemName << "! :)";
			break;
		}
	}
}

void System::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void System::showAllBuyers() const
{
	cout << "There are " << m_logicSizeBuyers << " buyers in the system:" << endl;
	for (unsigned int i = 0; i < m_logicSizeBuyers; i++)
	{
		cout << "#" << i + 1 << ": "
			<< "User name: " << m_allBuyers[i]->getUser().getUserName() << endl
			<< "Country: " << m_allBuyers[i]->getUser().getAddress().getCountry()
			<< ", City: " << m_allBuyers[i]->getUser().getAddress().getCity()
			<< ", Street: " << m_allBuyers[i]->getUser().getAddress().getStreet()
			<< ", Building Number: " << m_allBuyers[i]->getUser().getAddress().getBuildNo()
			<< ", Apartment Number: " << m_allBuyers[i]->getUser().getAddress().getApartmentNo()
			<< ", Zip Code: " << m_allBuyers[i]->getUser().getAddress().getZipCode() << endl;
	}
}

void System::showAllSellers() const
{
	cout << "There are " << m_logicSizeSellers << " sellers in the system:" << endl;
	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
	{
		cout << "#" << i + 1 << ": "
			<< "User name: " << m_allSellers[i]->getUser().getUserName() << endl
			<< "Country: " << m_allSellers[i]->getUser().getAddress().getCountry()
			<< ", City: " << m_allSellers[i]->getUser().getAddress().getCity()
			<< ", Street: " << m_allSellers[i]->getUser().getAddress().getStreet()
			<< ", Building Number: " << m_allSellers[i]->getUser().getAddress().getBuildNo()
			<< ", Apartment Number: " << m_allSellers[i]->getUser().getAddress().getApartmentNo()
			<< ", Zip Code: " << m_allSellers[i]->getUser().getAddress().getZipCode() << endl;
	}
}

void System::addItemToSellerMenu()
{
	cout << "Please enter the name of the seller: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	Seller* seller = findSeller(sellerName);
	if (seller != nullptr)
	{
		Item* item = readItem();
		seller->addItemToSeller(item);
	}
	else
	{
		cout << "Seller was not found in the system" << endl;
	}
}

void System::addItemToCartMenu()
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = findBuyer(buyerName);
	if (buyer != nullptr)
	{
		char nameOfItem[Item::MAX_LEN_NAME];
		cout << "Please enter the name of the item: ";
		cin.getline(nameOfItem, Item::MAX_LEN_NAME);
		cout << endl;
		if (showAllItemsMenu(nameOfItem))
		{
			cout << "Enter the seller name from the list above: ";
			char sellerName[User::MAX_LEN_NAME];
			cin.getline(sellerName, User::MAX_LEN_NAME);
			Seller* seller = findSeller(sellerName);
			if (seller != nullptr)
			{
				unsigned int counter = seller->ShowItemsOfSeller(nameOfItem);
				if (counter > 0)
				{
					cout << "Enter the serial number of the item to add to the Cart" << endl;
					unsigned int serialNumber;
					cin >> serialNumber;
					Item* item = seller->findSerialNumber(serialNumber);
					if (item != nullptr)
					{
						buyer->getCart()->addItemToCart(item);
					}
				}
				else
				{
					cout << "item was not found" << endl;
				}
			}
			else
			{
				cout << "Seller was not found in the system" << endl;
			}
		}
	}
	else
	{
		cout << "Buyer was not found in the system" << endl;
	}

}

void System::makeAnOrderMenu()
{
	int option;
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = findBuyer(buyerName);
	if (buyer != nullptr)
	{
		if (buyer->getCart()->getLogicSizeItems() > 0)
		{
			buyer->getCart()->showCart();
			cout << "Please enter one of the options: " << endl
				<< "1: Add all items from cart" << endl
				<< "2: Choose item from cart" << endl
				<< "3: Remove item from cart" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}

		}
		else
		{
			cout << "Cart is empty" << endl;
		}
	}
	else
	{
		cout << "Buyer was not found in the system" << endl;
	}
}