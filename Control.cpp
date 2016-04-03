#include "std_lib_facilities.h"
#include "commands.h"

bool user = false;

void initialize()
{
	ifstream file("datalog.txt");

	if (!file.is_open())
	{
		cerr << "Unable to open file" << "\n";
		exit(-1);
	}

	string name, call;

	while (file >> name >> call)
	{
		UCommands.push_back(name);
		UCommands.push_back(call);
	}
}

char opening()
{
	string username = "Anonymous";

	cout << " Hello and Welcome. This is high tech softwre that is ditibuted\n for free and used by anyone. It is not for beginner use and should only\n be used by people who know its intended purpose.\n\tThe software is about to start.\n\tEnter user name to login:\n\t";
	cin >> username;
	if (username == usernames[0]) {
		cout << " Welcome Back " << username << "!\n" << " To view a list of options type \"Opt\"\n\n";
		cout << " Your operating system is required for this to work\n\n";
		char machine;
		cout << " Type \"w\" for Windows and \"l\" for Linux:\n\t";
		cin >> machine;
		return machine;
	}
	else {
		cerr << "Please leave now and you won't get hacked\n";
		user = false;
		return 'b';
	}
}

void ipfind(char innermachine)
{
	if (innermachine == 'w') {
		system("ipconfig");
	}
	else if (innermachine == 'l') {
		system("ifconfig");
	}
}

void track(char innermachine)
{
	if (innermachine == 'w') { //make sure to check the interface
		cout << " Do you want to test the configuration or show output?\n\tType \"test\" to Test config or \"show\" to Show output";
		string typed;
		cin.get();
		getline(cin, typed);
		if (typed == "test") {
			system("snort -i 4 -c C:\Snort\etc\snort.conf -T");
		}
		else if (typed == "show") {
			system("snort -i 4 -c C:\Snort\etc\snort.conf -A console");
		}
		else {
			cerr << " Not an identifier!";
		}
	}
	else if (innermachine == 'l') {
		cout << " Do you want to start tracking or show log?\n\tType \"start\" to Test config or \"log\" to Show output";
		string typed;
		cin.get();
		getline(cin, typed);
		if (typed == "start") {
			system("snort -c /etc/snort/snort.conf -l /var/log/snort/");
		}
		else if (typed == "log") {
			system("cat /var/log/snort/alert");
		}
		else {
			cerr << " Not an identifier!";
		}
	}
}

void encrypt(char innermachine)
{
	if (innermachine == 'w') {
		system("");
	}
	else if (innermachine == 'l') {
		system("");
	}
}

void admin(char innermachine)
{
	if (innermachine == 'w') {
		system("@echo off; CLS; ECHO.; ECHO =============================; ECHO Running Admin shell; ECHO =============================; pause; :checkPrivileges; NET FILE 1>NUL 2>NUL; if '%errorlevel%' == '0' ( goto gotPrivileges ) else ( goto getPrivileges ); :getPrivileges; if '%1'=='ELEV' (echo ELEV & shift /1 & goto gotPrivileges); ECHO.; ECHO **************************************; ECHO Invoking UAC for Privilege Escalation; ECHO **************************************; pause; setlocal DisableDelayedExpansion; set 'batchPath=%~0'; setlocal EnableDelayedExpansion; ECHO Set UAC = CreateObject^('Shell.Application'^) > '%temp%\OEgetPrivileges.vbs'; ECHO args = 'ELEV ' >> '%temp%\OEgetPrivileges.vbs'; ECHO For Each strArg in WScript.Arguments >> '%temp%\OEgetPrivileges.vbs'; ECHO args = args ^& strArg ^& " "  >> '%temp%\OEgetPrivileges.vbs'; ECHO Next >> '%temp%\OEgetPrivileges.vbs'; ECHO UAC.ShellExecute '!batchPath!', args, '', 'runas', 1 >> '%temp%\OEgetPrivileges.vbs'; '%SystemRoot%\System32\WScript.exe' '%temp%\OEgetPrivileges.vbs' %*; exit /B;:gotPrivileges;if '%1'=='ELEV' shift /1; setlocal & pushd .; cd /d %~dp0");
	}
	else if (innermachine == 'l') {
		system("su");
	}
}

void make()
{
	ofstream outfile;
	outfile.open("datalog.txt", ios::app);
	//Check for Error
	if (outfile.fail()) {
		cerr << "Error Opening File" << endl;
	}
	else {
		string un;
		string callcom;
		cout << "\n Enter name of command: \n";
		cin.get();
		getline(cin, un);
		cout << "\n Enter calling command: \n";
		cin.get();
		getline(cin, callcom);
		outfile << un << endl << callcom << endl;
	}
	outfile.close();

	ofstream ofile;
	ofile.open("data.txt", ios::app);
	//Check for Error
	if (ofile.fail()) {
		cerr << "Error Opening File" << endl;
	}
	else {
		string line;
		cout << "Now enter command. To seperate commands use a \";\":" << endl;
		cin.get();
		getline(cin,line);
		ofile << line;
	}
	ofile.close();
}

void view()
{
	ifstream infile;
	infile.open("datalog.txt");
	//Check for Error
	if (infile.fail()) {
		cerr << "Error Opening File" << endl;
	}

	string un, callc, fil;
	int counter = 0;

	string filename = "data.txt";
	ifstream fin(filename.c_str(), ios::in);
	if (!fin.good()) {
		cerr << "Invalid file.\n";
	}
	else {
		string line;
		while (getline(fin, line)) {
			infile >> un >> callc;
			counter++;
			cout << " Command: " << un << " [" << callc << "]: " << line << endl;
		}
	}
	cout << "\n\t" << counter << " items found!\n";
	infile.close();
}

void ucommand(int com) {
	vector<int> oddnum;
	ifstream infile;
	string lineno, line;
	int x, y, y1;
	x = com;
	y = 0.5 * x - 0.5;
	y1 = y + 1;
	for (int lineno = 0; getline(infile, line) && lineno < y1; lineno++)
		if (lineno == y)
			cout << line << endl;
}

void use(char innermachine) {
	auto decider = [innermachine]() {
		while (true) {
			string typed;
			cout << " >  ";
			while (getline(cin, typed)) {
				size_t found = typed.find("ucommand");
				if (typed == "opt") {
					cout << "  Here is a list of commands:" << commands[0] << commands[1] << commands[2] << commands[3] << commands[4] << commands[5] << commands[6] << "\n";
				}
				else if (typed == internalcommands[0]) {
					ipfind(innermachine);
				}
				else if (typed == internalcommands[1]) {
					encrypt(innermachine);
				}
				else if (typed == internalcommands[2]) {
					track(innermachine);
				}
				else if (typed == internalcommands[3]) {
					admin(innermachine);
				}
				else if (typed == internalcommands[4]) {
					make();
				}
				else if (typed == internalcommands[5]) {
					view();
				}
				else if (found != string::npos) {
						for (int i = 1; i < sizeof(UCommands); i += 2) {
							// for loop with sizeof()
							size_t found = typed.find(UCommands[i]);
							if (found != string::npos) {
								cout << i;
								ucommand(i);
							}
							else {
								cout << " It didn't work";
							}
						}
						pos = found + 1;
				}
				else {
					cout << "\tNot recognized as a internal or external command!\n";
				}
				cout << " >  ";
			}
		}
	};
	decider();
}


int main() // this was made, programmed, and executed by @_S1m_C0d322
{
	initialize();
	char innermachine = opening();
	if (innermachine == 'w') {
		use(innermachine);
	}
	else if (innermachine == 'l') {
		use(innermachine);
	}
	else if (user == false){
		return 1;
	}
	else {
		cerr << "\t\t\tWRONG";
	}
}
