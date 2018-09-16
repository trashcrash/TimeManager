from datetime import datetime
import os

EVENT_LIST_NAME = 'Time Manager.txt'
LAST_EVENT_TIME_NAME = 'Last Event Time.txt'

def EventInput():
    event_name = raw_input()
    current_time_str = datetime.now().strftime("%m-%d-%Y %H:%M:%S")
    f = open(EVENT_LIST_NAME, 'a')
    f.write(event_name + "  >>  " + current_time_str)
    f.close()
    return current_time_str


def TimeCalc(current_time_str):
    if os.path.isfile(LAST_EVENT_TIME_NAME):
        with open(LAST_EVENT_TIME_NAME) as f:
            last_event_time_str = f.readline()
        current_time = datetime.strptime(current_time_str, "%m-%d-%Y %H:%M:%S")
        last_event_time = datetime.strptime(last_event_time_str, "%m-%d-%Y %H:%M:%S")
        f = open(EVENT_LIST_NAME, 'a')
        f.write("  >>  " + (str(current_time - last_event_time)))
        f.close()
    f = open(EVENT_LIST_NAME, 'a')
    f.write('\n')
    f.close


def LastEventTime(current_time_str):
    f = open(LAST_EVENT_TIME_NAME, 'w')
    f.write(current_time_str)
    f.close

    
if __name__ == '__main__':
    current_time_str = EventInput()
    TimeCalc(current_time_str)
    LastEventTime(current_time_str)
