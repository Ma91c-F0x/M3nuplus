#include "std_lib_facilities.h"

const int commandNum = 7;

string commands[commandNum]{ // Each of these are commands spaced down
	"\n\tIpFinder = IP",
	"\n\tLiveEncrypt = ENCRYPT",
	"\n\tTrack Network = TRACK",
	"\n\tADMIN Command Line = ADMIN",
	"\n\tMake a UCommand = MAKE",
	"\n\tView a UCommand = VIEW",
	"\n\tRun a UCommand = UCOMMAND <caller>"

};

string internalcommands[commandNum]{
	"ip",
	"encrypt",
	"track",
	"admin",
	"make",
	"view",
	"ucommand"
};

string usernames[]{
	"<username>" //Put your username here
};

vector<string> UCommands;
