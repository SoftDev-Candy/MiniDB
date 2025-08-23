#include"command.h"
#include"storedata.h"

int main()
{

	Record::Create_Open_Database();
	Record::ReadDatabase();

	DBCommands classobj; 
	classobj.startLoop();

	return 0;

}
