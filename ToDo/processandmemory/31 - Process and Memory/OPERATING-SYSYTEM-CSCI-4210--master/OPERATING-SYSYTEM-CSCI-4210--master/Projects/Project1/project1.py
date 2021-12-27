######
# OS project 1:
# Alseny Sylla, syllaa
#####

import sys
from copy import deepcopy
from collections import deque
import operator


# global variable
n = 4
t_cs = 8
t_slice = 80
rr_add = "END"
rr_back = "END"
rr_front = "BEGINNING"

class Process(object):
    def __init__(self, data):

        # Input file variables
        self.pid = data[0]
        self.arrival_time = int(data[1])
        self.cpu_burst_time = int(data[2])
        self.num_bursts = int(data[3])
        self.io_time = int(data[4])
 
        # Output file variables
        self.wait_times = [0]*int(data[3])
        self.turnaround_times = [0]*int(data[3])
        self.burst_count = 0

        # keep track of the process
        self.time_left = int(data[2])
        self.location = "NONE"
        self.time_saved = int(data[2])
        self.num_preemptions = 0

    # compare each process
    def __cmp__(self, other): 
            if self.time_saved == other.time_saved:
                return cmp(self.pid, other.pid)
            return cmp(self.time_saved, other.time_saved)

    #check io
    def check_io(self):
        if self.time_left == 0 and self.location == "IO":
            return True
        return False

    #check burst
    def check_burst(self):
        if self.time_left == 0:
            return True
        return False
    
    # cpu preemp
    def cpu_preemp(self):
        if self.location == "RUNNING":
            self.time_saved = self.time_left
            self.num_preemptions += 1
            self.change_state("READY")

    #check if process is done
    def finished(self): 
        if self.time_left == 0:
            if self.burst_count == self.num_bursts:
                return True
        elif self.burst_count == self.num_bursts and self.location == "IO" :
            return True
        return False
    
    #change process state
    def change_state(self, location):
        if location == "RUNNING":
            self.time_left = self.time_saved
        if location == "IO":
            #print "99999"
            self.time_left = self.io_time
        if location == "READY":
            self.time_left = 0
        self.location = location

    #mark process as completed
    def mark_finished(self):
        self.location = "DONE"

    #mark burst done
    def mark_burstDone(self):
        if self.location=="IO": #error, change
            self.change_state("READY")
        elif self.location=="RUNNING":
            self.burst_count += 1
            self.time_saved = self.cpu_burst_time
            self.change_state("IO")

    #increment time, switching or not
    def increment_time(self, switch=False):
        if not switch:

            #running state
            if self.location=="RUNNING":
                self.time_left -= 1
                self.time_saved -= 1
                self.turnaround_times[self.burst_count] += 1

            #io state
            if self.location=="IO":
                self.time_left -= 1

            #ready state
            if self.location == "READY":
                self.wait_times[self.burst_count] += 1
                self.turnaround_times[self.burst_count] += 1

        else:
            #running state
            if self.location=="RUNNING":
                self.turnaround_times[self.burst_count] += 1

            #io state
            elif self.location=="IO":
                self.time_left -= 1

            #ready state
            elif self.location=="READY":
                self.wait_times[self.burst_count] += 1
                self.turnaround_times[self.burst_count] += 1

    #resume process in cpu
    def resume(self):
        if self.location=="READY":
            self.time_left = self.time_saved
            self.change_state("RUNNING")
            
# CPU Scheduling
class CpuSchedule(object):

    # constructor
    def __init__(self, file):
        self.processList = []
        self.read_file(file)
        self.reset_stats()
    
    # start cpu scheduling
    def start(self, out_file):
        out_file = open(out_file, "w")

        #FCFS
        self.reset_stats()
        working_pids = self.fcfs()
        out_file.write("Algorithm FCFS\n")
        out_file.write(self.print_summary(working_pids))
        print

        #SRT
        self.reset_stats()
        working_pids = self.srt()
        out_file.write("\nAlgorithm SRT\n")
        out_file.write(self.print_summary(working_pids))
        print
        
        #RR
        self.reset_stats()
        working_pids = self.rr()
        out_file.write("\nAlgorithm RR\n")
        out_file.write(self.print_summary(working_pids))

        out_file.close()

    # reset stats
    def reset_stats(self):
        self.t = 0 # time
        self.num_context_switches = 0 # cs
        self.running_process = None # critical section
        self.slice_left = 0 # slice count

    # read and parsing input file
    def read_file(self, file):
        input_file = open(file, 'r')

        for line in input_file:
            if line[0]=='#':
                continue
            line = line.strip().split('|')
            if len(line)==1 and line[0]=='':
                continue
            if len(line)!=5:
                print 'ERROR: Invalid input file format'
                sys.exit(1)
            #print(line)
            self.processList.append(Process(line))

        input_file.close()

    # print output stats
    def print_summary(self, working_pids):
        total_wait = 0
        total_turn = 0
        total_burst_count = 0
        total_preemp = 0
        average_burst = 0

        for pid in working_pids:
            average_burst += (pid.cpu_burst_time * pid.num_bursts)
            total_burst_count += pid.num_bursts
            total_preemp += pid.num_preemptions
            for i in range(len(pid.wait_times)):
                total_wait += pid.wait_times[i]
                total_turn += pid.turnaround_times[i]

        output = ""
        output += "-- average CPU burst time: {:.2f} ms\n".format(float(average_burst)/total_burst_count)
        output += "-- average wait time: {:.2f} ms\n".format(float(total_wait)/total_burst_count)    
        output += "-- average turnaround time: {:.2f} ms\n".format(float(total_turn)/total_burst_count)
        output += "-- total number of context switches: {}\n".format(self.num_context_switches)
        output += "-- total number of preemptions: {}".format(total_preemp)

        return output
    
    # print to terminal
    def print_output(self, queue):

        line = ""
        if len(queue) == 0:
            line += "[Q <empty>]"
        else:
            line += "[Q "
            for pid in queue:
                line += pid.pid
                line += " "

            line = line.strip(" ")
            line += "]"

        return line

    # print progress such as cpu burst and switching to io
    def print_progress(self, working_pids, queue, running_cpu):
        if running_cpu.num_bursts - running_cpu.burst_count - 1 <= 0:
            
            print "time {}ms: Process {} terminated {}" \
                .format(self.t, running_cpu.pid, self.print_output(queue))
        else:
            if running_cpu.num_bursts - (running_cpu.burst_count + 1) == 1:
                print "time {}ms: Process {} completed a CPU burst; {} burst to go {}"\
                    .format(self.t, running_cpu.pid, running_cpu.num_bursts - (running_cpu.burst_count + 1), self.print_output(queue))
            else:
                print "time {}ms: Process {} completed a CPU burst; {} bursts to go {}"\
                    .format(self.t, running_cpu.pid, running_cpu.num_bursts - (running_cpu.burst_count + 1), self.print_output(queue))
            print "time {}ms: Process {} switching out of CPU; will block on I/O until time {}ms {}" \
                .format(self.t, running_cpu.pid, self.t + running_cpu.io_time + t_cs/2, self.print_output(queue))
        self.t = self.context_switch(working_pids, queue, running_cpu, self.t)
        
        #print running_cpu.location # before state, running
        running_cpu.mark_burstDone()

    # iterate and check io pids
    def get_IOlist(self, working_pids):
        IOlist = list()
        #print 23123331

        for pid in working_pids:

            if pid.check_io():
                #print 1392139213921

                IOlist.append(pid)
                pid.mark_burstDone()
            
        return sorted(IOlist, key=operator.attrgetter('pid'))

    # iterate and check arriving pids
    def get_arriving(self, working_pids, t):
        arriving_pids = list()
        for pid in working_pids:
            if pid.arrival_time == t:
                arriving_pids.append(pid)
                pid.change_state("READY")
                #print pid.location

        return sorted(arriving_pids, key=operator.attrgetter('pid'))

    #add pids to queue
    def addQueue(self, queue, pid_list, t, isArrival, sortbytime=False):
        #print "pid {}". format(len(pid_list))
        for pid in pid_list:
            queued = False
            #print pid.pid
            #print len(queue)
            #print "time {}ms:  queue {}"\
                   # .format(t,  self.print_output(queue))
            for waiting_pid in queue:
                
                #print "{} vs {}".format(pid.pid, waiting_pid.pid)
                if pid.pid == waiting_pid.pid: 
                    queued = True
                    #print pid.pid
            if not queued:
                #print len(queue)
                if rr_add==rr_back:
                    queue.append(pid)
                elif rr_add==rr_front:
                    queue.appendleft(pid)

                if sortbytime:
                    queue = deque(sorted(queue))
                
                if isArrival:
                    print "time {}ms: Process {} arrived and added to ready queue {}"\
                        .format(t, pid.pid, self.print_output(queue))
                    #print "test{}".format(len(queue))
                else:
                    #print 22
                    print "time {}ms: Process {} completed I/O; added to ready queue {}" \
                        .format(t, pid.pid, self.print_output(queue))
        return queue

    #context switch
    def context_switch(self, working_pids, queue, running_cpu, t, sortbytime=False):
        queued = list()
        for pid in working_pids:
            if pid is not running_cpu:
                queued.append(pid)
                #print "{}".format(pid.pid)

        for x in range(t_cs/2):

            IOlist = self.get_IOlist(queued)
            self.addQueue(queue, IOlist, t, False, sortbytime)

            arriving_pids = self.get_arriving(queued, t)
            self.addQueue(queue, arriving_pids, t, True, sortbytime)

            for pid in working_pids:
                pid.increment_time(True)
            t += 1
        #print t
        return t

    #fcfs
    def fcfs(self):
        working_pids = deepcopy(self.processList)
        finished = 0
        queue = deque()
        running_cpu = None

        print "time {}ms: Simulator started for FCFS {}"\
            .format(self.t, self.print_output(queue))

        while True:
            if finished == len(working_pids):
                break
            if running_cpu is not None:
                if running_cpu.check_burst():
                    self.print_progress(working_pids, queue, running_cpu)

                    if running_cpu.finished():
                        running_cpu.mark_finished()
                        finished += 1
                        if finished == len(working_pids):
                            break
                    running_cpu = None

            # check if IOs are done and sort
            #print finished
            IOlist = self.get_IOlist(working_pids)
            # if len(IOlist) != 0:
            #     print "io {}".format(len(IOlist))
            queue = self.addQueue(queue, IOlist, self.t, False)

            arriving_pids = self.get_arriving(working_pids, self.t)
            queue = self.addQueue(queue, arriving_pids, self.t, True)
            #print "after queue size {}".format(len(queue))
            
            # print " queue {}" .format(self.print_output(queue))
            # break
            if running_cpu is None:
                if len(queue) > 0:
                    next = queue.popleft()
                    next.resume()
                    self.num_context_switches += 1
                   
                    self.t = self.context_switch(working_pids, queue, next, self.t)
                    print "time {}ms: Process {} started using the CPU {}"\
                        .format(self.t, next.pid, self.print_output(queue))
                    running_cpu = next
                    continue

            #increment time
            for pid in working_pids:
                pid.increment_time()
            self.t += 1
            #break
  
        print "time {}ms: Simulator ended for FCFS".format(self.t)
        return working_pids



    def srt(self):
        working_pids = deepcopy(self.processList)
        finished = 0
        queue = deque()
        running_cpu = None

        print ("time {}ms: Simulator started for SRT {}") \
            .format(self.t, self.print_output(queue))

        while True:
            if finished == len(working_pids):
                break
            if running_cpu is not None:
                if (running_cpu.check_burst()):
                    self.print_progress(working_pids, queue, running_cpu)
                    if running_cpu.finished():
                        #print 2
                        running_cpu.mark_finished()
                        finished += 1
                        if finished == len(working_pids):
                            break
                    running_cpu = None

            IOlist = sorted(self.get_IOlist(working_pids))
            arriving_pids = sorted(self.get_arriving(working_pids, self.t))

            shortestArrival =  None
            shortestIos = None

            if running_cpu is not None:
                temp_short = [running_cpu]
                if len(arriving_pids) > 0:
                    temp_short.append(arriving_pids[0])
                if (len(IOlist)>0):
                    temp_short.append(IOlist[0])

                temp_short_proc = min(temp_short)
                if(temp_short_proc != running_cpu):
                    if(temp_short_proc in arriving_pids):
                        queue = self.addQueue(queue, IOlist, self.t, False, True )
                        print ("time {}ms: Process {} arrived and will preempt {} {}")\
                            .format(self.t, temp_short_proc.pid, running_cpu.pid, self.print_output(queue))
                        shortestArrival = arriving_pids.pop(0)
                    elif (temp_short_proc in IOlist): #error!
                        print ("time {}ms: Process {} completed I/O and will preempt {} {}")\
                            .format(self.t, temp_short_proc.pid, running_cpu.pid, self.print_output(queue))
                        shortestIos= IOlist.pop(0)

            queue = self.addQueue(queue, IOlist, self.t, False, True)
            queue = self.addQueue(queue, arriving_pids, self.t, True, True)
            #print len(queue)

            if(shortestArrival):
                queue.appendleft(shortestArrival)
            if(shortestIos):
                queue.appendleft(shortestIos)


            if running_cpu is not None and len(queue) >0:
                if queue[0] < running_cpu:
                    self.t = self.context_switch(working_pids, queue, running_cpu, self.t, True)
                    next = queue.popleft()
                    #print 3131313
                    #print next.pid
                    next.resume()
                    self.num_context_switches += 1

                    running_cpu.cpu_preemp()
                    queue.append(running_cpu)
                    queue = deque(sorted(queue))
                    self.t = self.context_switch(working_pids, queue, next, self.t, True)
                    running_cpu = None
                    if (next.time_left== next.cpu_burst_time):
                        print ("time {}ms: Process {} started using the CPU {}")\
                            .format(self.t, next.pid, self.print_output(queue))
                    else:
                        print ("time {}ms: Process {} started using the CPU with {}ms remaining {}")\
                            .format(self.t, next.pid, next.time_left, print_output(queue))

                    running_cpu = next
                    continue


            if running_cpu is None:
                #print "len:{}".format(len(queue))
                if(len(queue)>0):
                    next = queue.popleft()
                    next.resume()
                    self.num_context_switches += 1

                    self.t = self.context_switch(working_pids, queue, next, self.t, True) # error!
                    if next.time_left != next.cpu_burst_time:
                        print ("time {}ms: Process {} started using the CPU with {}ms remaining {}")\
                            .format(self.t, next.pid, next.time_left, self.print_output(queue))
                    else:
                        print ("time {}ms: Process {} started using the CPU {}")\
                            .format(self.t, next.pid, self.print_output(queue))

                    running_cpu = next
                    continue

                
            for pid in working_pids:
                pid.increment_time()
            self.t += 1


        print ("time {}ms: Simulator ended for SRT".format(self.t))
        return working_pids


    def rr(self):
        working_pids = deepcopy(self.processList)
        finished = 0
        queue = deque()
        running_cpu = None


        print "time {}ms: Simulator started for RR {}" \
        .format(self.t, self.print_output(queue))


        while True:
            if finished == len(working_pids):
                break
            if running_cpu is not None:
                #print "{}" .format(self.slice_left)
                if running_cpu.check_burst():
                    self.print_progress(working_pids, queue, running_cpu)
                    #print running_cpu.location
                    if running_cpu.finished():
                        #print 2
                        running_cpu.mark_finished()
                        finished += 1
                        if finished == len(working_pids):
                            break
                    running_cpu = None
                    self.slice_left = 0

                elif self.slice_left == t_slice:
                    if len(queue) != 0:
                        print "time {}ms: Time slice expired; process {} preempted with {}ms to go {}"\
                        .format(self.t, running_cpu.pid, running_cpu.time_left, self.print_output(queue))
                        self.t = self.context_switch(working_pids, queue, running_cpu, self.t)

                        next = queue.popleft()
                        next.resume()
                        self.num_context_switches += 1

                        running_cpu.cpu_preemp()
                        queue.append(running_cpu)
                        running_cpu = None

                        self.t = self.context_switch(working_pids, queue, next, self.t)
                        if next.time_left == next.cpu_burst_time:
                            print "time {}ms: Process {} started using the CPU {}"\
                            .format(self.t, next.pid, self.print_output(queue))
                        
                        else:
                             print "time {}ms: Process {} started using the CPU with {}ms remaining {}"\
                            .format(self.t, next.pid, next.time_left, self.print_output(queue))     

                        running_cpu = next
                        self.slice_left = 0

                    else:
                        self.slice_left = 0
                        print "time {}ms: Time slice expired; no preemption because ready queue is empty {}"\
                        .format(self.t, self.print_output(queue))


             # check if IOs are done and sort
            #print finished
            IOlist = self.get_IOlist(working_pids)
            queue = self.addQueue(queue, IOlist, self.t, False)

            arriving_pids = self.get_arriving(working_pids, self.t)
            queue = self.addQueue(queue, arriving_pids, self.t, True)
            #print "after queue size {}".format(len(queue))

            if running_cpu is None:
                if len(queue) > 0:
                    next = queue.popleft()
                    next.resume()
                    self.num_context_switches += 1
                   
                    self.t = self.context_switch(working_pids, queue, next, self.t)

                    if next.time_left == next.cpu_burst_time:
                        print "time {}ms: Process {} started using the CPU {}"\
                        .format(self.t, next.pid, self.print_output(queue))
                        
                    else:
                        print "time {}ms: Process {} started using the CPU with {}ms remaining {}"\
                        .format(self.t, next.pid, next.time_left, self.print_output(queue))     

                    running_cpu = next

                    self.slice_left = 0
                    continue

            #increment time
            for pid in working_pids:
                pid.increment_time()
            self.t += 1
            self.slice_left += 1

        print "time {}ms: Simulator ended for RR".format(self.t)
        return working_pids



if __name__ == '__main__':
    # Check command line arguments.
    if len(sys.argv) != 3 and len(sys.argv) != 4:
        print 'ERROR: Invalid arguments'
        print 'USAGE: ./a.out <input-file> <stats-output-file> [<rr-add>]'
        sys.exit(2)

    if len(sys.argv) == 4:
        if sys.argv[3] !="BEGINNING" and sys.argv[3] != "END":
            print 'ERROR: Invalid arguments'
            print 'USAGE: ./a.out <input-file> <stats-output-file> [<rr-add>]'
            sys.exit(2)
        else:
            rr_add = sys.argv[3]

    file = sys.argv[1]
    cpusch = CpuSchedule(file)
    cpusch.start(sys.argv[2])

    