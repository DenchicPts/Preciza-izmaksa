#include "quests.h"






int main() {

	int choice(0);

	cin >> choice;

	switch (choice)
	{
	case 1: MD01(); break;
	case 2: MD02(); break;
	case 3: MD03(); break;
	case 4: MD04(); break;

	default:cout << "Invalid choice" << endl;
		break;
	}



	return 0;
}
