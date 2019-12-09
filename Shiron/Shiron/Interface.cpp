#include "Interface.h"

Interface::Interface()
{

}

Interface::~Interface()
{
	if (m_system != nullptr)
		delete m_system;
}

const Address Interface::readAddress()
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

void Interface::readSystem()
{
	char systemName[System::MAX_LEN_SYSTEM_NAME];
	cout << "Enter system name: ";
	cin.getline(systemName, System::MAX_LEN_SYSTEM_NAME);
	setSystem(systemName);
}
bool Interface::setSystem(const char * systemName)
{
	m_system = new System(systemName);
	return true;
}

const User Interface::readUser()
{
	char userName[User::MAX_LEN_NAME];
	bool fcontinue = true;
	do 
	{
		cout << "Enter your user name: ";
		cin.getline(userName, User::MAX_LEN_NAME);

		if (m_system->findBuyer(userName) != nullptr || m_system->findSeller(userName) != nullptr)
			cout << "The user is already exist in the system, please enter again" << endl;
		else
			fcontinue = false;
	} while (fcontinue);

	char password[User::MAX_LEN_PASSWORD];
	cout << "Enter password: ";
	cin.getline(password, User::MAX_LEN_PASSWORD);

	return User(userName, password, readAddress());
}

Buyer* Interface::readBuyer()
{
	return new Buyer(readUser());
}

Seller* Interface::readSeller()
{
	return new Seller(readUser());
}

Item* Interface::readItem(Seller* seller)
{
	char itemName[Item::MAX_LEN_NAME];
	cout << "Enter The item name: ";
	cin.getline(itemName, Item::MAX_LEN_NAME);

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

Feedback* Interface::readFeedback(Buyer* buyer) 
{
	char feedbackText[Feedback::MAX_LEN_FEEDBACK];
	cout << "Enter Your feedback: ";
	cin.getline(feedbackText, Feedback::MAX_LEN_FEEDBACK);

	return new Feedback(feedbackText, readDate(), buyer);
}

const Date Interface::readDate()
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
	cout << endl;
	showAllItemsOfSellers(itemName);
}

void Interface::showAllItemsOfSellers(const char* itemName) const
{
	unsigned int logicSizeOfSellers = m_system->getLogicSizeSellers();
	for (unsigned int i = 0; i < logicSizeOfSellers; i++)
	{
		Seller** allSellers = m_system->getAllSellers();
		Seller* seller = allSellers[i];
		unsigned int counter = seller->countItemsOfSeller(itemName);
		if (counter > 0)
		{
			showItemsOfSeller(seller, itemName);
			cout << "The seller " << seller->getUser().getUserName() << " has " << counter << " items" << endl;
			cout << "--------------------------------------------------------" << endl << endl;
		}
	}
}

void Interface::headline()
{
	cout << "Welcome to " << m_system->getSystemName() << " The world advanced shopping platform online\n";
}
void Interface::menu()
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

void Interface::menuOptions()
{
	bool exitMenu = false;
	char option;
	Buyer* buyer;
	Seller* seller;

	headline();
	while (!exitMenu)
	{
		menu();
		cout << "Enter your option: ";
		cin >> option;
		//if (cin.fail())
		//	cout << "Error! bye" << endl;
		cout << endl;
		cin.ignore();
		switch (option)
		{
		case 1:
			buyer = readBuyer();
			m_system->addBuyerToSystem(buyer);
			break;
		case 2:
			seller = readSeller();
			m_system->addSellerToSystem(seller);
			break;
		case 3:
			addItemToSellerMenu();
			break;
		case 4:
			addFeedbackToSellerMenu();
			break;
		case 5:
			addItemToCartMenu();
			break;
		case 6:
			makeAnOrderMenu();
			break;
		case 7:
			payOrderMenu();
			break;
		case 8:
			showAllBuyers();
			break;
		case 9:
			showAllSellers();
			break;
		case 10:
			char itemName[Item::MAX_LEN_NAME];
			cout << "Please enter the name of the item: ";
			cin.getline(itemName, Item::MAX_LEN_NAME);
			cout << endl;
			showAllItemsOfSellers(itemName);
			break;
		case 11:
			exitMenu = true;
			cout << "Thank you for shopping " << m_system->getSystemName() << "! :)";
			break;
		default:
			cout << "Invalid number. Please choose a number between 1-11" << endl;
			//cin.ignore();
			//std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cleanBuffer();
			break;
		}
	}
}

void Interface::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}


void Interface::showUser(User& user) const
{
	Address address = user.getAddress();
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
		<< ", Seller name: " << item->getSeller()->getUser().getUserName() << endl;;
}

void Interface::showOrder(Order* order) const
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

void Interface::showCart(Cart* cart) const
{
	unsigned int logicSizeItems = cart->getLogicSizeItems();
	const Item** allItemsOfCart = cart->getAllItemsOfCart();
	for (unsigned int i = 0; i < logicSizeItems; i++)
	{
		if (allItemsOfCart[i] != nullptr)
			showItem(allItemsOfCart[i]);
	}
	cout << endl;
}

void Interface::showItemsOfSeller(Seller* seller, const char* itemName) const
{
	unsigned int logicSizeItems = seller->getLogicSizeItems();
	Item** allItemsOfSeller = seller->getAllItems();
	for (unsigned int i = 0; i < logicSizeItems; i++)
	{
		if (strcmp(allItemsOfSeller[i]->getNameOfItem(), itemName) == 0)
			showItem(allItemsOfSeller[i]);
	}
}

void Interface::addItemToSellerMenu()
{
	cout << "Please enter the name of the seller: ";
	char sellerName[User::MAX_LEN_NAME];
	cin.getline(sellerName, User::MAX_LEN_NAME);
	Seller* seller = m_system->findSeller(sellerName);
	if (seller != nullptr)
	{
		Item* item = readItem(seller);
		seller->addItemToSeller(item);
	}
	else
	{
		cout << "Seller was not found in the system" << endl;
	}
}

void Interface::addItemToCartMenu()
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = m_system->findBuyer(buyerName);
	if (buyer != nullptr)
	{
		char itemName[Item::MAX_LEN_NAME];
		cout << "Please enter the name of the item: ";
		cin.getline(itemName, Item::MAX_LEN_NAME);
		cout << endl;

		unsigned int counterOfItemsInAllSellers = m_system->countItemsInAllSellers(itemName);
		if (counterOfItemsInAllSellers > 0)
		{
			cout << "There are " << counterOfItemsInAllSellers << " items with the name " << itemName << endl;
			cout << "The items are: " << endl;
			showAllItemsOfSellers(itemName);
			cout << "Enter the seller name from the list above: ";
			char sellerName[User::MAX_LEN_NAME];
			cin.getline(sellerName, User::MAX_LEN_NAME);
			Seller* seller = m_system->findSeller(sellerName);
			if (seller != nullptr)
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

void Interface::addFeedbackToSellerMenu()
{
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = m_system->findBuyer(buyerName);

	if (buyer != nullptr)
	{
		cout << "Please enter the name of the seller: ";
		char sellerName[User::MAX_LEN_NAME];
		cin.getline(sellerName, User::MAX_LEN_NAME);

		Seller* seller = m_system->findSeller(sellerName);
		if (seller != nullptr)
		{
			if (buyer->checkIfSellerExistsInOrdersHistory(seller))
			{
				Feedback* feedback = readFeedback(buyer); 
				seller->addFeedbackToSeller(feedback);
			}
		}
		else
		{
			cout << "Seller was not found in the system" << endl;
		}
	}
	else
	{
		cout << "Buyer was not found in the system" << endl;
	}
}

void Interface::makeAnOrderMenu()
{
	int option;
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = m_system->findBuyer(buyerName);
	if (buyer != nullptr)
	{
		Cart* cart = buyer->getCart();
		unsigned int numberOfItemsInCart = cart->getLogicSizeItems();
		if (numberOfItemsInCart > 0)
		{
			Order* order = buyer->getCurrentOrder();
			unsigned int numberOfItemsInOrder = order->getLogicSizeItems();
			cout << "The items in the cart are:" << endl;
			showCart(cart);
			cout << "\nPlease enter one of the options: " << endl
				<< "(1) Choose all items from cart to the order" << endl
				<< "(2) Choose certain items from cart to the order" << endl
				<< "(3) Remove certain items from order" << endl;
			cout << "Enter your option of order: ";
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
				{
					showOrder(order);
				}
				chooseCertainItemsFromCart(buyer);
				break;
			case 3:
				if (numberOfItemsInOrder > 0)
				{
					showOrder(order);
					removeItemsFromOrder(buyer);
				}
				else
				{
					cout << "There are no items in the order" << endl;
				}
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
	unsigned int cartItemsAmount = cart->getLogicSizeItems();
	const Item** allItemsOfCart = cart->getAllItemsOfCart();
	unsigned int numberOfItems;
	unsigned int serialNumber;
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
			{
				order->addItemToOrder(item);
			}
			else
			{
				cout << "The serial number you entered is not valid" << endl;
			}
		}
	}
	else
	{
		cout << "The number of items you items in the cart is "
			<< cartItemsAmount << " and you entered "
			<< numberOfItems << ":(" << endl;
	}
}

void Interface::removeItemsFromOrder(Buyer* buyer) const
{
	Order* order = buyer->getCurrentOrder();
	unsigned int numberOfItemInOrder = order->getLogicSizeItems();
	const Item** allItemsOfOrder = order->getAllItemsOfOrder();
	unsigned int numberOfItemsToDel;
	unsigned int serialNumber;

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
				{
					cout << "The order is empty" << endl;
				}
			}
			else
			{
				cout << "The serial number you entered is not valid" << endl;
			}
		}
	}
	else
	{
		cout << "The number of items you items in the cart is "
			<< numberOfItemInOrder << " and you entered "
			<< numberOfItemsToDel << ":(" << endl;
	}
}

void Interface::payOrderMenu()
{
	int option;
	cout << "Please enter the name of the buyer: ";
	char buyerName[User::MAX_LEN_NAME];
	cin.getline(buyerName, User::MAX_LEN_NAME);
	Buyer* buyer = m_system->findBuyer(buyerName);
	if (buyer != nullptr)
	{
		Cart* cart = buyer->getCart();
		Order* order = buyer->getCurrentOrder();
		const Item** allItemsOfOrder = order->getAllItemsOfOrder();
		const Item** allItemsOfCart = cart->getAllItemsOfCart();
		unsigned int numberOfItemsInCart = cart->getLogicSizeItems();
		unsigned int numberOfItemsInOrder = order->getLogicSizeItems();
		if (numberOfItemsInOrder > 0)
		{
			int totalPriceOfOrder = order->getTotalPriceOfOrder();
			cout << "The items in the order are:" << endl;
			showOrder(order);
			cout << "The total price is: " << totalPriceOfOrder << endl;
			cout << "Choose option:" << endl
				<< "1. Pay for the order" << endl
				<< "2. Pay later" << endl;
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
							{
								itemFound = true;
							}
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
				{
					cout << "You didn't enter the exact amount of money" << endl;
				}
			}
		}
		else
		{
			cout << "There are no items in the order" << endl;
		}
	}
	else
	{
		cout << "Buyer was not found in the system" << endl;
	}
}


void Interface::showAllBuyers() const
{
	Buyer** allBuyers = m_system->getAllBuyers();
	unsigned int logicSizeBuyers = m_system->getLogicSizeBuyers();
	cout << "There are " << logicSizeBuyers << " buyers in the system:" << endl;
	for (unsigned int i = 0; i < logicSizeBuyers; i++)
	{
		cout << "#" << i + 1 << ": ";
		showUser(allBuyers[i]->getUser());
	}
}

void Interface::showAllSellers() const
{
	Seller** allSellers = m_system->getAllSellers();
	unsigned int logicSizeSellers = m_system->getLogicSizeSellers();
	cout << "There are " << logicSizeSellers << " sellers in the system:" << endl;
	for (unsigned int i = 0; i < logicSizeSellers; i++)
	{
		cout << "#" << i + 1 << ": ";
		showUser(allSellers[i]->getUser());
	}
}