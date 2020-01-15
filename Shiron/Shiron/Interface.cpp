#include "Interface.h"

Interface::Interface()
{
	System* m_system = nullptr; 
}

Interface::~Interface()
{
	delete m_system;
}

bool Interface::setSystem(const char * systemName)
{
	m_system = new System(systemName);
	return true;
}

void Interface::readNumericValuesOfAddress(int& apartmentNo, int& buildNo) const
{
	cout << "Enter build number: ";
	cin >> buildNo;

	cout << "Enter apartment number: ";
	cin >> apartmentNo;
}

const Address Interface::readAddress() const
{
	int apartmentNo, buildNo;

	char country[Address::MAX_LEN_COUNTRY];
	cout << "Enter country: ";
	cin.getline(country, Address::MAX_LEN_COUNTRY);
	cleanAfterGetLine();

	char city[Address::MAX_LEN_CITY];
	cout << "Enter city: ";
	cin.getline(city, Address::MAX_LEN_CITY);
	cleanAfterGetLine();

	char street[Address::MAX_LEN_STREET];
	cout << "Enter street: ";
	cin.getline(street, Address::MAX_LEN_STREET);
	cleanAfterGetLine();

	readNumericValuesOfAddress(apartmentNo, buildNo);

	char zipCode[Address::MAX_LEN_ZIP_CODE];
	cout << "Enter zip code: ";
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

User* Interface::readUserGeneral(eUserType type) const
{
	char userName[User::MAX_LEN_NAME];
	bool fcontinue = true;
	do
	{
		cout << "Enter user name: ";
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

	switch (type)
	{
		case BUYER:
			return new Buyer(userName, password, readAddress());
			break;
		case SELLER:
			return new Seller(userName, password, readAddress());
			break;
		case BUYER_AND_SELLER:
			return new BuyerAndSeller(userName, password, readAddress());
			break;
		default:
			return new Buyer(userName, password, readAddress()); //not supposed to enter to it, its technical only (if the type was not send correctly then it is a Buyer)
	}
}

Item* Interface::readItem(const Seller& seller) const
{
	char itemName[Item::MAX_LEN_NAME];
		bool fcontinue = true;
	do
	{
		cout << "Enter The item name: ";
		cin.getline(itemName, Item::MAX_LEN_NAME);
		cleanAfterGetLine();
		if (seller.countItemsOfSeller(itemName) != 0)
		{
			cout << "The item is already exist in the seller " << seller.getUserName() << " please enter again" << endl << endl;
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

	int priceOfItem;
	cout << "Please enter the price of the product: ";
	cin >> priceOfItem;
	if (priceOfItem < 0)
	{
		cout << "A price lower than 0 is not valid!" << endl;
		return nullptr;
	}
	
	return new Item(itemName, categoryOfItem, priceOfItem, seller);
}

Feedback* Interface::readFeedback(const Buyer& buyer) const
{
	char feedbackText[Feedback::MAX_LEN_FEEDBACK];
	cout << "Enter feedback: ";
	cin.getline(feedbackText, Feedback::MAX_LEN_FEEDBACK);
	cleanAfterGetLine();

	return new Feedback(feedbackText, readDate(), buyer);
}

const Date Interface::readDate() const
{
	int year, month, day;
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
		<< "(14)  Check operations\n"
		<< "(15) Exit\n";
}

void Interface::menuOptions() const
{
	bool exitMenu = false;
	int option;
	User* user;

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
			cout << "Invalid number. Please choose a number between 1-15" << endl;
			cin.clear();
			cleanBuffer();
		}
		else
		{
			switch (option)
			{
			case 1:
				user = readUserGeneral(BUYER);
				m_system->addUserToSystem(user);
				break;
			case 2:
				user = readUserGeneral(SELLER);
				m_system->addUserToSystem(user);
				break;
			case 3:
				user = readUserGeneral(BUYER_AND_SELLER);
				m_system->addUserToSystem(user);
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
				cout << "Invalid number. Please choose a number between 1-15" << endl;
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

void Interface::showItemsOfSeller(const Seller* seller, const char* itemName) const
{
	unsigned int logicSizeItems = seller->getLogicSizeItems();
	Item** allItemsOfSeller = seller->getAllItems();
	for (unsigned int i = 0; i < logicSizeItems; i++)
	{
		if (strcmp(allItemsOfSeller[i]->getNameOfItem(), itemName) == 0)
			cout << *allItemsOfSeller[i];
	}
}

void Interface::addItemToSellerMenu() const
{
	cout << "Please enter the name of the seller: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	User* user = m_system->findUser(sellerName);
	Seller* seller = dynamic_cast<Seller*>(user);
	if (seller != nullptr)
	{
		Item* item = readItem(*seller);
		if (item !=nullptr)
			seller->addItemToSeller(item);
		// if item==nullptr the item will not be created
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
			{
				if (strcmp(seller->getUserName(), buyer->getUserName()) != 0)
					addItemToCartMenuHelper(seller, itemName, buyer);
				else //it is the same user name
					cout << "Seller can't buy from himself" << endl;
			}
			else
				cout << "Seller was not found in the system" << endl;
		}
		else
			cout << itemName << " was not found" << endl;
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
		if (buyer->checkIfSellerExistsInOrdersHistory(*seller))
		{
			const Feedback* feedback = readFeedback(*buyer);
			seller->addFeedbackForSeller(feedback);
			cout << "The feedback was added" << endl;
		}
		else
		{
			cout << "Cannot send feedback, the seller was not in orders' history" << endl;
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
	cout << *cart;
	cout << "\nPlease enter one of the options: " << endl
		<< "(1) Choose all items from cart to the order" << endl
		<< "(2) Choose certain items from cart to the order" << endl
		<< "(3) Remove certain items from order" << endl;
	cout << "Enter your option: ";
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
			cout << endl << "The item in the order are:" << endl;
			cout << *order;
		}
		else
			cout << "All of the items are in the order" << endl;
		break;
	case 2:
		if (numberOfItemsInOrder > 0)
			cout << *order;
		chooseCertainItemsFromCart(buyer);
		break;
	case 3:
		if (numberOfItemsInOrder > 0)
		{
			cout << *order;
			removeItemsFromOrder(buyer);
		}
		else
			cout << "There are no items in the order" << endl;
		break;
	default:
		 cout << "Invalid number. Please choose a number between 1-3" << endl;
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
				cout << *order;
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
			unsigned int totalPriceOfOrder = order->getTotalPriceOfOrder();
			cout << "The items in the order are:" << endl;
			cout << *order;
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

	unsigned int amountPayed;
	cout << "Enter the exact amount of money for the order: ";
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
			buyer->show();
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
			seller->show();
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
		BuyerAndSeller* buyerAndSeller = dynamic_cast<BuyerAndSeller*>(allUsers[i]);
		if (buyerAndSeller != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			buyerAndSeller->show();
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

void Interface::menuOperatorOptionsHeadline() const
{
	cout << "(1) +=: add buyer to system" << endl
		<< "(2) +=: add seller to system" << endl
		<< "(3) >: compare between buyers' carts" << endl
		<< "(4) << show cart's items" << endl
		<< "(5) << show order's items" << endl
		<< "(6) << show seller's feedbacks" << endl
		<< "Choose option: ";
}
void Interface::menuOperatorOptionAddBuyer() const
{
	User* user = readUserGeneral(BUYER);
	Buyer* buyer = dynamic_cast<Buyer*>(user);
	*m_system += buyer;
}

void Interface::menuOperatorOptionAddSeller() const
{
	User* user = readUserGeneral(SELLER);
	Seller* seller = dynamic_cast<Seller*>(user);
	*m_system += seller;
}

void Interface::menuOperatorCompareBuyers() const
{
	char userName[User::MAX_LEN_NAME];
	cout << "Enter The first buyer name: ";
	cin.getline(userName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	Buyer* firstBuyer = dynamic_cast<Buyer*>(m_system->findUser(userName));
	if (firstBuyer == nullptr)
		cout << "The " << userName << " buyer is not exist in the system" << endl;
	else
	{
		cout << "Enter The second buyer name: ";
		cin.getline(userName, User::MAX_LEN_NAME);
		cleanAfterGetLine();
		Buyer* secondBuyer = dynamic_cast<Buyer*>(m_system->findUser(userName));
		if (secondBuyer == nullptr)
			cout << "The buyer " << userName << " is not exist in the system" << endl;
		else
		{
			if (*firstBuyer > *secondBuyer)
				cout << "The Total price of " << firstBuyer->getUserName() << "'s cart is higher than " << secondBuyer->getUserName() << "'s cart" << endl;
			else
				cout << "The Total price of " << firstBuyer->getUserName() << "'s cart is not higher than " << secondBuyer->getUserName() << "'s cart" << endl;
		}
	}
}

void Interface::menuOperatorShowCart() const
{
	char userName[User::MAX_LEN_NAME];
	cout << "Enter The buyer's name: ";
	cin.getline(userName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	Buyer* buyer = dynamic_cast<Buyer*>(m_system->findUser(userName));
	if (buyer == nullptr)
		cout << "Buyer was not found" << endl;
	else
		cout << userName << "'s items in the cart are: " << endl << *(buyer->getCart());
}

void Interface::menuOperatorShowOrder() const
{
	char userName[User::MAX_LEN_NAME];
	cout << "Enter The buyer's name: ";
	cin.getline(userName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	Buyer* buyer = dynamic_cast<Buyer*>(m_system->findUser(userName));
	if (buyer == nullptr)
		cout << "Buyer was not found" << endl;
	else
		cout << userName << "'s items in the current order are: " << *(buyer->getCurrentOrder());
}

void Interface::menuOperatorShowAllFeedbacks() const
{
	char userName[User::MAX_LEN_NAME];
	cout << "Enter The seller's name: ";
	cin.getline(userName, User::MAX_LEN_NAME);
	cleanAfterGetLine();
	Seller* seller = dynamic_cast<Seller*>(m_system->findUser(userName));
	if (seller == nullptr)
		cout << "Seller was not found" << endl;
	else
	{
		seller->showMe();
	}
}

void Interface::menuOperatorOptions() const
{
	menuOperatorOptionsHeadline();
	unsigned int option;
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
			menuOperatorOptionAddBuyer();
			break;
		case(2):
			menuOperatorOptionAddSeller();
			break;
		case(3):
			menuOperatorCompareBuyers();
			break;
		case(4):
			menuOperatorShowCart();
			break;
		case(5):
			menuOperatorShowOrder();
			break;
		case(6):
			menuOperatorShowAllFeedbacks();
			break;
		default:
			cout << "Invalid number. Please choose a number between 1-6" << endl;
			cleanBuffer();
			break;
		}
	}
}