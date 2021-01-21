//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/  /*Command*/                                                                        /*Interval*/ /*Signal*/
	{"",      "torrent",                                                                          30,          0},
	{"🏠 ",     "df -h \"/home\" | awk ' /[0-9]/ {print $4}'",                                    60,          2},
	{"🧠 ",     "free -h | awk '/^Mem:/ {print $3 \"/\" $2}' | sed 's/i//g'",                     30,          3},
	{"🖥 ",     "mpstat | grep -A 5 \"%idle\" | tail -n 1 | awk -F \" \" '{print 100-$13 \"%\"}'", 30,          4},
	{"🌡 ",     "sensors | awk '/Tctl/ {print $2}' | sed 's/+//'",                                 30,          5},
	{"",      "volume",                                                                           0,           6},
	{"",      "cat /sys/class/net/e*/operstate | sed \"s/up/🌐/;s/down/❌/\"",                    60,          7},
	{"",      " date '+%b %d (%a) %H:%M'",                                                        10,          8},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
