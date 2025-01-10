import java.util.*;

public class SRTFScheduler {
    public static int[] schedule(List<Process> processes, int contextSwitchTime) {
        // Keep a copy of the original list for index tracking
        List<Process> originalProcesses = new ArrayList<>(processes);

        // Sort by arrival time
        processes.sort(Comparator.comparingInt(p -> p.arrivalTime));

        int currentTime = 0;
        int completed = 0;
        int n = processes.size();
        int[] completionTimes = new int[n];
        PriorityQueue<Process> readyQueue = new PriorityQueue<>(Comparator.comparingInt(p -> p.remainingTime));
        List<String> executionOrder = new ArrayList<>();  // To capture the execution order

        Process previousProcess = null;

        while (completed < n) {
            // Add processes to ready queue that have arrived by current time
            for (Iterator<Process> it = processes.iterator(); it.hasNext();) {
                Process p = it.next();
                if (p.arrivalTime <= currentTime) {
                    readyQueue.add(p);
                    it.remove();  // Only remove from processes once they've arrived and added to the queue
                }
            }

            if (!readyQueue.isEmpty()) {
                Process current = readyQueue.poll();

                // Add context switch time if switching processes
                if (previousProcess != null && previousProcess != current) {
                    currentTime += contextSwitchTime;  // Add context switch time
                }

                // Process current
                currentTime += current.remainingTime;
                current.remainingTime = 0;

                completionTimes[processIndex(current, originalProcesses)] = currentTime;
                executionOrder.add(current.name);  // Add to execution order
                completed++;

                // Set the current process as the previous process for context switching purposes
                previousProcess = current;
            } else {
                currentTime++;
            }
        }

        // Print execution order
        System.out.println("Execution Order: " + String.join(" -> ", executionOrder));
        return completionTimes;
    }

    // Process index lookup based on the original list
    private static int processIndex(Process process, List<Process> originalList) {
        for (int i = 0; i < originalList.size(); i++) {
            if (originalList.get(i).name.equals(process.name)) {
                return i;
            }
        }
        throw new IllegalArgumentException("Process not found: " + process.name);
    }
}