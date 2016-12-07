#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <cstring>
#include "sha256.h"
#include "color.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <ctime>

using namespace std;

static char** my_completion(const char*, int ,int);
char* my_generator(const char*,int);
char * dupstr (char*);
void *xmalloc (int);

char* cmd [] ={ "wifipine", "exit", "help", "show", "kicknick" 
,"msf", "shhh", "ssh", "scan", "lip", "clshist", "setglo"
, "delglo","bash","shutdown", "ptf", "set", "fluxion", "wifite",
 "ptf_no_network", "dedpscr", "payload", "clshist", "logout", " " };


static char** my_completion( const char * text , int start,  int end)
{
    char **matches;

    matches = (char **)NULL;

    if (start == 0)
        matches = rl_completion_matches ((char*)text, &my_generator);
    else
        rl_bind_key('\t',rl_abort);

    return (matches);

}

char* my_generator(const char* text, int state)
{
    static int list_index, len;
    char *name;

    if (!state) {
        list_index = 0;
        len = strlen (text);
    }

    while (name = cmd[list_index]) {
        list_index++;

        if (strncmp (name, text, len) == 0)
            return (dupstr(name));
    }

    /* If no names matched, then return NULL. */
    return ((char *)NULL);

}

char * dupstr (char* s) {
  char *r;

  r = (char*) xmalloc ((strlen (s) + 1));
  strcpy (r, s);
  return (r);
}

void * xmalloc (int size)
{
    void *buf;

    buf = malloc (size);
    if (!buf) {
        fprintf (stderr, "Error: Out of memory. Exiting.'n");
        exit (1);
    }

    return buf;
}

void startup()
{
  Color::Modifier blue(Color::FG_BLUE);
  Color::Modifier red(Color::FG_RED);
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);
 cout<<blue << endl;
 cout<<blue << "                                \n                                            @@@@@@@@   @@@@@@@@@         " << endl;
 cout<<blue << "                             @@@@@@@      @@@@@@@@@@@ @@@@@@@@@@@@             " << endl;
 cout<<blue << "                           @@@@@@@@@@@@  @@@@@@ @@@@@ @@@@@@@@@@@@@  @@@@      " << endl;
 cout<<blue << "  @@@@          @@@@@@@@@@ @@@@@@@@@@@@@ @@@@@@ @@@@  @@@@@%   @@@ @@@@@@@@@   " << endl;
 cout<<blue << "@@@@@@@@@    @@@@@@@@@@@@@ #@@@@@@@@@@@@ @@@@@@      @@@@@@@     @@@@@@@@@@@@@ " << endl;
 cout<<blue << "@@@@@@@@@@   @@@@@@@@@@@@  @@@@@  @@@@@ #&&&&&&&&    @@@@@@@@@@ @@@@@@ @@@@@@@@" << endl;
 cout<<blue << " @@@@@@@@@@   @@@@@@@@@@@@  @@@@@  @@@@@ #&&&&&&&&   @@@@@@@@@@ @@@@@   @@@@@@@" << endl;
 cout<<blue << "  @@@@@@@@@@&  @@@@@@@@@    @@@@&  &&&&&  &&&&&&&&% &&&&&&&&@  &@@@@    @@@@@@@" << endl;
 cout<<blue << "   @@@@  %@&&&  @@@&&&       &&&&&  &&&&    &&&&&&& &&&&      &&&&@     (@@@@# " << endl;
 cout<<blue << "    @@@&   &&&&  &&&&&.      &&&&&  &&&&      %%%% %&&&      &&&&              " << endl;
 cout<<blue << "     &&&&   &&&%  &&%%%%%%%%  %%%%  %%%% /%%   %%% %%%%%%%  %&&& &&&&&&        " << endl;
 cout<<blue << "      &&&&   %%%#  %%%%%%%%#  %%%%  %%%% %%%%%%%%% %%%%%%% %%%%&&&&&&          " << endl;
 cout<<blue << "       %%%%   %%%   %######   ##### #### ########  ##%%%%  %%%%%%%&            " << endl;
 cout<<blue << "        %%%%   ###  #####      #### #### (######             %%%%               " << endl;
 cout<<blue << "         %###  ####  #((((     ((((((((/   (##                                  " << endl;
 cout<<blue << "          ####  #(((  (((( (((( ((((((                                         " << endl;
 cout<<blue << "           ##(( ((((   ((////// (((                                            " << endl;
 cout<<blue << "            ((((((((/   ///////                                               " << endl;
 cout<<blue << "             ((((((//    ///                                                   " << endl;
 cout<<blue << "              ///////                                          " << endl;
 cout<<blue << "               ////                                     " << endl;
 cout<<blue << endl <<endl;
 cout<<def;
 cout<<red << "                   ++++++++++++++++++++++++++++++++++++++++                    " << endl;
 cout<<def << "                    Developed by: Luna ("<<green<<"nao3301"<<def<<" & "<<green<<"lupa"<<def<<")                      " << endl;
 cout<<def << "                    Version: 0.2.1 beta                                        " << endl;
 cout<<red << "                   ++++++++++++++++++++++++++++++++++++++++                    " << endl << endl;
 cout<<def;
}

int main ()
{

	string name;
	string namep;
	string nickp;
	char join='\0';
	string task;
	int bufnr=0;
	string pw;
	string gtarget = "0";
	string target ="0";
	string ginterface = "0";
	string gap = "0";
	string gssid = "0";
	string gport ="0";
	string port ="0";
	string gtest ="0";
	string pay = "0";
	string ap_ip ="0";
	string iprg="0";
	string ghash="0";
	string glist ="passwd_lists/common-passwords.txt";
	string host, hip, hoip;
	string ip;
	string Interface;
	string intaDownp;
	string intaUpp;
	string macchp;
	string listenp;
	int nettest=0;
	int warnung_intafaces=0;
	int nou = 0;
	int iin;
	char *buf;
	string buff;
	string mac1;
	string mac0;
	string cmacp;
	string pwhash = "9c1e7f9a92b0d0088b6425c37fb91eee5aa8787fb815af0b453b0ddc11d036ea";
	string rip;
	int tescou=0;
	int f=0;
	string tesc;
	string ptest ="0";
	time_t now = time(0);
	char date[22];
	strftime(date, 22, "%d.%m.%Y - %H:%M:%S", localtime(&now));


  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);
  Color::Modifier blue(Color::FG_BLUE);

  rl_attempted_completion_function = my_completion;

	struct ifaddrs *ifap, *ifa;
   						 struct sockaddr_in *sa;
    					char *addr;

    					getifaddrs (&ifap);
   					 for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
     				   if (ifa->ifa_addr->sa_family==AF_INET) {
      				      sa = (struct sockaddr_in *) ifa->ifa_addr;
         				  addr = inet_ntoa(sa->sin_addr);
          				 // printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
            			string ita = ifa->ifa_name;
            				if (ita != "lo")
            				{
             			 	  //printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
              			 	 ip = addr;
              			 	 Interface = ita;
              			 	 nettest ++;
           				 	}

        				}
    				}
    				if (nettest >= 2 )
    					warnung_intafaces=1;

    				//cout<<ip<<endl;

    				freeifaddrs(ifap);

    intaDownp = "ifconfig "+Interface+" down";
    intaUpp = "ifconfig "+Interface+" up";
    macchp = "macchanger -r "+Interface;
    cmacp= "python2 mac.py " +Interface;

		startup();

	//cout<<"______________________________________"<<endl;
	//cout<<"|    _                                |"<<endl;
	//cout<<"|   |  \\   __   __|    __    __    __ |"<<endl;
	//cout<<"|   |   ) |__| |  |   |__   |__|  |   |"<<endl;
	//cout<<"|   |_ /  |__  |__|    __|  |__   |__ |"<<endl;
	//cout<<"|_____________________________________|"<<endl<<endl;
	//cout<<"#########################"<<endl;

   ifstream datei("conf/speicher.txt");
   if( !datei ) throw "\033[1;31m[!]\033[0merror while opening file";
   string text;
   datei >> text;
   datei.close();

   ginterface = Interface;

	if (text == "\0")
	{

	cout<<"welcome to DED tool!\nnickname: ";
	cin>>name;
	cout<<"\nhello "<<name<<"!"<<endl;
	//namep= "./comu.out "+name;
	cout<<"confirm your membership: ";
	cin >> pw;
	const char * pwchar = pw.c_str();
	string hash = SHA256(pwchar);

	if (hash == pwhash)
	  cout << "welcome to the party" << endl;
	 else
	 {
	  cout << "nope" << endl;
	  return 1;
	 }

	ofstream file;
	file.open("conf/speicher.txt",ios::app);
	file << name << endl;

	cout<<"user added"<<endl;
	nou=256;
	}
	else if (text !="\0")
	{
		cout<<"welcome back "<<text<<"\n"<<endl;
	}

	if (date[13]==1 && date[14]>2)
		cout<<"good morning "<<endl;
	else
		cout<<"good afternoon "<<endl;
	
	if (date[0]==2&&date[1]==4&&date[3]==1&&date[4]==2)
		cout<<" and Merry Chrismas! "<<endl;
	
	if (date[0]==0&&date[1]==1&&date[3]==0&&date[4]==1)
		cout<<" and a happy new year! "<<endl;
	
	if (date[0]==0&&date[1]==5&&date[3]==1&&date[4]==1)
		cout<<" and a happy Guy Fawkes day! "<<endl;

	const char *cname=namep.c_str();
	const char *cintaDown=intaDownp.c_str();
	const char *cintaUp=intaUpp.c_str();
	const char *cmacch=macchp.c_str();

	if (warnung_intafaces == 1)
	{
		string warnA;
		cout<<"\033[1;31m[!]\033[0mwarning: you are using more than 1 interface at the same time."<<endl;
		cout<<"which one do you want to use?"<<endl;

    					int i=0;
   					 for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
     				   if (ifa->ifa_addr->sa_family==AF_INET) {
      				      sa = (struct sockaddr_in *) ifa->ifa_addr;
         				  addr = inet_ntoa(sa->sin_addr);
          				 // printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
            			string ita = ifa->ifa_name;
            				if (ita != "lo")
            				{
            					i++;
              			 	 cout<<"[";
							 cout<<i;
							 cout<<"] ";
							 cout<<ita<<endl;
           				 	}
        				}
    				}

			freeifaddrs(ifap);

			cin>>iin;

    					 i=0;
   					 for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
     				   if (ifa->ifa_addr->sa_family==AF_INET) {
      				      sa = (struct sockaddr_in *) ifa->ifa_addr;
         				  addr = inet_ntoa(sa->sin_addr);
          				 // printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
            			string ita = ifa->ifa_name;
            				if (ita != "lo")
            				{
            					    if (i==iin)
            					   	 Interface=ita;
           				 	}
        				}
    				}

						nettest=1;
	}

	if (nettest == 1)
	{

	const char *cmac=cmacp.c_str();
	mac1 = system(cmac);	

	cout<<"\033[1;36m[!]\033[0m"<<endl;
	cout<<"\nNinjamode enable..."<<endl;
	system (cintaDown);
	system(cmacch);
	system(cintaUp);

	mac0 = system(cmac);

	cout<<mac0<<"hier"<<endl;
	if (mac1 != mac0)
	{
		cout<<"... done"<<endl;
	}

	}
	if (nettest == 0)
	{
		cout<<"\033[1;31m[!]\033[0mno network connection!\nshopping sucks wihtout a connection"<<endl;
	}
	cout<<"\nhappy hacking"<<endl;
	do {
		 while((buf = readline("\n ~ "))!=NULL) {
        //enable auto-complete
        rl_bind_key('\t',rl_complete);

        if (buf[0]!=0)
            add_history(buf);

		buff = buf;

		ifstream datei("conf/history.txt");
   if( !datei ) throw "\033[1;31m[!]\033[0merror while opening!";
   string hist;
   datei >> hist;
   datei.close();

		ofstream file;
	file.open("conf/history.txt",ios::app);
	file << buff << endl;


		if (buff =="exit"||buff =="exit ")
			bufnr=1;
		else if(buff=="bash"||buff=="bash ")
			bufnr=2;
			else if (buff == "show" ||buff == "show ")
			bufnr=4;
			else if (buff == "help"||buff == "help ")
			bufnr =5;
			else if (buff == "wifipine"|| buff == "wiifipine ")
			bufnr=6;
			else if (buff == "kicknick"||buff == "kicknick ")
			bufnr=7;
			else if (buff == "fluxion"||buff == "fluxion ")
			bufnr=8;
			else if (buff == "map"|| buff=="map ")
			bufnr=9;
			else if (buff == "wifite"|| buff == "wifite ")
			bufnr=10;
			else if (buff == "set"||buff == "set ")
			bufnr=11;
			else if (buff == "ptf"||buff == "ptf ")
			bufnr=12;
			else if (buff == "msf"||buff == "msf")
			bufnr=13;
			else if (buff == "example"||buff == "example ")
			bufnr=14;
			else if (buff == "shutdown"||buff == "shutdown ")
			bufnr=15;
			else if (buff == "shhh"||buff == "shhh ")
			bufnr = 16;
			else if (buff == "")
			bufnr = 17;
			else if (buff =="")
			bufnr = 18;
			else if (buff == "")
			bufnr = 19;
			else if (buff == "setglo"||buff == "setglo ")
			bufnr=20;
			else if (buff == "scan"||buff == "scan ")
			bufnr=21;
			else if (buff == "delglo"||buff == "delglo ")
			bufnr=22;
			else if (buff =="about"||buff == "about ")
			bufnr=23;
			else if (buff == "")
			bufnr=24;
			else if (buff == "payload"||buff == "payload ")
			bufnr = 25;
			else if (buff == "")
			bufnr =26;
			else if (buff == "dedpscr" ||buff == "dedpscr ")
			bufnr =27;
			else if (buff == "lip"||buff == "lip ")
			bufnr =28;
			else if (buff == "ssh"|| buff == "ssh ")
			bufnr=29;
			else if (buff == "clshist"||buff == "clshist ")
			bufnr =30;
			else if (buff =="ptf_no_network"||buff == "ptf_no_network ")
			bufnr = 31;
			else if (buff == "logout"||buff == "logout ")
			bufnr =32;


			else if (buff=="c")
			bufnr=1000;
			else if (buff=="MrRobot")
			bufnr=1500;
			else if (buff == "hack5" || buf== "hak5")
			bufnr=1501;
			else if (buff == "talk")
			bufnr=98;
			else
			bufnr=99;

	switch (bufnr){

		case 1:
	{
		cout<<"\033[1;31m[*]\033[0m hope you made a big loot"<<endl;
		return 1;
		break;
	};
	case 2:
	{
		system("bash");
		break;
	};
			case 4 :
				{
					cout<<"\nmodules:\n\n"<<"fluxion ==> opens fluxion(tool to crack wlan)\n";//[*]
					cout<<"map => maps the wireless networks around you"<<endl;			//make better
					cout<<"scan ==> scans other clients in your network"<<endl;			// 
					cout<<"wifite ==> starts wifite"<<endl;								//[*]
					cout<<"set ==> starts the SEToolkit"<<endl;							//[*]
					cout<<"ptf ==> starts the pentestframework"<<endl;					//[*]
					cout<<"msf ==> starts metasploit"<<endl;								//[*]
					cout<<"kick => kicks everybody out of the network"<<endl;			//create
					cout<<"kicknick ==> kicks one target out of the network"<<endl;			
					cout<<"dedpscr ==> cracks password hash with wordlist (dictionary attack)"<<endl;		// [*]
					cout<<"lip ==> shows your ip adress"<<endl;									
					cout<<"shhh ==> starts a listener (for example for the reverse shell from the rubber ducky!)"<<endl;	
					cout<<"ssh ==> sets ssh-connection to a client"<<endl;
					cout << "logout ==> logout" <<endl;
					break;																							//hst form file?
																													//hist remake (windows?)
				};
			case 5 :
				{
					cout<<"\nhelp:\n\n"<<"use arrowkeys to use history, use tap for auto completion\n"<<"exit => closes Dedsec\nbash => opens bash ( come with exit back to Dedsec )\nshow => shows you the modules";
					cout<<"setglo => you can set globals, which then will be used by the modules"<<endl;		//[*]
					cout<<"delglo => deletes all globals"<<endl;											//[*]
					cout<<"about => about"<<endl;														//[*] 
					//cout<<"connect => connect you to the Dedsec server"<<endl;							// maybe ...
					cout<<"payload=> menu for payloads for the USB rubberducky"<<endl;				//create 
					cout<<"w_modul_nano => write a modul for the wifi pineapple nano"<<endl;			//create
					cout<<"clshist => clear the history"<<endl;											// cls history file ... 
					cout<<"shutdown => do i have to say anything?"<<endl;
					cout<<"c"<<endl;																	//just for us coder! => no exlanation
					break;																				//example, rubber shit, nano shit, turtle shit...
				};
			case 6:
				{
					cout <<"chat is now not avalible, check your connection."<<endl;
					break;
				};
			case 7:
				{
					cout <<"kicknick: "<<endl;

					nickp= "python2 'modules/nick_arp.py' ";

					if (ginterface != "0")
					{
						nickp= nickp+ginterface+" ";

					}
					else
					{
					nickp=nickp+" 0  ";// +var+" ";
					}

					if (gtarget != "0")
					{
						nickp=nickp+gtarget+" ";// +var+" ";

					}
					else
					{
						cout<<"target_ip:"<<endl;
						buf = readline("/kicknick/target~ ");
                    	rl_bind_key('\t',rl_complete);

             			if (buf[0]!=0)
                		 add_history(buf);
     					target = buf;
     					free(buf);
						nickp=nickp+target+" ";
					}

					if (gap != "0")
					{
						nickp=nickp+gap;// +var+" ";

					}
					else
					{
						cout<<"ap_ip: "<<endl;
						buf = readline("/kicknick/ap_ip~ ");
                    	rl_bind_key('\t',rl_complete);

             			if (buf[0]!=0)
                		 add_history(buf);
     					ap_ip = buf;
     					free(buf);
						nickp=nickp+ap_ip+"0 ";
					}
					const char *cnick=nickp.c_str();
					system(cnick);
					break;

				};

			case 8:
				{
					cout<<"fluxion: "<<endl;
					system("/home/nao3301/redteam_kit/fluxion/./fluxion");
					//system("fluxion);
					break;
				};
			case 9:
				{
					cout<<"map: "<<endl;

					nickp= "python2 modules/wlan-scanner.py ";

					if (ginterface != "0")
					{
						nickp= nickp+ginterface+" ";

					}
					else
					{
						cout<<"interface: "<<endl;
					nickp=nickp+" 0  ";// +var+" ";
					}


					const char *cnick=nickp.c_str();
					system(cnick);
					break;
				};
			case 10:
				{
					cout<<"wifite: "<<endl;
					//system("wifite");
					system("python2 /home/nao3301/redteam_kit/wifite/wifite.py");
					break;
				};
		case 11:
		{
					cout<<"SET: "<<endl;
					system("setoolkit");
					break;
		};
		case 12:
		{
			cout<<"PTF: "<<endl;
					system("ptf");
					break;
		};
		case 13:
		{
			cout<<"MSF: "<<endl;
					system("msfconsole");
					break;
		};
			case 14:
				{
					string test="0";
					cout<<"[modulname]"<<endl;
					//needed code
					//use globals?
					if (gport!= "0")
						test=gtest;
					else
						cout<<"[test]: "<<endl;
					buf = readline("/[modulname]/[test]~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				test = buf;
     				free(buf);
     				//ptest="python2 modules/example.py "+test;
     				ptest="./modules/example.out "+test;
					const char *ctest=ptest.c_str();
					system(ctest);
					break;
				};
			case 15:
				{
					cout<<"shutdown: /n..."<<endl;
					system("shutdown now halt");
					break;
				};
			case 16:
				{
					cout<<"listener: "<<endl;
					if (gport!= "0")
					listenp="nc -nvl -p "+gport;
					else
					{
						cout<<"port for the listener:"<<endl;
						buf = readline("/ssh/ip~ ");
                    	rl_bind_key('\t',rl_complete);

             			if (buf[0]!=0)
                		 add_history(buf);
     					port = buf;
     					free(buf);
						listenp="nc -nvl -p "+port;
					}
					const char *clisten=listenp.c_str();
					system(clisten);
					break;
				};
			case 17:
				{
					break;

				};
			case 18:
				{
					break;
				};
			case 19:
				{
					break;
				};
			case 20:
				{
					cout<<"\nset your globals: \nto reset just enter '0'"<<endl;
					cout<<"target: ";
					buf = readline("/global/target~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				gtarget = buf;
     				free(buf);
					cout<<"\ninterface: ";//func
					buf = readline("/global/interface~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				ginterface = buf;
     				free(buf);
					cout<<"\nap_ip: ";
					buf = readline("/global/ap_ip~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				gap = buf;
     				free(buf);
					cout<<"\nport: ";
					buf = readline("/global/port~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				gport = buf;
     				free(buf);

     				cout<<"\nhash: ";
					buf = readline("/global/hash~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				ghash = buf;
     				free(buf);

     				cout<<"\nwordlist: ";
					buf = readline("/global/list~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				glist = buf;
     				free(buf);

     // 				cout<<"\gtest: ";
					// buf = readline("/global/test~ ");		//globals in file?
     //                rl_bind_key('\t',rl_complete);

     //         		if (buf[0]!=0)
     //            	 add_history(buf);
     // 				gtest = buf;
     // 				free(buf);

					cout<<endl;
					break;
				};
			case 21:
				{
					do{
						
						rip = rip+ip[f];
						tesc=ip[f];
						f++;
						if (tesc==".")
							tescou++;

					}while(tescou<=2);
					iprg="nmap -sP "+rip+"0/24";
					const char *scanrg=iprg.c_str();
					system(scanrg);//"nmap -sP 192.168.2.0/24");//user var!
					 break;
				};
			case 22:
				{
					cout<<"\033[1;31m[!]\033[0mdeleting globals..."<<endl;
					gap="0";
					ginterface="0";
					gtarget="0";
					gport="0";
					ghash="0";
					glist ="0";
					cout<<"...done"<<endl;
					break;
				};
			case 23:
				{
					startup();
					break;
				};
			case 24:
				{
					cout<<"connecting..."<<endl;
					cout<<".";
					cout<<".";
					cout<<"."<<endl;
					cout<<" connection failt"<<endl;
					break;
				};
			case 25:
				{
					cout<<"payload"<<endl;
					cout<<endl;
					cout<<"create [C,c] "<<endl;
					cout<<"look at [L,l]"<<endl;
					cin>>pay;

					if (pay == "C" || pay == "c")
					{
						cout<<"create:"<<endl;
					}
					else if (pay == "l" || pay == "L")
					{
						cout<<"look at: "<<endl;
					}
					else
						cout<<"input not valid"<<endl;
					break;
				};
			case 26:
				{
					break;
				};
			case 27:
				{
					cout<<"passwd hash cracker"<<endl;
					cout<<"please mind your characters must not be capital letters"<<endl;
					cout<<"supports: md5, sha1, sha224, sha256, sha384, sha512"<<endl;
					
					nickp= "python2 'modules/sha_python.py' ";

					cout<<"hash-algorithim:"<<endl;
					buf = readline("/dedpscr/algo~ ");
                   	rl_bind_key('\t',rl_complete);

           			if (buf[0]!=0)
	               		add_history(buf);
     				target = buf;
     				free(buf);
					nickp=nickp+target+" ";

					if (ghash != "0")
					{
						nickp=nickp+ghash+" ";// +var+" ";

					}
					else
					{
						cout<<"hash: "<<endl;
						buf = readline("/dedpscr/hash~ ");
                    	rl_bind_key('\t',rl_complete);

             			if (buf[0]!=0)
                		 add_history(buf);
     					ap_ip = buf;
     					free(buf);
						nickp=nickp+ap_ip+" ";
					}

					if (glist != "0")
					{
						nickp=nickp+glist+" ";// +var+" ";

					}
					else
					{
						cout<<"wordlist: "<<endl;
						buf = readline("/dedpscr/list~ ");
                    	rl_bind_key('\t',rl_complete);

             			if (buf[0]!=0)
                		 add_history(buf);
     					ap_ip = buf;
     					free(buf);
						nickp=nickp+ap_ip;
					}
					const char *cnick=nickp.c_str();
					system(cnick);
					break;
				};
			case 28:
				{
					cout<<"\nyour local IP is :"<<endl;
    			cout<<"\t"<<ip<<endl;
    			break;
				};
			case 29:
				{
					cout<<"ssh:"<<endl;
					cout<<"username: "<<endl;
					buf = readline("/ssh/username~ ");
            		rl_bind_key('\t',rl_complete);

              		if (buf[0]!=0)
                  	add_history(buf);
     				host = buf;
     		     	free(buf);
					cout<<"ip: "<<endl;
					buf = readline("/ssh/ip~ ");
                    rl_bind_key('\t',rl_complete);

             		if (buf[0]!=0)
                	 add_history(buf);
     				hip = buf;
     				free(buf);
					hoip="ssh "+host+"@"+hip;
					const char *cssh=hoip.c_str();
					system(cssh);
					break;
				}
			case 30:
				{
						ofstream file;
						file.open("conf/history.txt",fstream::out | fstream::trunc);
						file.clear(); 
					cout<<"\n\033[1;31m[!]\033[0mhistory deleted"<<endl;
					break;
				};
			case 31:
				{
					cout<<"PTF not connected: "<<endl;
					system("ptf --no-network-connection");
					break;
				};
				case 32:
					{
							ofstream file;
							file.open("conf/speicher.txt",fstream::out | fstream::trunc);
							file.clear(); 
						cout<<"\n\033[1;31m[!]\033[0myou are logged out"<<endl;
						return 1;
						break;
					};

			case 98:
				{
					cout<<"talk: "<<endl;
					system( cname);
					break;
				};
			case 1000:
				{
					system("g++ -o Dedsec{,.cpp} -lreadline");
					return 0;
				};
			case 1500:
				{
					cout<<"is the BEST series !!! "<<endl;
					cout<<"\033[1;31mfsociety\033[0m"<<endl;
					break;
				};
				case 1501:
				{
					cout<<"has a great shop! "<<endl;
					cout<<"and youtube channel !"<<endl;
					cout<<"\n °"<<endl;
					cout<<"    °"<<endl;
					cout<<"° ° °"<<endl;
					break;
				};
			default:
			{cout<<"\n\033[1;31m[!]\033[0mcommand not known. need some 'help'?"<<endl;
				 break;
			};
		}
	}

    free(buf);
	}while (1);


	return 0;
}
