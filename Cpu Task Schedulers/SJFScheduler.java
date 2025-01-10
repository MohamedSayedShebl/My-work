import java.util.*;

public class SJFScheduler {
    public static int[] schedule(List<Process> processes) {
        List<Process> originalList = new ArrayList<>(processes); // Keep a copy of the original list
        processes.sort(Comparator.comparingInt(p -> p.arrivalTime)); // Sort by arrival time

        int currentTime = 0;
        int n = processes.size();
        int[] completionTimes = new int[n];
        List<Process> readyQueue = new ArrayList<>();
        List<String> executionOrder = new ArrayList<>(); // To capture the execution order
        int completed = 0;

        while (completed < n) {
            // Add processes that have arrived by the current time to the readyQueue
            for (Iterator<Process> it = processes.iterator(); it.hasNext();) {
                Process p = it.next();
                if (p.arrivalTime <= currentTime && !readyQueue.contains(p)) {
                    readyQueue.add(p);
                }
            }

            // If readyQueue is not empty, select the process with the shortest burst time
            if (!readyQueue.isEmpty()) {
                readyQueue.sort(Comparator.comparingInt(p -> p.burstTime)); // Sort by burst time
                Process currentProcess = readyQueue.remove(0); // Get the process with the shortest burst time

                currentTime = Math.max(currentTime, currentProcess.arrivalTime); // Ensure current time is at least arrival time
                currentTime += currentProcess.burstTime; // Update the current time after process execution

                // Update completion time for this process
                completionTimes[processIndex(currentProcess, originalList)] = currentTime;
                executionOrder.add(currentProcess.name); // Add process to execution order
                processes.remove(currentProcess); // Remove from the list to avoid re-adding
                completed++;
            } else {
                currentTime++; // No processes are ready, increment time
            }
        }

        // Print execution order
        System.out.println("Execution Order: " + String.join(" -> ", executionOrder));
        return completionTimes;
    }

    // Helper method to find the index of the process in the original list
    private static int processIndex(Process process, List<Process> originalList) {
        for (int i = 0; i < originalList.size(); i++) {
            if (originalList.get(i).name.equals(process.name)) {
                return i;
            }
        }
        throw new IllegalArgumentException("Process not found: " + process.name);
    }
}