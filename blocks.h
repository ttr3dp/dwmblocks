//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/  /*Command*/                                                                        /*Interval*/ /*Signal*/
	{"",      "torrent",                                                                          30,          0},
	{"",     "df -h --output=avail \"/home\" | tail -n 1",                                       60,          1},
	{"",     "df -h --output=avail \"/media\" | tail -n 1",                                      60,          2},
	{" ",     "free -h | awk '/^Mem:/ {print $3 \"/\" $2}' | sed 's/i//g'",                      30,          3},
	{" ",     "mpstat | awk '/all/ {print 100-$13 \"%\"}'",                                      30,          4},
	{" ",     "sensors | awk '/Tctl/ {print $2}' | sed 's/+//'",                                 30,          5},
	{"",      "volume",                                                                           0,           6},
	{"",      "sed \"s/up//;s/down/❌/\" /sys/class/net/e*/operstate",                           60,          7},
	{"",      " date '+%b %d (%a) %H:%M '",                                                       10,          8},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
