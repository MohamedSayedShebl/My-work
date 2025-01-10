import java.util.*;

public class priorityScheduler {
    public static int[] schedule(List<Process> processes, int contextSwitchTime) {
        List<Process> originalList = new ArrayList<>(processes);
        processes.sort(Comparator.comparingInt(p -> p.arrivalTime)); // Sort by arrival time
        List<Process> readyQueue = new ArrayList<>();
        int currentTime = 0;
        int[] completionTimes = new int[originalList.size()];
        Process previousProcess = null;
        List<String> executionOrder = new ArrayList<>();  // To capture the execution order

        while (!processes.isEmpty() || !readyQueue.isEmpty()) {
            // Add processes to the ready queue
            for (Iterator<Process> it = processes.iterator(); it.hasNext();) {
                Process p = it.next();
                if (p.arrivalTime <= currentTime) {
                    readyQueue.add(p);
                    it.remove();
                }
            }

            if (!readyQueue.isEmpty()) {
                readyQueue.sort(Comparator.comparingInt(p -> p.priority));
                Process current = readyQueue.remove(0);

                // Add context switch time if switching processes
                if (previousProcess != null && previousProcess != current) {
                    currentTime += contextSwitchTime;  // Add context switch time
                }

                currentTime += current.burstTime;
                completionTimes[processIndex(current, originalList)] = currentTime;
                executionOrder.add(current.name);  // Add process to execution order
                previousProcess = current;
            } else {
                currentTime++;
            }
        }

        // Print execution order
        System.out.println("Execution Order: " + String.join(" -> ", executionOrder));
        return completionTimes;
    }

    private static int processIndex(Process process, List<Process> originalList) {
        for (int i = 0; i < originalList.size(); i++) {
            if (originalList.get(i).name.equals(process.name)) {
                return i;
            }
        }
        return -1;
    }
}