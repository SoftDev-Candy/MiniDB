#include"command.h"
#include"storedata.h"

int main()
{

	Record file;
	file.Create_Open_Database();
	file.ReadDatabase();

	DBCommands classobj; 
	classobj.startLoop();

	return 0;

}
