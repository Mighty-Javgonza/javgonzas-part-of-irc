#!/usr/bin/expect -f

set COMMANDS_FILE [lindex $argv 0]
set PORT [lindex $argv 1]

spawn nc -c localhost $PORT

set file [open $COMMANDS_FILE r]
while {[gets $file line] != -1} {
    send "$line\r\n"
}

interact
