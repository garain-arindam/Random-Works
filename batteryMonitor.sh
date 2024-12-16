#!/bin/bash 

#set -x # enables debug mode

# HANDEL THE CASE WHEN THE FORM IS CANCELLED

# ask the user for the alert percentage
range=$(zenity --forms --title="Set Battery limits" --add-entry="Minimum charge" --add-entry="Maximum charge")

# checking if user cancelled the form 
if [ $? -ne 0 ] || [ -z "$range" ] 
then 
	exit 0
fi

# min value and max value
min=$(cut -d'|' -f1 <<< "$range" ); 
max=$(cut -d'|' -f2 <<< "$range" ); 

if [ -z "$min" ] || [ -z "$max" ] || [ "$min" -ge "$max" ]; then
    zenity --error --text="Please enter appropriate Minimum and Maximum charge value"
    exit 1
fi

# comparing the limits with the batter percentages

#checking if the battery files exits
battery_capacity_file=/sys/class/power_supply/BAT0/capacity
charging_status_file=/sys/class/power_supply/BAT0/subsystem/AC/online
if [ ! -f "$battery_capacity_file" ] || [ ! -f "$charging_status_file" ]
then
	zenity --error --text="BATTERY FILES NOT FOUND!!!"
	exit 1
fi

bat_capacity=$(cat "$battery_capacity_file");
charging=$(cat "$charging_status_file");
while :
do
	bat_capacity=$(cat "$battery_capacity_file");
	charging=$(cat "$charging_status_file");

	if  [ "$bat_capacity" -le "$min" ] && [ "$charging" -eq 0 ]
	then 
		zenity --warning --text="Battery level is below "$min"% connnect charger!!!"
	fi

	if [ "$bat_capacity" -ge "$max" ] && [ "$charging" -eq 1 ]
	then
		zenity --warning --text="Battery level is above  "$max"% remove charger!!!"
	fi
	# checking every 10 sec to avoid cpu wastage 
	sleep 5
done
