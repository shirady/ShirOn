#include "Interface.h"

Interface::Interface()
{
	System* m_system = nullptr; 
}

Interface::~Interface()
{
	delete m_system;
	//printf("%d\n", _CrtDumpMemoryLeaks());
}

bool Interface::setSystem(const char * systemName)
{
	m_system = new System(systemName);
	return true;
}

void Interface::readNumericValuesOfAddress(int& apartmentNo, int& buildNo) const
{
	cout << "Enter your build number: ";
	cin >> buildNo;

	cout << "Enter your apartment number: ";
	cin >> apartmentNo;
}

const Address Interface::readAddress() const
{
	int apartmentNo, buildNo;

	char country[Address::MAX_LEN_COUNTRY];
	cout << "Enter your country: ";
	cin.getline(country, Address::MAX_LEN_COUNTRY);
	cleanAfterGetLine();

	char city[Address::MAX_LEN_CITY];
	cout << "Enter your city: ";
	cin.getline(city, Address::MAX_LEN_CITY);
	cleanAfterGetLine();

	char street[Address::MAX_LEN_STREET];
	cout << "Enter your street: ";
	cin.getline(street, Address::MAX_LEN_STREET);
	cleanAfterGetLine();

	readNumericValuesOfAddress(apartmentNo, buildNo);

	char zipCode[Address::MAX_LEN_ZIP_CODE];
	cout << "Enter your zip code: ";
	cleanBuffer();
	cin.getline(zipCode, Address::MAX_LEN_ZIP_CODE);
	cleanAfterGetLine();

	return Address(country, city, street, buildNo, apartmentNo, zipCode);
}

void Interface::readSystem()
{
	char systemName[System::MAX_LEN_SYSTEM_NAME];
	cout << "Enter system name: ";
	cin.getline(systemName, System::MAX_LEN_SYSTEM_NAME);
	cleanAfterGetLine();
	setSystem(systemName);
}

Buyer* Interface::readBuyer() const
{
	char userName[User::MAX_LEN_NAME];
	bool fcontinue = true;
	do 
	{
		cout << "Enter your user name: ";
		cin.getline(userName, User::MAX_LEN_NAME);
		cleanAfterGetLine();

		if (m_system->findUser(userName) != nullptr)
			cout << "The user is already exist in the system, please enter again" << endl;
		else
			fcontinue = false;
	} while (fcontinue);

	char password[User::MAX_LEN_PASSWORD];
	cout << "Enter password: ";
	cin.getline(password, User::MAX_LEN_PASSWORD);
	cleanAfterGetLine();
	return new Buyer(userName, password, readAddress());
}

Seller* Interface::readSeller() const
{
	char userName[User::MAX_LEN_NAME];
	bool fcontinue = true;
	do
	{
		cout << "Enter your user name: ";
		cin.getline(userName, User::MAX_LEN_NAME);
		cleanAfterGetLine();

		if (m_system->findUser(userName) != nullptr)
			cout << "The user is already exist in the system, please enter again" << endl;
		else
			fcontinue = false;
	} while (fcontinue);

	char password[User::MAX_LEN_PASSWORD];
	cout << "Enter password: ";
	cin.getline(password, User::MAX_LEN_PASSWORD);
	cleanAfterGetLine();

	return new Seller(userName, password, readAddress());
}

BuyerAndSeller* Interface::readBuyerAndSeller() const
{
	char userName[User::MAX_LEN_NAME];
	bool fcontinue = true;
	do
	{
		cout << "Enter your user name: ";
		cin.getline(userName, User::MAX_LEN_NAME);
		cleanAfterGetLine();

		if (m_system->findUser(userName) != nullptr)
			cout << "The user is already exist in the system, please enter again" << endl;
		else
			fcontinue = false;
	} while (fcontinue);

	char password[User::MAX_LEN_PASSWORD];
	cout << "Enter password: ";
	cin.getline(password, User::MAX_LEN_PASSWORD);
	cleanAfterGetLine();

	return new BuyerAndSeller(userName, password, readAddress());
}

Item* Interface::readItem(const Seller* seller) const
{
	char itemName[Item::MAX_LEN_NAME];
		bool fcontinue = true;
	do
	{
		cout << "Enter The item name: ";
		cin.getline(itemName, Item::MAX_LEN_NAME);
		cleanAfterGetLine();
		if (seller->countItemsOfSeller(itemName) != 0)
		{
			cout << "The item is already exist in the seller " << seller->getUserName() << " please enter again" << endl << endl;
		}
		else
		{
			fcontinue = false;
		}
	} while (fcontinue);

	Item::eCategory categoryOfItem;
	cout << "Choose category: 0 - KIDS, 1- ELECTRONICS, 2 - OFFICE, 3 - CLOTHING: ";
	int numOfCategory;
	cin >> numOfCategory;
	categoryOfItem = (Item::eCategory)(numOfCategory);

	unsigned int priceOfItem;
	cout << "Please enter the price of the product: ";
	cin >> priceOfItem;

	return new Item(itemName, categoryOfItem, priceOfItem, seller);
}

Feedback* Interface::readFeedback(const Buyer* buyer) const
{
	char feedbackText[Feedback::MAX_LEN_FEEDBACK];
	cout << "Enter Your feedback: ";
	cin.getline(feedbackText, Feedback::MAX_LEN_FEEDBACK);
	cleanAfterGetLine();

	return new Feedback(feedbackText, readDate(), buyer);
}

const Date Interface::readDate() const
{
	unsigned int year, month, day;
	cout << "Please enter the date, in the following format:" << endl;

	cout << "year: ";
	cin >> year;

	cout << "month: ";
	cin >> month;

	cout << "day: ";
	cin >> day;

	return Date(year, month, day);
}

void Interface::showAllItemsOption() const
{
	char itemName[Item::MAX_LEN_NAME];
	cout << "Please enter the name of the item: ";
	cin.getline(itemName, Item::MAX_LEN_NAME);
	cleanAfterGetLine();
	cout << endl;
	showAllItemsOfSellers(itemName);
}

void Interface::showAllItemsOfSellers(const char* itemName) const
{
	unsigned int logicSizeOfUsers = m_system->getLogicSizeUsers();
	for (unsigned int i = 0; i < logicSizeOfUsers; i++)
	{
		User** allUsers = m_system->getAllUsers();
		Seller* seller = dynamic_cast<Seller*>(allUsers[i]);
		if (seller != nullptr)
		{
			unsigned int counter = seller->countItemsOfSeller(itemName);
			if (counter > 0)
			{
				showItemsOfSeller(seller, itemName);
				cout << "The seller " << seller->getUserName() << " has " << counter << " items" << endl;
				cout << "--------------------------------------------------------" << endl << endl;
			}
		}
	}
}

void Interface::headline() const
{
	cout << "Welcome to " << m_system->getSystemName() << " The world advanced shopping platform online\n";
}

void Interface::menu() const
{
	cout << "\nChoose your option:\n"
		<< "(1)  Add a buyer\n"
		<< "(2)  Add a seller\n"
		<< "(3)  Add a user that is a buyer and a seller\n"
		<< "(4)  Add an item to a seller\n"
		<< "(5)  Add a feedback to a seller\n"
		<< "(6)  Add an item to cart of a buyer\n"
		<< "(7)  Make an order for a buyer\n"
		<< "(8)  Pay for an order of a buyer\n"
		<< "(9)  Show details of all buyers\n"
		<< "(10) Show details of all sellers\n"
		<< "(11) Show details of all users that are buyers and sellers\n"
		<< "(12) Show details of all users of a certain type\n"
		<< "(13) Show details of all the products of a certain name\n"
		<< "(14) choose operation option\n"
		<< "(15) Exit\n";
}

void Interface::menuOptions() const
{
	bool exitMenu = false;
	int option;
	Buyer* buyer;
	Seller* seller;
	BuyerAndSeller* buyerAndSeller;

	headline();
	while (!exitMenu)
	{
		menu();
		cout << "Enter your option: ";
		cin >> option;
		cout << endl;
		cin.ignore();
		if (cin.fail())
		{
			cout << "Invalid number. Please choose a number between 1-11" << endl;
			cin.clear();
			cleanBuffer();
		}
		else
		{
			switch (option)
			{
			case 1:
				buyer = readBuyer();
				m_system->addUserToSystem(buyer);
				break;
			case 2:
				seller = readSeller();
				m_system->addUserToSystem(seller);
				break;
			case 3:
				buyerAndSeller = readBuyerAndSeller();
				m_system->addUserToSystem(buyerAndSeller);
				break;
			case 4:
				addItemToSellerMenu();
				break;
			case 5:
				addFeedbackToSellerMenu();
				break;
			case 6:
				addItemToCartMenu();
				break;
			case 7:
				makeAnOrderMenu();
				break;
			case 8:
				payOrderMenu();
				break;
			case 9:
				showAllBuyers();
				break;
			case 10:
				showAllSellers();
				break;
			case 11:
				showAllBuyersThatAreSellers();
				break;
			case 12:
				showAllUsersOfCertainType();
				break;
			case 13:
				showAllItemsOfCeratinNameMenu();
				break;
			case 14:
				menuOperatorOptions();
				break;
			case 15:
				exitMenu = true;
				cout << "Thank you for shopping " << m_system->getSystemName() << "! :)";
				break;
			default:
				cout << "Invalid number. Please choose a number between 1-11" << endl;
				cleanBuffer();
				break;
			}
		}
	}
}

void Interface::cleanBuffer() const
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void Interface::showUser(const User& user) const
{
	const Address address = user.getAddress();
	cout << "User name: " << user.getUserName() << endl
		<< "Country: " << address.getCountry()
		<< ", City: " << address.getCity()
		<< ", Street: " << address.getStreet()
		<< ", Building Number: " << address.getBuildNo()
		<< ", Apartment Number: " << address.getApartmentNo()
		<< ", Zip Code: " << address.getZipCode() << endl;
}

void Interface::showItem(const Item* item) const
{
	cout << "Item name: " << item->getNameOfItem()
		<< ", Category: " << category[item->getCategoryOfItem()]
		<< ", Price: " << item->getPriceOfItem()
		<< ", Serial Number: " << item->getSerialNumberOfItem()
		<< ", Seller name: " << item->getSeller()->getUserName() << endl;;
}

void Interface::showOrder(const Order* order) const
{
	unsigned int logicSizeItems = order->getLogicSizeItems();
	const Item** allItemsOfOrder = order->getAllItemsOfOrder();
	cout << "\nThe items in the order are:" << endl;
	for (unsigned int i = 0; i < logicSizeItems; i++)
	{
		if (allItemsOfOrder[i] != nullptr)
			showItem(allItemsOfOrder[i]);
	}
	cout << endl;
}

void Interface::showCart(const Cart* cart) const
{
	unsigned int logicSizeItems = cart->getLogicSizeItems();
	const Item** allItemsOfCart = cart->getAllItemsOfCart();
	for (unsigned int i = 0; i < logicSizeItems; i++)
		if (allItemsOfCart[i] != nullptr)
			showItem(allItemsOfCart[i]);
	cout << endl;
}

void Interface::showItemsOfSeller(const Seller* seller, const char* itemName) const
{
	unsigned int logicSizeItems = seller->getLogicSizeItems();
	Item** allItemsOfSeller = seller->getAllItems();
	for (unsigned int i = 0; i < logicSizeItems; i++)
	{
		if (strcmp(allItemsOfSeller[i]->getNameOfItem(), itemName) == 0)
			showItem(allItemsOfSeller[i]);
	}
}

void Interface::addItemToSellerMenu() const
{
	cout << "Please enter the name of the seller: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(sellerName);
	Seller* seller = dynamic_cast<Seller*>(user); //what if user is nullptr?
	if (seller != nullptr)
	{
		Item* item = readItem(seller);
		seller->addItemToSeller(item);
	}
	else
		cout << "Seller was not found in the system" << endl;
}

void Interface::addItemToCartMenu() const
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (buyer != nullptr)
	{
		char itemName[Item::MAX_LEN_NAME];
		cout << "Please enter the name of the item: ";
		cin.getline(itemName, Item::MAX_LEN_NAME);
		cleanAfterGetLine();
		cout << endl;
		unsigned int counterOfItemsInAllSellers = m_system->countItemsInAllSellers(itemName);

		if (counterOfItemsInAllSellers > 0)
		{
			Seller* seller = nullptr;
			seller = FindSellerByChoise(itemName, counterOfItemsInAllSellers);
			if (seller != nullptr)
				addItemToCartMenuHelper(seller, itemName, buyer);
			else
				cout << "Seller was not found in the system" << endl;
		}
	}
	else
		cout << "Buyer was not found in the system" << endl;
}

Seller* Interface::FindSellerByChoise(const char* itemName, unsigned int counterOfItemsInAllSellers) const
{
	cout << "There are " << counterOfItemsInAllSellers << " items with the name " << itemName << endl;
	cout << "The items are: " << endl;
	showAllItemsOfSellers(itemName);
	cout << "Enter the seller name from the list above: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();

	User* user = m_system->findUser(sellerName);
	return (dynamic_cast<Seller*>(user));
}


void Interface::addItemToCartMenuHelper(const Seller* seller, const char* itemName, Buyer* buyer) const
{
	unsigned int counter = seller->countItemsOfSeller(itemName);

	if (counter > 0)
	{
		showItemsOfSeller(seller, itemName);
		cout << "Enter the serial number of the item to add to the Cart: ";
		unsigned int serialNumber;
		cin >> serialNumber;
		Item* item = seller->findSerialNumber(serialNumber);
		if (item != nullptr)
			buyer->getCart()->addItemToCart(item);
	}
	else
		cout << "item was not found" << endl;
}


void Interface::addFeedbackToSellerMenu() const
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (buyer != nullptr)
		addFeedbackToSellerMenuHelper(buyer);
	else
		cout << "Buyer was not found in the system" << endl;
}

void Interface::addFeedbackToSellerMenuHelper(const Buyer* buyer) const
{
	cout << "Please enter the name of the seller: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(sellerName);
	Seller* seller = dynamic_cast<Seller*>(user);
	if (seller != nullptr)
	{
		if (buyer->checkIfSellerExistsInOrdersHistory(seller))
		{
			Feedback* feedback = readFeedback(buyer);
			seller->addFeedbackToSeller(feedback);
		}
	}
	else
		cout << "Seller was not found in the system" << endl;
}


void Interface::makeAnOrderMenu() const
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (buyer != nullptr)
	{
		Cart* cart = buyer->getCart();
		unsigned int numberOfItemsInCart = cart->getLogicSizeItems();
		if (numberOfItemsInCart > 0)
			chooseOptionForMakeAnOrder(buyer, cart,numberOfItemsInCart);
		else
			cout << "Cart is empty" << endl;
	}
	else
		cout << "Buyer was not found in the system" << endl;
}

void Interface::chooseOptionForMakeAnOrderMenu(const Cart* cart) const
{
	cout << "The items in the cart are:" << endl;
	showCart(cart);
	cout << "\nPlease enter one of the options: " << endl
		<< "(1) Choose all items from cart to the order" << endl
		<< "(2) Choose certain items from cart to the order" << endl
		<< "(3) Remove certain items from order" << endl;
	cout << "Enter your option of order: ";
}


void Interface::chooseOptionForMakeAnOrder(Buyer* buyer, Cart* cart, unsigned int numberOfItemsInCart) const
{
	Order* order = buyer->getCurrentOrder();
	unsigned int option=0, numberOfItemsInOrder = order->getLogicSizeItems();
	chooseOptionForMakeAnOrderMenu(buyer->getCart());
	cin >> option;

	switch (option)
	{
	case 1:
		if (numberOfItemsInOrder < numberOfItemsInCart)
		{
			chooseAllItemsFromCart(buyer);
			showOrder(order);
		}
		else
			cout << "All of the items are in the order" << endl;
		break;
	case 2:
		if (numberOfItemsInOrder > 0)
			showOrder(order);
		chooseCertainItemsFromCart(buyer);
		break;
	case 3:
		if (numberOfItemsInOrder > 0)
		{
			showOrder(order);
			removeItemsFromOrder(buyer);
		}
		else
			cout << "There are no items in the order" << endl;
		break;
	}
}


void Interface::chooseAllItemsFromCart(Buyer* buyer) const
{
	Cart* cart = buyer->getCart();
	Order* order = buyer->getCurrentOrder();
	const Item** allItemsOfCart = cart->getAllItemsOfCart();
	const Item** allItemsOfOrder = order->getAllItemsOfOrder();
	bool itemOfCartIsInOrder = false;
	unsigned int cartLogicSizeItems = cart->getLogicSizeItems();
	unsigned int orderLogicSizeItems = order->getLogicSizeItems();

	for (unsigned int i = 0; i < cartLogicSizeItems; i++)
	{
		for (unsigned int j = 0; j < orderLogicSizeItems && !itemOfCartIsInOrder; j++)
		{
			if (allItemsOfCart[i] == allItemsOfOrder[j])
				itemOfCartIsInOrder = true;
		}
		if ((!itemOfCartIsInOrder) || (orderLogicSizeItems == 0))
			order->addItemToOrder(allItemsOfCart[i]);
		itemOfCartIsInOrder = false; //initialize
	}
}
void Interface::chooseCertainItemsFromCart(Buyer* buyer) const
{
	Cart* cart = buyer->getCart();
	Order* order = buyer->getCurrentOrder();
	unsigned int numberOfItems, serialNumber, cartItemsAmount = cart->getLogicSizeItems();

	cout << "The number of items in the cart is: " << cartItemsAmount << endl;;
	cout << "How many items do you want to add to the order? ";
	cin >> numberOfItems;
	if (numberOfItems <= cartItemsAmount && numberOfItems > 0)
	{
		for (unsigned int i = 0; i < numberOfItems; i++)
		{
			cout << "Enter the " << i + 1 << " serial number of item: ";
			cin >> serialNumber;
			const Item* item = cart->findSerialNumber(serialNumber);
			if (item != nullptr)
				order->addItemToOrder(item);
			else
				cout << "The serial number you entered is not valid" << endl;
		}
	}
	else
		cout << "The number of items you items in the cart is " << cartItemsAmount << " and you entered " << numberOfItems << endl;
}

void Interface::removeItemsFromOrder(Buyer* buyer) const
{
	Order* order = buyer->getCurrentOrder();
	unsigned int numberOfItemsToDel, serialNumber,numberOfItemInOrder = order->getLogicSizeItems();

	cout << "The number of items in the order is: " << numberOfItemInOrder << endl;
	cout << "How many items do you want to remove from the order? ";
	cin >> numberOfItemsToDel;

	if (numberOfItemsToDel <= numberOfItemInOrder && numberOfItemsToDel > 0)
	{
		for (unsigned int i = 0; i < numberOfItemsToDel; i++)
		{
			cout << "Enter the " << i + 1 << " serial number of item : ";
			cin >> serialNumber;
			const Item* item = order->findSerialNumber(serialNumber);
			if (item != nullptr)
			{
				showOrder(order);
				order->removeItemFromOrder(item);
				order->reallocItems();
				if (order->getLogicSizeItems() == 0)
					cout << "The order is empty" << endl;
			}
			else
				cout << "The serial number you entered is not valid" << endl;
		}
	}
	else
		cout << "The number of items you items in the cart is " << numberOfItemInOrder << " and you entered " << numberOfItemsToDel << endl;
}

void Interface::payOrderMenu() const
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(buyerName);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	if (buyer != nullptr)
	{
		Cart* cart = buyer->getCart();
		Order* order = buyer->getCurrentOrder();

		unsigned int numberOfItemsInCart = cart->getLogicSizeItems();
		unsigned int numberOfItemsInOrder = order->getLogicSizeItems();
		if (numberOfItemsInOrder > 0)
		{
			int totalPriceOfOrder = order->getTotalPriceOfOrder();
			cout << "The items in the order are:" << endl;
			showOrder(order);
			cout << "The total price is: " << totalPriceOfOrder << endl;
			payOrderMenuHelper(buyer, cart, order, numberOfItemsInCart, numberOfItemsInOrder, totalPriceOfOrder);
		}
		else
			cout << "There are no items in the order" << endl;
	}
	else
		cout << "Buyer was not found in the system" << endl;
}

void Interface::payOrderMenuHelper(Buyer* buyer,Cart* cart, Order* order, unsigned int numberOfItemsInCart, unsigned int numberOfItemsInOrder, unsigned int totalPriceOfOrder) const
{
	const Item** allItemsOfOrder = order->getAllItemsOfOrder();
	const Item** allItemsOfCart = cart->getAllItemsOfCart();
	unsigned int option = 0;
	cout << "(1) Pay for the order" << endl << "(2) Pay later:"<< endl <<"Choose option: ";
	cin >> option;

	if (option == 1)
	{
		unsigned int amountPayed;
		cout << "Enter the exact amount of money for the order" << endl;
		cin >> amountPayed;
		bool itemFound = false;
		if (amountPayed == totalPriceOfOrder)
		{
			for (unsigned int i = 0; i < numberOfItemsInCart; i++)
			{
				for (unsigned int j = 0; i < numberOfItemsInOrder && !itemFound; j++)
				{
					if (allItemsOfCart[i] == allItemsOfOrder[j])
						itemFound = true;
				}
				if (itemFound)
					cart->removeItemFromCart(allItemsOfCart[i]);
			}
			cart->reallocItems();
			order->closeOrder(totalPriceOfOrder);
			buyer->addOrderToHistory();
			cout << "The order was payed." << endl;
		}
		else
			cout << "You didn't enter the exact amount of money" << endl;
	}
}

void Interface::showAllBuyers() const
{
	unsigned int counter = 0;
	User** allUsers = m_system->getAllUsers();
	unsigned int logicSizeUsers = m_system->getLogicSizeUsers();

	for (unsigned int i = 0; i < logicSizeUsers; i++)
	{
		Buyer* buyer = dynamic_cast<Buyer*>(allUsers[i]);
		if (buyer != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			showUser(*allUsers[i]); //prints the User part of the Buyer
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
		<< "There are " << counter << " buyers in the system" << endl;
}

void Interface::showAllSellers() const
{
	unsigned int counter=0;
	User** allUsers = m_system->getAllUsers();
	unsigned int logicSizeUsers = m_system->getLogicSizeUsers();
	for (unsigned int i = 0; i < logicSizeUsers; i++)
	{
		Seller* seller = dynamic_cast<Seller*>(allUsers[i]);
		if (seller != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			showUser(*allUsers[i]); //prints the User part of the Seller
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
	<< "There are " << counter << " sellers in the system" << endl;
}

void Interface::showAllBuyersThatAreSellers() const
{
	unsigned int counter = 0;
	User** allUsers = m_system->getAllUsers();
	unsigned int logicSizeUsers = m_system->getLogicSizeUsers();
	for (unsigned int i = 0; i < logicSizeUsers; i++)
	{
		BuyerAndSeller* seller = dynamic_cast<BuyerAndSeller*>(allUsers[i]);
		if (seller != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			showUser(*allUsers[i]); //prints the User part of the SellerAndBuyer
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
		<< "There are " << counter << " buyer which are also sellers in the system" << endl;
}

void Interface::showAllUsersOfCertainType() const
{
	unsigned int option;
	cout << "(1) Buyer" << endl << "(2) Seller" << endl << "(3) Buyer that is a Seller" << endl
		<< "Choose type of user: ";
	cin >> option;
	cout << endl;

	if (cin.fail())
	{
		cout << "Invalid number. Please choose a number between 1-3" << endl;
		cin.clear();
		cleanBuffer();
	}
	else
	{
		switch (option)
		{
		case(1):
			showAllBuyers();
			break;
		case(2):
			showAllSellers();
			break;
		case(3):
			showAllBuyersThatAreSellers();
			break;
		default:
			cout << "Invalid number. Please choose a number between 1-3" << endl;
			cleanBuffer();
			break;
		}
	}
}

void Interface::cleanAfterGetLine() const
{
	if (cin.fail())
	{
		cin.clear(); //clean the failbit if cin.getline get more than the maximum 
		cleanBuffer(); //clean the buffer
	}
}

void Interface::showAllItemsOfCeratinNameMenu() const
{
	char itemName[Item::MAX_LEN_NAME];
	cout << "Please enter the name of the item: ";
	cin.getline(itemName, Item::MAX_LEN_NAME);
	cleanAfterGetLine();
	cout << endl;
	
	unsigned int counterOfItemsInAllSellers = m_system->countItemsInAllSellers(itemName);
	if (counterOfItemsInAllSellers > 0)
		showAllItemsOfSellers(itemName);
	else
		cout << itemName << " item was not found" << endl;
}

void Interface::menuOperatorOptions() const
{
	Buyer* buyer;
	Seller* seller;
	unsigned int option;

	cout << "(1) +=: add buyer to system" << endl << "(2) +=: add seller to system" << endl <<
	 "Choose option: ";
	cin >> option;
	cout << endl;

	if (cin.fail())
	{
		cout << "Invalid number. Please choose a number between 1-6" << endl;
		cin.clear();
		cleanBuffer();
	}
	else
	{
		cleanBuffer();
		switch (option)
		{
		case(1):
			buyer = readBuyer();
			*m_system+=buyer;
			break;
		case(2):
			seller = readSeller();
			*m_system += seller;
			break;
		case(3):
			break;
		default:
			cout << "Invalid number. Please choose a number between 1-3" << endl;
			cleanBuffer();
			break;
		}
	}
}